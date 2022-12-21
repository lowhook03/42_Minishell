/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:18:30 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/21 15:53:16 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	// fd가 터미널을 참조하는지 확인
	printf("isatty : %d\n", isatty(0));

	// fd가 참조하는 디바이스의 이름 확인
	printf("device : %s\n", ttyname(0));
}