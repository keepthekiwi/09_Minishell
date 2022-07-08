/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:14:22 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/18 08:47:03 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/**
int main(void)
{
	char chr1 = 'p';
	char chr2 = '3';
	char chr3 = '?';
	printf("--- ft_isalnum ------------------\n\n");
	printf("chr 1: %c\now: %d\nor: %d\n\n", chr1, ft_isalnum(chr1), isalnum(chr1));
	printf("chr 2: %c\now: %d\nor: %d\n\n", chr2, ft_isalnum(chr2), isalnum(chr2));
	printf("chr 3: %c\now: %d\nor: %d\n\n", chr3, ft_isalnum(chr3), isalnum(chr3));
}
**/
