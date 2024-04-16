NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf.c ft_utils.c ft_utils2.c		 

OBJS = $(SRCS:.c=.o)

ARRC = ar rc

RANLIB = ranlib

RM = rm -f


.c.o : $(SRCS)
	${CC} ${CFLAGS} -c -o $@ $^

$(NAME) : $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re