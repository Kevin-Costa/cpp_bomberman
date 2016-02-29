//
// Map.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Thu May 28 15:18:03 2015 Christian Boisson
// Last update Sun Jun 14 23:05:16 2015 rousse_3
//

#include		<stdlib.h>
#include		"Player.hpp"
#include		"Map.hpp"
#include		"Wall.hpp"

Map::Map(int sizeX, int sizeY) : m_sizeX(sizeX), m_sizeY(sizeY)
{
  int			i;
  int			j;
  int			diff;
  Position		tmp;

  std::cout << "Start de la creation de la map" << std::endl;
  m_map = new std::list<Entity *> *[m_sizeX];
  i = 0;
  while (i < m_sizeX)
    {
      m_map[i] = new std::list<Entity *>[m_sizeY];
      ++i;
    }
  tmp.setDirection(BOTTOM);
  diff = 0;
  i = 0;
  while (i < m_sizeX)
    {
      j = 0;
      while (j < m_sizeY)
	{
	  tmp.setX(i);
	  tmp.setY(j);
	  tmp.setZ(0);
	  if (i % 2 == 1 && j % 2 == 1)
	    {
	      m_map[i][j].push_back(new Wall(false));
	      m_map[i][j].front()->setPosition(tmp);
	    }
	  else if (diff <= 0 || (diff < 2 && rand() % 100 / 50))
	    {
	      m_map[i][j].push_back(new Wall(&m_dropTable));
	      m_map[i][j].front()->setPosition(tmp);
	      diff += 1;
	    }
	  else
	    diff -= 2;
	  ++j;
	}
      ++i;
    }
}

// Copier les données de la Map au lieu de récupérer les pointeurs.
Map::Map(const Map &old) : m_sizeX(old.m_sizeX), m_sizeY(old.m_sizeY)
{
  m_map = old.m_map;
}

Map::~Map(void)
{
  int			i;
  int			j;

  i = 0;
  while (i < m_sizeX)
    {
      j = 0;
      while (j < m_sizeX)
	{
	  while (m_map[i][j].size() != 0)
	    {
	      delete m_map[i][j].front();
	      m_map[i][j].pop_front();
	    }
	  j++;
	}
      delete[] m_map[i];
      ++i;
    }
  delete[] m_map;
}

int			Map::getSizeX(void) const
{
  return (m_sizeX);
}

int			Map::getSizeY(void) const
{
  return (m_sizeY);
}

std::list<Entity *>	Map::getEntitysAtPos(int posX, int posY) const
{
  if (posX >= 0 && posX < m_sizeX && posY >= 0 && posY < m_sizeY)
    return (m_map[posX][posY]);
  return (m_map[0][0]);
}

void			Map::addEntityAtPos(int posX, int posY, Entity *toAdd)
{
  if (posX >= 0 && posX < m_sizeX && posY >= 0 && posY < m_sizeY)
    m_map[posX][posY].push_back(toAdd);
}


void			Map::addPlayer(int x, int y, Player *newPlayer)
{
  Position	pos(x, y, 0, BOTTOM);

  deleteEntitys(x, y, 1);
  newPlayer->setPosition(pos);
  m_map[x][y].push_back(newPlayer);  
  m_players.push_back(newPlayer);
}


void			Map::addPlayer(Player *newPlayer)
{
  int			x;
  int			y;
  bool			tryIt = true;
  std::string		playerString(PLAYER_STR);

  while (tryIt)
    {
      x = rand() % m_sizeX;
      y = rand() % m_sizeY;
      if (x % 2 == 1 && y % 2 == 1)
	y = (y + 1) < m_sizeY ? (y + 1) : (y - 1);
      if (!checkForEntity(x, y, 1, playerString))
	{
	  Position	pos(x, y, 0, BOTTOM);
	  deleteEntitys(x, y, 1);
	  newPlayer->setPosition(pos);
	  m_map[x][y].push_back(newPlayer);
	  tryIt = false;
	}
    }
  m_players.push_back(newPlayer);
}

void			Map::update(gdl::Clock &clock, gdl::Input &input)
{
  int			x;
  int			y;

  x = 0;
  while (x < m_sizeX)
    {
      y = 0;
      while (y < m_sizeY)
	{
	  std::list<Entity *>::iterator it = m_map[x][y].begin();
	  while (it != m_map[x][y].end())
	    {
	      (*it)->update(clock, *this, input);
	      ++it;
	    }
	  ++y;
	}
      ++x;
    }
  std::list< std::pair<Entity *, Position> >::iterator	toUp = m_toUpdate.begin();
  while (toUp != m_toUpdate.end())
    {
      moveEntity((*toUp).first, (*toUp).second);
      ++toUp;
    }
  m_toUpdate.erase(m_toUpdate.begin(), m_toUpdate.end());
}

void			Map::draw(gdl::AShader &shader, gdl::Clock &clock)
{
  int			i;
  int			j;
  int			x;
  int			y;

  x = getSizeX();
  y = getSizeY();
  i = 0;
  while (i < x)
    {
      j = 0;
      while (j < y)
	{
	  std::list<Entity *>::iterator it = m_map[i][j].begin();
	  while (it != m_map[i][j].end())
	    {
	      (*it)->draw(shader, clock);
	      ++it;
	    }
	  ++j;
	}
      ++i;
    }
}

