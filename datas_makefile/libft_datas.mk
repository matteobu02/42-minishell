# ***** #
# LIBFT #
# ***** #

NAME			= 	libft.a

# *** #
# INC #
# *** #

INCLUDES	=	../includes/

# *** #
# DIR #
# *** #

OBJ_DIR		=	./objs
SRC_DIR		=	./srcs

# *** #
# OBJ #
# *** #

OBJS	= 	$(addprefix ${OBJ_DIR}/,${SRC:.c=.o})

# *** #
# SRC #
# *** #

SRC += ft_isalpha.c
SRC += find_next_char.c
SRC += ft_matrixlcpy_up.c
SRC += ft_isspace.c
SRC += ft_split_up.c
SRC += ft_isalnum.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_isprint.c
SRC += ft_strdup.c
SRC += ft_toupper.c
SRC += ft_tolower.c
SRC += ft_memmove.c
SRC += ft_strlen.c
SRC += ft_memset.c
SRC += ft_bzero.c
SRC += ft_memcpy.c
SRC += ft_strlcpy.c
SRC += ft_strlcat.c
SRC += ft_strrchr.c
SRC += ft_strchr.c
SRC += ft_atoi.c
SRC += ft_calloc.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_strnstr.c
SRC += ft_strcmp.c
SRC += ft_strncmp.c
SRC += ft_putchar_fd.c
SRC += ft_striteri.c
SRC += ft_itoa.c
SRC += ft_putendl_fd.c
SRC += ft_strjoin.c
SRC += ft_putnbr_fd.c
SRC += ft_strtrim.c
SRC += ft_putstr_fd.c
SRC += ft_substr.c
SRC += ft_split.c
SRC += ft_strmapi.c
SRC += ft_lstadd_back.c
SRC += ft_lstadd_front.c
SRC += ft_lstclear.c
SRC += ft_lstdelone.c
SRC += ft_lstiter.c
SRC += ft_lstlast.c
SRC += ft_lstnew.c
SRC += ft_lstmap.c
SRC += ft_lstsize.c
SRC += get_next_line.c
SRC += ft_matrixlen.c
SRC += ft_split_pipex.c
SRC += ft_lstsize_up.c
SRC += ft_strchr_up.c
SRC += ft_allisspace.c
SRC += ft_strjoin_up.c
SRC += cpy_with_malloc.c
SRC += ft_lstnb.c
