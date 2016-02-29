##
## Makefile for bomberman in /home/boisso_c/rendu/cpp_bomberman
## 
## Made by Christian Boisson
## Login   <boisso_c@epitech.net>
## 
## Started on  Sun May 24 14:14:04 2015 Christian Boisson
## Last update Sat Jun 13 19:32:54 2015 rousse_3
##

CXX		=		g++
CXXFLAGS	=		-W -Wall -Wextra -I./header/ -I./header/parser -I./LibBomberman_linux_x64/includes

RM		=		rm -f

NAME		=		bomberman

ifdef DEBUG
CXXFLAGS	+=		-g
endif

LDFLAGS		= -LLibBomberman_linux_x64/libs/ -lgdl_gl  -lGLEW  -lrt -lfbxsdk -lSDL2 -lpthread -ldl -lGL

include	sources.mk

OBJ		=		$(SRC:.cpp=.o)

DEPS		=		$(SRC:.cpp=.d)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(DEPS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

%.o:		%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	@$(CXX) $(CXXFLAGS) -MM -o $*.d $<
	@sed -i -e 's|.*:|$*.o:|' $*.d

.PHONY:		all clean fclean re

-include $(DEPS)
