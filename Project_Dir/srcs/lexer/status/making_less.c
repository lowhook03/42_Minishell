/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_less.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:08 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 16:53:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_less(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	(*line)++;
	if (**line == '<')
		*status = MAKING_DLESS;
	else
	{
		create_token(&data->token_lst, buffer_lst, T_LESS);
		*status = BRANCH;
	}
}
