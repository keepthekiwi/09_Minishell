/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:28:47 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/25 11:31:00 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
int	main(void)
{
	char chr1 = 'x';
	char chr2 = '\t';
	char chr3 = 128;
	printf("--- ft_isascii ------------------\n\n");
	printf("chr 1: %c\now: %d\nor: %d\n\n", chr1, ft_isascii(chr1), isascii(chr1));
	printf("chr 2: %c\now: %d\nor: %d\n\n", chr2, ft_isascii(chr2), isascii(chr2));
	printf("chr 3: %c\now: %d\nor: %d\n\n", chr3, ft_isascii(chr3), isascii(chr3));
}
**/
