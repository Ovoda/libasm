NAME	= libasm.a

SRCS	= ft_strlen.s 	\
		  ft_strdup.s 	\
		  ft_write.s 	\
		  ft_read.s 	\
		  ft_strcmp.s 	\
		  ft_strcpy.s 	\

OBJS 	= $(SRCS:.s=.o)

%.o: %.s
	nasm -f elf64 $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
