NAME = minishell

# *** #
# INC #
# *** #

INCLUDES	=	./includes
LIBFT		=	./global_libft/bin/libft.a

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


SRC += main.c
SRC += ft_free_all.c
SRC += find_path.c
SRC += manip_datas_cmd.c
SRC += manip_one_cmd.c
SRC += prompt.c
SRC += pipen_t.c
SRC += ft_strlen_up.c
SRC += infile.c
SRC += outfile.c
SRC += modif_mat.c
SRC += simple_mat.c
SRC += pipe.c
SRC += pipe_utils.c
SRC += manip_env.c
SRC += here_doc.c
SRC += builtin_functions.c
SRC += cd.c
SRC += echo.c
SRC += env.c
SRC += pwd.c
