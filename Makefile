NAME	= libasm.a

SRCS	= ft_strlen.s 	\
		  ft_strdup.s 	\
		  ft_write.s 	\
		  ft_read.s 	\
		  ft_strcmp.s 	\
		  ft_strcpy.s 	\

SRCS_BONUS = 	ft_list_size_bonus.s \
				ft_list_push_front_bonus.s	\
		  	# ft_list_remove_if_bonus.s	\

OBJS 	= $(SRCS:.s=.o)
OBJS_BONUS 	= $(SRCS_BONUS:.s=.o)

%.o: %.s
	nasm -f elf64 $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
