/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:22:58 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/23 19:22:58 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OPERATION_H
#define ASM_OPERATION_H

#include "op.h"

/*typedef struct	s_op
{
	char		*name;
	uint8_t	code;
	uint8_t	args_num;
	uint8_t	chang_carry;
	uint8_t	args_type[3];
	uint8_t	dir_size;
}				t_op;


static t_op		asm_op[16] = {
		{
				.name = "live",
				.code = 0x01,
				.args_num = 1,
				.chang_carry = 0,
				.args_type = {T_DIR, 0, 0},
				.dir_size = 4,
		},
		{
				.name = "lb",
				.code = 0x02,
				.args_num = 2,
				.chang_carry = 1,
				.args_type = {T_DIR | T_IND, T_REG, 0},
				.dir_size = 4,
		},
		{
				.name = "st",
				.code = 0x03,
				.args_num = 2,
				.chang_carry = 0,
				.args_type = {T_REG, T_REG | T_IND, 0},
				.dir_size = 4,
		},
		{
				.name = "add",
				.code = 0x04,
				.args_num = 3,
				.chang_carry = 1,
				.args_type = {T_REG, T_REG, T_REG},
				.dir_size = 4,
		},
		{
				.name = "sub",
				.code = 0x05,
				.args_num = 3,
				.chang_carry = 1,
				.args_type = {T_REG, T_REG, T_REG},
				.dir_size = 4,
		},
		{
				.name = "and",
				.code = 0x06,
				.args_num = 3,
				.chang_carry = 1,
				.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.dir_size = 4,
		},
		{
				.name = "or",
				.code = 0x07,
				.args_num = 3,
				.chang_carry = 1,
				.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.dir_size = 4,
		},
		{
				.name = "xor",
				.code = 0x08,
				.args_num = 3,
				.chang_carry = 1,
				.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.dir_size = 4,
		},
		{
				.name = "zjmp",
				.code = 0x09,
				.args_num = 1,
				.chang_carry = 0,
				.args_type = {T_DIR, 0, 0},
				.dir_size = 2,
		},
		{
				.name = "ldi",
				.code = 0x0A,
				.args_num = 3,
				.chang_carry = 1,
				.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
				.dir_size = 2,
		},
		{
				.name = "sti",
				.code = 0x0B,
				.args_num = 3,
				.chang_carry = 1,
				.args_type = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
				.dir_size = 2,
		},
		{
				.name = "fork",
				.code = 0x0C,
				.args_num = 1,
				.chang_carry = 0,
				.args_type = {T_DIR, 0, 0},
				.dir_size = 2,
		},
		{
				.name = "lld",
				.code = 0x0D,
				.args_num = 2,
				.chang_carry = 1,
				.args_type = {T_DIR | T_IND, T_REG, 0},
				.dir_size = 4,
		},
		{
				.name = "lldi",
				.code = 0x0E,
				.args_num = 3,
				.chang_carry = 1,
				.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
				.dir_size = 2,
		},
		{
				.name = "lfork",
				.code = 0x0F,
				.args_num = 1,
				.chang_carry = 0,
				.args_type = {T_DIR, 0, 0},
				.dir_size = 2,
		},
		{
				.name = "aff",
				.code = 0x10,
				.args_num = 1,
				.chang_carry = 1,
				.args_type = {T_REG, 0, 0},
				.dir_size = 4,
		}
};
*/
#endif
