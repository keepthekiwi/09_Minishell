/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:14:34 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 14:38:43 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	g_error_code = errno;
	if (!pwd)
		return (0);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
