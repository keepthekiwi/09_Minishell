/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:33:35 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/27 14:24:07 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
int main(void)
{
	char chr1 = 'o';
	char chr2 = '\t';
	printf("--- ft_isprint ------------------\n\n");
	printf("chr 1: %c\now: %d\nor: %d\n\n", chr1, ft_isprint(chr1), isprint(chr1));
	printf("chr 2: %c\now: %d\nor: %d\n\n", chr2, ft_isprint(chr2), isprint(chr2));
}
**/
