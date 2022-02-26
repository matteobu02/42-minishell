# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgoorick <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 16:00:11 by hgoorick          #+#    #+#              #
#    Updated: 2021/09/06 14:01:48 by hgoorick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include datas_makefile/colors.mk

-include datas_makefile/srcs.mk

CFLAGS		=	-Wall -Wextra -Werror -I/Users/$(USER)/.brew/opt/readline/include

all:  global_libft_init creat_dir print ${NAME}

-include datas_makefile/manip_global_libft.mk

${NAME}:    ${OBJS}
	@gcc ${CFLAGS} -lreadline -I ${INCLUDES} ${LIBFT} ${OBJS} -o $@ -L/Users/$(USER)/.brew/opt/readline/lib
	@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]%40s\n" "Compile" ""

${OBJ_DIR}/%.o:${SRC_DIR}/%.c
	@${CC} ${CFLAGS} -g -I ${INCLUDES} -c $< -o $@
	@printf "${START_FIRST}${BLUE}%-30s${DEFAULT}\t\t[${GREEN}%-30s${DEFAULT}]" "minishell" $<
	@sleep ${FAST}

creat_dir:
	@mkdir -p ${OBJ_DIR}

clean:
	@rm -rf ${OBJ_DIR}
	@printf "${RED}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]\n" "Cleaning up object files"

fclean: clean
	@rm -f ${NAME}
	@printf "${RED}%-30s${DEFAULT}\t\t[${GREEN} OK ${DEFAULT}]\n" "Removed ${NAME}"

re: re_libft print fclean  all

run: ${NAME}
	@./${NAME}

print:
	@printf "\n\t${BLUE_UNDERLINE}${NAME} :${DEFAULT}\n\n"

add:
	@bash ./all_bash/add.sh
	@printf "${GREEN}File(s) ok !${DEFAULT}\n\n"

man:
	@bash ./all_bash/makefile_man.sh
