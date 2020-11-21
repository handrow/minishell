/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiandre <kostbg1@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:34:39 by jiandre           #+#    #+#             */
/*   Updated: 2020/07/06 00:40:44 by jiandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static t_string		*get_buff(int fd)
{
	static t_string buff[FD_MAX];

	if (fd > FD_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buff[fd].str == NULL)
	{
		if (!(buff[fd].str = malloc(BUFFER_SIZE + 1)))
			return (NULL);
		buff[fd].str[0] = '\0';
		buff[fd].len = 0;
	}
	return (&buff[fd]);
}

static int			buff_join(t_string *str1, t_string *str2, size_t mod_len)
{
	size_t			new_len;
	char			*new_str;

	new_len = str2->len + mod_len;
	if (!(new_str = malloc(new_len + 1)))
		return (0);
	ft_memcpy(new_str, str2->str, str2->len);
	ft_memcpy(new_str + str2->len, str1->str, mod_len);
	new_str[new_len] = '\0';
	free(str2->str);
	str2->str = new_str;
	str2->len = new_len;
	return (1);
}

static int			get_line(t_string *buff, t_string *new_line)
{
	char			*line_end;
	size_t			mod_len;

	if ((line_end = ft_memchr(buff->str, '\n', buff->len)))
		mod_len = line_end - buff->str;
	else
		mod_len = buff->len;
	if (!(buff_join(buff, new_line, mod_len)))
		return (-1);
	if (line_end)
		ft_memcpy(buff->str, line_end + 1, buff->len - mod_len);
	buff->len = buff->len - mod_len - 1;
	if (line_end)
		return (1);
	return (0);
}

static void			string_free(t_string *string)
{
	free(string->str);
	string->len = 0;
	string->str = NULL;
}

int					get_next_line(int fd, char **line)
{
	t_string		*buff;
	t_string		new_line;
	long			line_len;
	int				stat;

	buff = get_buff(fd);
	if (!buff || !(new_line.str = malloc(sizeof(char))))
		return (-1);
	new_line.str[0] = '\0';
	new_line.len = 0;
	line_len = 0;
	stat = get_line(buff, &new_line);
	while (stat < 1 && (line_len = read(fd, buff->str, BUFFER_SIZE)) > 0)
	{
		buff->len = line_len;
		buff->str[line_len] = '\0';
		stat = get_line(buff, &new_line);
	}
	*line = new_line.str;
	stat = line_len == -1 ? -1 : stat;
	if (stat == -1)
		free(*line);
	if (stat < 1)
		string_free(buff);
	return (stat);
}
