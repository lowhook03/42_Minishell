/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:19:30 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/10 23:02:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

extern int	g_last_exit_status;

void	parse_io_here(t_data *data, t_proc_data *proc_data, t_list *token_list)
{
	t_redir	*redir;
	char	*filename;
	char	*limiter;

	if (is_return_case(data, token_list, E_NONE))
		return ;
	filename = make_temp_file(data);
	limiter = get_limiter(token_list);
	if (get_heredoc_input(filename, limiter) == EX_BY_SIGNAL)
	{
		g_last_exit_status = EX_BY_SIGNAL + SIGINT;
		data->syntax_err_flag = E_SIGINT;
		clear_and_free_token_list(token_list);
		return ;
	}
	redir = (t_redir *)ft_calloc(1, sizeof(t_redir));
	redir->type = T_DLESS;
	redir->filename = filename;
	list_append(&proc_data->redir_list, new_node(redir));
	clear_and_free_token_list(token_list);
}
