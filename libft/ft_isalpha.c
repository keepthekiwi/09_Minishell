/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:34:03 by nhaas             #+#    #+#             */
/*   Updated: 2022/05/24 12:50:46 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
/* for any character for which isupper(3) or islower(3) is true */
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/**
int	main(void)
{
	char chr1 = 'p';
	char chr2 = '!';
	printf("--- ft_isalpha ------------------\n\n");
	printf("chr 1: %c\now: %d\nor: %d\n\n", chr1, ft_isalpha(chr1), isalpha(chr1));
	printf("chr 2: %c\now: %d\nor: %d\n\n", chr2, ft_isalpha(chr2), isalpha(chr2));
}
**/

// octal zahlen
