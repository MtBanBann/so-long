#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_dprintf.h"
#include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>

int open_window(void);
int map_test(char **argv);
int map_tab(char **argv, size_t i);
int map_valid(char **map, int len);
char	*ft_strdup_long(const char *s);

#endif