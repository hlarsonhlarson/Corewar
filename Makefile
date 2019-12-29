# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 07:18:31 by ahalmon-          #+#    #+#              #
#    Updated: 2019/11/12 19:08:20 by hlarson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re make all

FILENAMES = add.c \
        aff.c \
        and.c \
        errors.c \
        exit_functions.c \
        fork.c \
        get_args.c \
        get_filenames.c \
        help_main_alg.c \
        help_parser.c \
        insert_next.c \
        iss.c \
        ld.c \
        ldi.c \
        lfork.c \
        live.c \
        lld.c \
        lldi.c \
        main_alg.c \
        move_and_do.c \
        next_proves.c \
        num_args_prove.c \
        or.c \
        overflow_numbers_prove.c \
        parser.c \
        previous_prove.c \
        print_hex.c \
        print_map.c \
        prove_blocks.c \
        prove_duples.c \
        prove_files.c \
        prove_nulls.c \
        prove_num_position.c \
        proves.c \
        range_filenames.c \
        set_movement.c \
        set_timer.c \
        st.c \
        sti.c \
        sub.c \
        temp_main.c \
        what_arg.c \
        xor.c \
        zjmp.c

NAME = corewar

SRCS	=$(addprefix srcs/, $(FILENAMES))
OBJS	=$(addprefix build/, $(FILENAMES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LFLAGS	= -L ./Libft/ -lft -lncurses

all: $(NAME)

$(NAME):$(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS)

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./Libft
	@make clean -C ./Libft

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./Libft
	@rm -f $(NAME)

build:
	@mkdir build/
