int map_test()
{
	char *line;

	line = get_next_line(1);
	while (line)
	{
		if (wall(line))
		{
			write(1, "ERROR", 5);
			return(0);
		}
		free(line);
		line = get_next_line(1);
	}
	free(line);
}

bool read_swap(char *line)
{
	if(!(ft_strcmp(line, "sa\n")))
	{
		swap_sa(tab_a);
		return (false);
	}
	if(!(ft_strcmp(line, "sb\n")))
	{
		swap_sb(tab_b);
		return (false);
	}
	if(!(ft_strcmp(line, "ss\n")))
	{
		swap_sa(tab_a);
		swap_sb(tab_b);
		return (false);
	}
	return (true);
}