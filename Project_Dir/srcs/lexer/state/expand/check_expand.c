/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:53:25 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/08 22:16:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/lexer.h"

void	check_expand(t_state *state, t_asset *asset)
{
	const char	next_input = asset->line[asset->index + 1];
	char		*env_start;

	env_start = &asset->line[asset->index + 1];
	if (next_input == '?')
		*state = QUESTION_MARK_EXPAND;
	else if (get_env_length(env_start) > 0 && !is_limiter(asset->token_list))
		*state = EXPAND;
	else
		*state = ADD_BUF_IN_EXPAND;
}