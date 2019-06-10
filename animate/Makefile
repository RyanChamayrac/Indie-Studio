##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Indie Studio
##

NAME		=	bomberman

CFLAGS		+=	-W -Wall -Wextra -Werror -std=gnu++11 -g3

LDFLAGS		+=	-I./include/ -I./include/Irrlicht -no-pie

LDLIBS		+=	-Llib -L/usr/lib64 -L/usr/X11R6/lib

LDLIBS		+=	-lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor -lpthread

SRC			=	anim.cpp

OBJS		=	$(SRC:.cpp=.o)

%.o : 		%.cpp
		@g++ -c -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'

$(NAME):	$(OBJS)
		@g++ -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
		@printf "[\033[0;36mCore built\033[0m] % 32s\n"

all:		$(NAME)

clean:
		@rm -rf $(OBJS)

fclean:		clean
		@rm -rf $(NAME)

re:		fclean all