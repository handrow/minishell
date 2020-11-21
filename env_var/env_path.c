/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:23:37 by handrow           #+#    #+#             */
/*   Updated: 2020/11/19 00:18:29 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <dirent.h>

static void	splitfree(char **out)
{
	size_t		i;

	i = 0;
	while (out[i])
	{
		free(out[i]);
		i++;
	}
	free(out);
}

static char	*compare_n_join(const char *name1, const char *name2,
							const char *dir)
{
	char	*tmp;
	char	*path;
	
	if (ft_strcmp(name1, name2) != 0)
		return (NULL);
	path = NULL;
	if ((tmp = ft_strjoin(dir, "/")))
	{
		path = ft_strjoin(tmp, name2);
		free(tmp);
	}
	return (path);
}

char		*get_path(char *name, const char *dirs)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**path;
	int				i;
	char			*bin_path;

	i = 0;
	bin_path = NULL;
	if ((path = ft_split(dirs, ':')) == NULL)
		return (NULL);
	while (bin_path == NULL && path[i])
	{
		if ((dir = opendir(path[i])))
		{
			while(bin_path == NULL && (entry = readdir(dir)))
				bin_path = compare_n_join(entry->d_name, name, path[i]);
			closedir(dir);
		}
		++i;
	}
	splitfree(path);
	return (bin_path);
}
