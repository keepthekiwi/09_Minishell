/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:48:07 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/18 09:13:35 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/**
int main(void)
{
	char chr1 = 'e';
	char chr2 = 'N';
	printf("--- ft_tolower ------------------\n\n");
	printf("chr 1: %c\now: %c\nor: %c\n\n", chr1, ft_tolower(chr1), tolower(chr1));
	printf("chr 2: %c\now: %c\nor: %c\n\n", chr2, ft_tolower(chr2), tolower(chr2));
}
**/
