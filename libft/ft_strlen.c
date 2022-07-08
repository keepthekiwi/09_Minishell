/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 07:42:42 by nhaas             #+#    #+#             */
/*   Updated: 2022/05/11 22:11:17 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
int main()
{
	char str[] = "test  123";
	printf("string: %s\n\now: %d\nor: %d\n", str, ft_strlen(str), strlen(str));
	return (0);
}
**/
