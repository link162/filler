#include "header.h"
#include <string.h>
#include <stdlib.h>

int	find_squere(int field[][9], int y, int x, int a)
{
	int ry;
	int rx;
	int i;
	int j;

	ry = (y / 3) * 3;
	rx = (x / 3) * 3;
	j = 0;
	i = 0;
	while (j++ < 3)
	{
		x = rx;
		while (i++ < 3)
			if (field[ry][x++] == a)
				return (0);
		ry++;
	}
	return (1);
}

int avalible(int field[][9], int y, int x, int a)
{
	int z;

	z = 0;
	while (z < 9)
	{
		if (field[y][z] == a)
			return (0);
		z++;
	}
	z = 0;
	while (z < 9)
	{
		if (field[z][x] == a)
			return (0);
		z++;
	}
	return (find_squere(field, y, x, a));
}

int		fill_sudoku(int field[][9], int y, int x)
{
	int a;

	a = 1;
	if (y > 8)
		return (1);
	if (field[y][x] > 0)
		return (fill_sudoku(field, y, x + 1));
	if (x > 8)
		return (fill_sudoku(field, y + 1, 0));
	if (field[y][x] == 0)
		while (a < 10)
		{
			if (avalible(field, y, x, a))
			{
				field[y][x] = a;
				if (fill_sudoku(field, y,  x + 1))
					return (1);
				field[y][x] = 0;
			}
			a++;
		}
	return (0);
}

void	print_sudoku(int field[][9])
{
	int x;
	int y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
			printf("%i", field[y][x++]);
		printf("\n");
		y++;
	}
}

void	convert_to_int(char *str)
{
	int field[9][9];
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			if (str[i] != '.')
				field[y][x] = (str[i] - '0');
			else
				field[y][x] = 0;
			x++;
			i++;
		}
		y++;
		i++;
	}
	if (fill_sudoku(field, 0, 0))
		print_sudoku(field);
	else
		printf("error map\n");

}

void	ft_read_file(int fd)
{
	char	str[95];
	int		i;
	int		n;
	int		c;

	i = read(fd, str, 95);
	str[i] = '\0';
	i = 0;
	n = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (i + 1) % 10 == 0)
			n++;
		else if ((str[i] >= '1' && str[i] <= '9') || str[i] == '.')
			c++;
		else
		{
			printf("error now\n");
			break;
		}
		i++;
	}
	if (n == 9 && c == 81 && str[i] == '\0')
		convert_to_int(str);
	else
		printf("error here\n");
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("errorrrr\n");
			exit (1);
		}
		else
			ft_read_file(fd);
		close(fd);
	}
	else
		printf("usage: ./sudoku file_name\n");
}
