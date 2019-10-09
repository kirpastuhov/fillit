NAME = fillit
SRCS = ./fillit_src/*.c 
OBJS = ./fillit_src/*.o
HEADER = ./fillit_src/fillit.h 
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)
	
$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER) -L. libft/libft.a

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
