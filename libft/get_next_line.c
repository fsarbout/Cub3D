/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:11:26 by fsarbout          #+#    #+#             */
/*   Updated: 2020/11/05 18:32:02 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fr(char **s)
{
	if (*s != NULL)
	{
		free(*s);
		*s = NULL;
	}
	return (-1);
}

int		search(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		abc(int fd, char **s2, int rd)
{
	char	*buff;
	char	*ptr;

	if ((buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	if (!search(*s2))
	{
		while (rd > 0)
		{
			rd = read(fd, buff, BUFFER_SIZE);
			buff[rd] = '\0';
			ptr = *s2;
			if ((*s2 = ft_strjoin(*s2, buff)) == NULL)
			{
				fr(&buff);
				fr(&ptr);
				return (-1);
			}
			fr(&ptr);
			if (search(*s2))
				break ;
		}
	}
	fr(&buff);
	return (rd);
}

int		lenline(char *s1)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	int			rd;
	char		*ptr;
	static char	*s1;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, NULL, 0) != 0)
		return (-1);
	if (!s1)
		if ((s1 = ft_strdup("")) == NULL)
			return (-1);
	if ((rd = abc(fd, &s1, 1)) == -1)
		return (-1);
	i = lenline(s1);
	if ((*line = ft_substr(s1, 0, i)) == NULL)
		return (fr(&s1));
	if (rd == 0)
	{
		fr(&s1);
		return (0);
	}
	ptr = s1;
	if ((s1 = ft_strdup(&s1[i + 1])) == NULL)
		return (fr(&s1));
	fr(&ptr);
	return (1);
}
