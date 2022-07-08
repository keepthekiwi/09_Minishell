/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:36:46 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/18 12:46:35 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/**
int	main(void)
{
	char chr1 = 'b';
	char chr2 = 'A';
	printf("--- ft_toupper ------------------\n\n");
	printf("chr 1: %c\now: %d\nor: %d\n\n", chr1, ft_toupper(chr1), toupper(chr1));
	printf("chr 2: %c\now: %c\nor: %d\n\n", chr2, ft_toupper(chr2), toupper(chr2));
}
**/
