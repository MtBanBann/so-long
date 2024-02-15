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

# define ESC_KEY 65307

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int open_window(void);
int map_test(char **argv);
int map_tab(char **argv, size_t i);
int map_valid(char **map, int len);
char	*ft_strdup_long(const char *s);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	close_window(int keycode, t_vars *vars);

#endif