/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:04:52 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/18 08:42:34 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
int main(void)
{
	char chr1 = 'p';
	char chr2 = '3';
	printf("--- ft_isdigit ------------------\n\n");
	printf("chr 1: %c\now: %d\nor: %d\n\n", chr1, ft_isdigit(chr1), isdigit(chr1));
	printf("chr 2: %c\now: %d\nor: %d\n\n", chr2, ft_isdigit(chr2), isdigit(chr2));
}
**/
