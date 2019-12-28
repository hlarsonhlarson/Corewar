#ifndef OPER_H
# define OPER_H

typedef struct	s_player
{
	int	player_id;
	int	live;
}		t_carret;

typedef struct	s_carret
{
	int		movement;
	int		live_last;
	int		live;
	t_player	*player;
}		t_carret;

typedef struct	s_data
{
	int	live;
	int	cycles;
	int	data_iterator;
}		t_data;

int		what_arg(char c);
