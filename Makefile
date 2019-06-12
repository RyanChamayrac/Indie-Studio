##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Indie Studio
##

NAME		=	bomberman

PATH_SRCS	=	src/

CFLAGS		+=	-W -Wall -Wextra -Werror -std=gnu++11 -g3

LDFLAGS		+=	-I./include/ -I./include/Irrlicht -no-pie

LDLIBS		+=	-Llib -L/usr/lib64 -L/usr/X11R6/lib

LDLIBS		+=	-lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor -lpthread

SRC		=	main.cpp 	\
			Core.cpp    \
			Menu.cpp	\
			Game.cpp	\
			Event.cpp	\
			Pause.cpp

TEST	=	test.cpp

SRCS		=	$(addprefix $(PATH_SRCS), $(SRC))

SRCS_TEST	=	$(addprefix ., $(TEST))

OBJS		=	$(SRCS:.cpp=.o)

TEST_OBJS	=	$(TEST:.cpp=.o)

%.o : 		%.cpp
		@g++ -c -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'

$(NAME):	$(OBJS)
		@g++ -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
		@printf "[\033[0;36mCore built\033[0m] % 32s\n"

test: $(TEST_OBJS)
	@g++ -o a.out $(TEST_OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	@printf "[\033[0;36mCore built\033[0m] % 32s\n"

all:		$(NAME)

clean:
		@rm -rf $(OBJS)

fclean:		clean
		@rm -rf $(NAME)

re:		fclean all
