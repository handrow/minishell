/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:28:07 by jiandre           #+#    #+#             */
/*   Updated: 2020/11/26 19:28:32 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void		token_free(void *tk_addr)
{
	const struct s_token *tk = tk_addr;

	free(tk->var);
	free((void *)tk);
}
