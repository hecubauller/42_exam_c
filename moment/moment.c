/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:01:44 by exam              #+#    #+#             */
/*   Updated: 2019/08/09 14:35:48 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moment.h"

char	*moment(unsigned int duration)
{
	unsigned int	time;
	unsigned int	tmp;
	unsigned int	tmp2;
	char			w;
	int				cnt;
	int				cnt2;
	char			*res;

	res = NULL;
	cnt = 1;
	cnt2 = -1;
	tmp = duration;
	time = 0;
	if (!(res = (char*)malloc(sizeof(char)*100)))
		return (NULL);
	res[99] = '\0';
	if (duration < 60)
	{
		(duration == 1) ? (w = 'o') : (w = 'p');
		time = duration;
	}
	else if (duration < 3600)
	{
		time = duration / 60;
		(time == 1) ? (w = 'q') : (w = 'm');	
	}
	else if (duration < 86400)
	{
		time = duration / 3600;
		(time == 1) ? (w = 'h') : (w = 'z');
	}
	else if (duration < 1296000)
	{
		time = duration / 43200;
		(time == 1) ? (w = 'l') : (w = 'j');
	}
	else 
	{
		time = duration / 1296000;
		(time == 1) ? (w = 's') : (w = 'v');
	}
	tmp2 = time;
	time > 9 ? cnt++ : 0;
	if (tmp2 > 9)
	{
		res[++cnt2] = tmp2 / 10 + '0';
		res[++cnt2] = tmp2 % 10 + '0';
	}
	else 
		res[++cnt2] = tmp2 + '0';
	res[++cnt2] = ' ';
	++cnt2;
	if (w == 'o' || w == 'p')

	{
		res[cnt2] = 's';
		res[++cnt2] = 'e';
		res[++cnt2] = 'c';
		res[++cnt2] = 'o';
		res[++cnt2] = 'n';
		res[++cnt2] = 'd';
		(w == 'p') ? res[++cnt2] = 's' : 0;
	}		 
	if (w == 'q' || w == 'm')

	{
		res[cnt2] = 'm';

		res[++cnt2] = 'i';
		res[++cnt2] = 'n';
		res[++cnt2] = 'u';
		res[++cnt2] = 't';
		res[++cnt2] = 'e';
		(w == 'm') ? (res[++cnt2] = 's') : 0;
	}
	else if (w == 'h' || w == 'z')
	{
		res[cnt2] = 'h';
		res[++cnt2] = 'o';
		res[++cnt2] = 'u';
		res[++cnt2] = 'r';
		(w == 'z') ? res[++cnt2] = 's' : 0;
	}
	else if (w == 'l' || w == 'j')
	{
		res[cnt2] = 'd';
		res[++cnt2] = 'a';
		res[++cnt2] = 'y';
		(w == 'j') ? res[++cnt2] = 's' : 0;
	}
	else if (w == 's' || w == 'v')
	{
		res[cnt2] = 'm';
		res[++cnt2] = 'o';
		res[++cnt2] = 'n';
		res[++cnt2] = 't';
		res[++cnt2] = 'h';
		(w =='v') ? res[++cnt2]	= 's' : 0;
	}
	res[++cnt2] = ' ';
	res[++cnt2] = 'a';
	res[++cnt2] = 'g';
	res[++cnt2] = 'o';
	res[++cnt2] = '.';
	res[++cnt2] = '\0';
	return (res);
}

