/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaas <nhaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:18:33 by nhaas             #+#    #+#             */
/*   Updated: 2021/06/27 15:04:51 by nhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(char *str, int c, int n)
{
	int	i;

	i = 0;
	while (i != n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

/**
ft_putchar(char string[], int n){
	int i;
	for (i=0; i != n; i++){
		write(1, &string[i], 1);
	}
}

void main(){
	char str[] = "Hallo";
	char str2[] = "Hallo";
	ft_memset(str, '0', 2);
	//ft_putchar("test", 4);
	ft_memset(str, '0', 2);
	printf(str);
	printf("\n");
	memset(str2,'0', 2 );
	printf(str2);
} **/
