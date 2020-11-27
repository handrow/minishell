/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <jiandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:56:17 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/28 01:11:28 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "instructions.h"

void		rdr_free(void *rdr_addr)
{
	struct s_rdr *const rdr = rdr_addr;

	free(rdr->filename);
	free(rdr);
}

void		instruction_free(void *isntr_addr)
{
	struct s_instruction *const instr = isntr_addr;

	if (instr->type == IT_CMD)
		str_arr_free(instr->argv);
	dlst_del(&instr->rdr_list, rdr_free);
	free(instr);
}
