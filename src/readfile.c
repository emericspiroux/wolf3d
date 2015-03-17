/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 14:21:34 by espiroux          #+#    #+#             */
/*   Updated: 2015/03/17 16:57:47 by espiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static unsigned int			read_countcase(const char *str, int c)
{
	int						count;
	unsigned int			line;
	unsigned int			i;

	count = 0;
	i = 0;
	line = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && count != 1)
		{
			line++;
			count = 1;
		}
		else if (str[i] == c)
			count = 0;
		i++;
	}
	if (line == 0)
		line++;
	return (line);
}

static void					put_line_map(t_env *e, char *line, int i)
{
	int						j;
	char					**save_line;
	unsigned int			nb_case;

	j = 0;
	save_line = ft_strsplit((const char *)line, ' ');
	nb_case = read_countcase((const char *)line, ' ');
	e->map.map[i] = (int *)malloc(sizeof(int) * nb_case);
	while (save_line[j])
	{
		e->map.map[i][j] = ft_atoi(save_line[j]);
		free(save_line[j]);
		j++;
	}
	free(save_line);
}

int							read_file(char *file, t_env *e)
{
	int						fd;
	int						i;
	char					*line;

	i = 0;
	e->map.map = (int **)malloc(sizeof(int) * 100);
	if (!((fd = open(file, O_RDONLY)) > 0))
	{
		perror(file);
		strerror(fd);
		close(fd);
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		put_line_map(e, line, i);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
