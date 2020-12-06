/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 23:28:18 by cwing             #+#    #+#             */
/*   Updated: 2020/12/06 23:53:27 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char					*get_file(char *name)
{
	char		*file;
	t_stat		stat_file;
	int			fd;

	fd = open(name, O_RDONLY);
	file = NULL;
	if (fd > 0)
	{
		if (stat(name, &stat_file) != 0)
		{
			file = (char*)malloc(sizeof(char) * (stat_file.st_size + 1));
			if (file)
			{
				if (read(fd, file, stat_file.st_size) != stat_file.st_size)
				{
					print_error("Read file error", 0);
					free(file);
			}
			else
				print_error("Malloc alloc error", 0);
		}
		else
			print_error("Stat call error", 0);
		close(fd);
	}
	return (file);
}