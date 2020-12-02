/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrow <handrow@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:23:37 by handrow           #+#    #+#             */
/*   Updated: 2020/12/02 06:58:03 by handrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "err_msg.h"
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

static int	ft_istrcmp(const char *s1, const char *s2)
{
	while (*s1 && ft_tolower(*s1) == ft_tolower(*s2))
	{
		++s1;
		++s2;
	}
	return (ft_tolower(*s1) - ft_tolower(*s2));
}

static char	*compare_n_join(const char *name1, const char *name2,
							const char *dir)
{
	char	*tmp;
	char	*path;

	if (ft_istrcmp(name1, name2) != 0)
		return (NULL);
	path = NULL;
	if ((tmp = ft_strjoin(dir, "/")))
	{
		if (!(path = ft_strjoin(tmp, name1)))
			err_system_n_exit(1, NULL);
		free(tmp);
	}
	else
		err_system_n_exit(1, NULL);
	return (path);
}

char		*get_path(char *name, const char *dirs)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**path;
	int				i;
	char			*bin_path;

	i = -1;
	bin_path = NULL;
	if (!ft_strncmp(name, "/", 1) || !ft_strncmp(name, "./", 2) ||
		!ft_strncmp(name, "../", 3))
		return (ft_strdup(name));
	if (!dirs)
		return (NULL);
	if ((path = ft_split(dirs, ':')) == NULL)
		err_system_n_exit(1, NULL);
	while (bin_path == NULL && path[++i])
		if ((dir = opendir(path[i])))
		{
			while (bin_path == NULL && (entry = readdir(dir)))
				bin_path = compare_n_join(entry->d_name, name, path[i]);
			closedir(dir);
		}
	splitfree(path);
	return (bin_path);
}
