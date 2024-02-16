/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:31:58 by afavier           #+#    #+#             */
/*   Updated: 2024/02/16 22:08:57 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../minilibx-linux/mlx.h"

int map_test(char **argv)
{
	char *line;
	int		fd;
	size_t i;
	size_t len;


	len = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0)
			len = ft_strlen_so_long(line);
		
		else if (len != ft_strlen_so_long(line))
		{
			close(fd);
			free(line);
			ft_dprintf(2, "so_long: %s: map invalidbvewhb\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
	{
		ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}
	free(line);
	map_tab(argv, i);
	return (0);
}

int map_tab(char **argv, size_t len)
{
	char *line;
	char **map;
	int fd;
	int y;
	
	y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(char *) * (len));
	if (!map)
	{
		if (close(fd) == -1)
		{
			ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
			exit(EXIT_FAILURE);
		}
		ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		map[y++] = ft_strdup_long(line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
	{
		ft_dprintf(2, "so_long: %s: %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}
	free(line);
	map_valid(map, len);
	open_window(map);
	return (0);
}

int map_valid(char **map, int len)
{
	int i;
	int y;
	int len_map;

	i = 0;
	y = 0;
	len_map = strlen(map[0]);
	while (i < len-1)
	{
		
		while (map[i][y])
		{	
			
			if ((i == 0 || i == len - 1) && y < len_map-2)
			{
				
				if(map[i][y] != '1')
				{
					printf("haut ou bas mauvais");
					exit(EXIT_FAILURE);
				}
			}
			else if(map[i][0] != '1' || map[i][len_map - 2] != '1')
			{
				printf("coter mauvais");
				exit(EXIT_FAILURE);	
			}
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

char	*ft_strdup_long(const char *s)
{
	size_t	i;
	size_t	y;
	char	*tab;

	i = ft_strlen(s);
	y = 0;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	while (s[y])
	{
		tab[y] = s[y];
		y++;
	}
	tab[y] = '\0';
	return (tab);
}

size_t	ft_strlen_so_long(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

