/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:01:39 by exam              #+#    #+#             */
/*   Updated: 2019/08/08 14:26:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
	
char	**ft_strsplit(char *src)
{
	int		i;
	int		b;
	int		k;
	char	**res;

	i = -1;
	b = -1;
	k = -1;
	if (!(res = (char **)malloc(sizeof(char *) * 1000)))
		return (NULL);
	res[++k] = (char *)malloc(sizeof(char) * 1000);
	while (src[++i])
	{
		if (src[i] == ' ' || src[i] == '\t')
		{
			res[k][++b] = '\0';
			k++;
			b = -1;
			if (!(res[k] = (char *)malloc(sizeof(char) * 1000)))
				return (NULL);
		}
		else 
			(res[k][++b] = src[i]);
	}
	res[k][++b] = '\0';
	res[++k] = (char *)malloc(sizeof(char) * 1);
	res[k][0] = '\0';
	return (res);
}

int		main(int argc, char **argv)
{
	int		j;
	int		k;
	int		tmp;
	char	**res;

	j = 0;	
	k = -1;
	if (argc == 2)
	{
		res = ft_strsplit(argv[1]);
		while (res[j])
			++j;
		j--;
		tmp = 0;
		while (j >= 0)
		{
			k = -1;
			while (res[j][++k])
				write (1, &res[j][k], 1);
			if (j && tmp)
				write (1, " ", 1);
			tmp++;
			j--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