bool			Map::checkForEntity(int posX, int posY, int range, const std::string &type) const
{
  int			x;
  int			y;
  int			tmpX;
  int			tmpY;

  x = -range;
  while (x <= range)
    {
      y = -range;
      while (y <= range)
	{
	  tmpX = posX + x;
	  tmpY = posY + y;
	  if ((tmpX >= 0 && tmpX < m_sizeX) && (tmpY >= 0 && tmpY < m_sizeY))
	    {
	      std::list<Entity *>::const_iterator it = m_map[tmpX][tmpY].begin();
	      while (it != m_map[tmpX][tmpY].end())
		{
		  if ((*it)->toString().compare(type) == 0)
		    return (true);
		  ++it;
		}
	    }
	  ++y;
	}
      ++x;
    }
  return (false);
}

void			Map::addToUpdate(Entity *toUpdate, Position oldPos)
{
  std::pair<Entity *, Position>	tmp;

  tmp.first = toUpdate;
  tmp.second = oldPos;
  m_toUpdate.push_back(tmp);
}

void			Map::deleteEntity(Entity *toDelete)
{
  int			posX = toDelete->getPosition().getX();
  int			posY = toDelete->getPosition().getY();

  m_map[posX][posY].remove(toDelete);
}

void			Map::moveEntity(Entity *toMove, Position oldPos)
{
  Position		newPos;

  newPos = toMove->getPosition();
  removeEntityFromPos(toMove, oldPos);
  if (!(newPos.getX() == -1 && newPos.getY() == -1))
    addEntityAtPos(newPos.getX(), newPos.getY(), toMove);
}

void			Map::removeEntityFromPos(Entity *toRemove, Position pos)
{
  if (pos.getX() >= 0 && pos.getX() < m_sizeX && pos.getY() >= 0 && pos.getY() < m_sizeY)
    m_map[pos.getX()][pos.getY()].remove(toRemove);
}

void			Map::dumpScore(void) const
{
  std::list<Player *>::const_iterator it = m_players.begin();

  while (it != m_players.end())
    {
      std::cout << "Player " << (*it)->getID() << " : " << (*it)->getScore();
      if ((*it)->isAlive())
	std::cout << "   *";
      std::cout << std::endl;
      ++it;
    }
}

bool			Map::gameIsEnd(void) const
{
  int			alive = 0;
  std::list<Player *>::const_iterator	it = m_players.begin();

  while (it != m_players.end())
    {
      if ((*it)->isAlive())
	++alive;
      ++it;
    }
  if (alive > 1)
    return (false);
  else
    return (true);
}

void			Map::deleteEntitys(int posX, int posY, int range, bool deletePlayer)
{
  int			x;
  int			y;
  int			tmpX;
  int			tmpY;

  x = -range;
  while (x <= range)
    {
      y = -range;
      while (y <= range)
	{
	  tmpX = posX + x;
	  tmpY = posY + y;
	  if (!(tmpX % 2 == 1 && tmpY % 2 == 1))
	    if ((tmpX >= 0 && tmpX < m_sizeX) && (tmpY >= 0 && tmpY < m_sizeY))
	      {
		std::list<Entity *>::iterator it = m_map[tmpX][tmpY].begin();
		while (it != m_map[tmpX][tmpY].end())
		  {
		    if (((*it)->toString().compare(PLAYER_STR) == 0 && deletePlayer) \
			|| (*it)->toString().compare(PLAYER_STR) != 0)
		      {
			delete (*it);
			m_map[tmpX][tmpY].erase(it++);
		      }
		    else
		      ++it;
		  }
	      }
	  ++y;
	}
      ++x;
    }
}

static int	getNbSquare(int nbPlayer)
{
  int		square = static_cast<int>(std::sqrt(nbPlayer));

  if (square * square >= nbPlayer)
    return (square);
  else
    return (square + 1);
}

bool		Map::placePlayer(int nbPlayer, std::vector<Player*> tab)
{
  int		nbSquare = getNbSquare(nbPlayer);

  if (static_cast<double>(m_sizeX) / nbSquare < 2)
    {
      std::cerr << "Too many player for the map" << std::endl;
      return false;
    }
  int		sizeSquare = m_sizeX / nbSquare;
  int		idx = 0;
  int		x = 0;
  int		y = 0;

  while (nbPlayer > 0)
    {
      int	randX;
      int	randY;
      int	px;
      int	py;

      do
	{
	  randX = rand() % sizeSquare;
	  randY = rand() % sizeSquare;
	  if (idx == 0)
	    {
	      px = x * sizeSquare + randX;
	      py = y * sizeSquare + randY;
	    }
	  else if (idx == 1)
	    {
	      px = m_sizeX - (x + 1) * sizeSquare + randX;
	      py = y * sizeSquare + randY;
	    }
	  else if (idx == 2)
	    {
	      px = x * sizeSquare + randX;
	      py = m_sizeY - (y + 1) * sizeSquare + randY;
	    }
	  else if (idx == 3)
	    {
	      px = m_sizeX - (x + 1) * sizeSquare + randX;
	      py = m_sizeY - (y + 1) * sizeSquare + randY;
	    }
	}
      while (px % 2 == 1 && py % 2 == 1);

      addPlayer(px, py, tab[nbPlayer - 1]);
      idx++;
      nbPlayer--;
      if (idx == 4)
	{
	  idx = 0;
	  x += 1;
	  if (x >= m_sizeX / sizeSquare)
	    {
	      x = 0;
	      y++;
	    }
	}
    }
  return (true);
}
