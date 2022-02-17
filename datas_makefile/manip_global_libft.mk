global_libft_init:
	@if [ ! -e "./global_libft/bin/libft.a" ]; then \
		printf "\n\t${BLUE_UNDERLINE}Libft :${DEFAULT}\n\n"; \
		make -C ./global_libft; \
	fi

clean_libft:
	@if [ -e "./global_libft/bin/libft.a" ]; then \
		printf "\n\t${BLUE_UNDERLINE}Libft :${DEFAULT}\n\n"; \
		make clean -C ./global_libft; \
	fi

fclean_libft:
	@if [ -e "./global_libft/bin/libft.a" ]; then \
		printf "\n\t${BLUE_UNDERLINE}Libft :${DEFAULT}\n\n"; \
		make fclean -C ./global_libft; \
	fi

re_libft:
	@printf "\n\t${BLUE_UNDERLINE}Libft :${DEFAULT}\n\n"
	@make re -C ./global_libft

add_libft:
	@make add -C ./global_libft
