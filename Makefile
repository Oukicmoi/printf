NAME        = libftprintf.a
AR            = ar rcs
CC            = cc 
CFLAGS        = -Werror -Wall -Wextra

PATH_LIBFT = libft
LIBFT = ${PATH_LIBFT}/libft.a

SRCS    =    ft_printf_nb ft_printf_str ft_printf_utils ft_printf \

OBJ_FILES    = $(addsuffix .o, $(SRCS))


all: ${LIBFT} ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

${NAME}: ${OBJ_FILES}
	cp ${LIBFT} ${NAME}
	${AR} $@ $^
	
    

${LIBFT}:
	${MAKE} -C ${PATH_LIBFT}

clean:
	rm -f ${OBJ_FILES} ${OBJ_BFILES}
	${MAKE} -C  ${PATH_LIBFT} clean


fclean: clean
	rm -f ${NAME}
	${MAKE} -C ${PATH_LIBFT} fclean 

re: fclean all

.PHONY: all clean fclean re