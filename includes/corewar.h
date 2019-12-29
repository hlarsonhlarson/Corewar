/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:02:54 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/12/28 18:25:50 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../Libft/includes/libft.h"
# include <ncurses.h>

# define CHAMP_MAX_SIZE 3
# define PROG_NAME_LENGTH 128
# define MEM_SIZE 4096
# define COMMENT_LENGTH 2048
# define REG_NUMBER 16
# define CYCLES_TO_DIE 1536
# define NBR_LIVE 21
# define CYCLE_DELTA 50
# define MAX_CHECKS 10
# define REG_SIZE 1
# define DIR_SIZE 4
# define IND_SIZE 2
# define IDX_MOD MEM_SIZE/8
# define T_REG 1
# define T_DIR 2
# define T_IND 3

typedef struct			s_parse
{
	size_t				d;
	size_t				dump;
	size_t				live;
	int					last_alive;
	unsigned char		a;
	unsigned char		v;
	unsigned char		*map;
	unsigned char		*color;
	t_list				*carret;
	int					check;
	int					print_movement;
}						t_parse;

typedef struct			s_carret
{
	size_t				number;
	char				*name;
	char				*comment;
	int					*reg;
	int					dead;
	char				op;
	int					id;
	int					pos;
	size_t				timer;
	int					movement;
	int					live;
	int					carry;
	int					live_last;
	int					champion_exec_code_size;
}						t_carret;

void					error_out(char *error_message);
void					error_out_free_lst(char *error_message, t_list *lst);
void					all_is_proves(t_list *lst);
void					prove_arguments(t_list *arguments);
void					num_args_prove(t_list *arguments);
int						iss(char *str, char *original, size_t len);
int						is_dot_cor(char *str);
int						ft_isdigits(char *str);
void					next_proves(t_list *arguments);
void					overflow_numbers_prove(t_list *lst);
void					previous_num_prove(t_list *lst);
void					prove_n_num_duples(t_list *args);
void					prove_blocks_cors(t_list *lst);
t_list					*ranges(t_list *lst);
t_list					*sames(t_list *lst);
t_list					*range_filenames(t_list *args);
void					parser(t_list *args, t_parse *flags);
void					prove_files(t_list *files);
void					prove_num_position(t_list *args);
void					prove_nulls(t_list *lst);
int						move_and_do(t_carret *carret, \
		size_t i, t_parse *flags);
int						get_dir_one(unsigned char *c, size_t *i);
short					get_dir_two(unsigned char *c, size_t *i);
int						main_alg(t_parse *flags);
void					zjmp(t_carret *carret, unsigned char *c);
void					sti(t_parse *flags, t_carret *carret);
short					get_ind(unsigned char *c, size_t *i);
int						get_arg_for_ind(unsigned char *c, \
		t_carret *carret, size_t *i, int ind);
int						what_arg(char c);
int						get_reg(unsigned char *c, size_t *i);
void					live(t_parse *flags, t_carret *carret, size_t cycle);
void					print_map(unsigned char *c, t_parse *flags, size_t j);
int						init_ncurses(t_parse *flags);
void					op_or(t_parse *flags, t_carret *carret);
void					op_and(t_parse *flags, t_carret *carret);
void					op_xor(t_parse *flags, t_carret *carret);
void					op_add(t_parse *flags, t_carret *carret);
void					op_sub(t_parse *flags, t_carret *carret);
void					ld(t_parse *flags, t_carret *carret);
void					lld(t_parse *flags, t_carret *carret);
void					insert_next(t_carret *carret, t_list *current);
void					op_fork(t_parse *flags, t_carret *carret);
void					set_movement(t_carret *carret, \
		unsigned char c, int num_args, int dir_size);
void					op_lfork(t_parse *flags, t_carret *carret);
void					st(t_parse *flags, t_carret *carret);
void					ldi(t_parse *flags, t_carret *carret);
void					lldi(t_parse *flags, t_carret *carret);
void					aff(t_parse *flags, t_carret *carret);
void					print_byte_reg(int *d);
void					set_timer(t_carret *carret, t_parse *flags);
void					init_main_alg(size_t *i,
		size_t *delta, int *k, int *win);
int						end_main_alg(t_parse *flags, int win);
int						print_winner(t_parse *flags);
void					ft_set_lives(t_list *carret, size_t i, int delta);
void					life_checker(t_parse *flags, int *k,
		size_t i, size_t *delta);
void					print_map_printf(unsigned char *map, t_parse *flags);
char					*print_begin(int index, int champion_exec_code_size, \
		char *name, char *comment);
void					colorizer(unsigned char *color,
		unsigned char paint, size_t size);
t_list					*add_to_print(char *to_print, t_list *old);
void					help_carret_generate(t_carret *carret, size_t index,
		t_parse *flags, t_list *files);
t_list					*carret_generate(t_list *files, t_parse *flags,
		size_t file_num);
void					print_hex_two(unsigned char n);
void					print_hex_four(int n);
void					free_carrets(t_list *carret);
void					free_field(t_parse *flags);

#endif
