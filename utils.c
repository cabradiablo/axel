#include "prueba.h"
#include "libft/libft.h"

void	print_map(int ***map)
{
	int	row;
	int	column;
	row = 0;
	while (row < 2)
	{
		column = 0;
		while (column < 2)
		{
			printf("%d", map[row][column][0]);
			column++;
		}
		printf("\n");
		row++;
	}
}
/*char    *get_color(char *line, int *color)
{
    if (ft_strncmp(line, ",0x", 3) == 0)
    {
        *line += 3;
        line = get_IntColor(line, color);
    }
    else
        *color = -1;
    return (line);
}*/

char *get_IntColor(char *line, int *color)
{
    int result = 0;
    int shift = 0;
    
    while (*line && shift < 6) 
    {
        char digit = *line;
        int value;

        if (digit >= '0' && digit <= '9')
            value = digit - '0';
        else if (digit >= 'A' && digit <= 'F')
            value = digit - 'A' + 10;
        else if (digit >= 'a' && digit <= 'f')
            value = digit - 'a' + 10;
        else
            break;
        result = (result << 4) | value;
        shift++;
        line++;
    }    
    *color = result;
    return line;
}
char    *strjoin(char *head, char *tail)
{
    int     i;
    int     j;
    char    *result;
    
    i = -1;
    j = -1;
    while (*head && head[++i])
        ;
    while (*tail && tail[++j])
        ;
    if (i == -1 || j == -1)
        return (NULL);
    result = (char *)malloc(i + j + 1);
    if (!result)
        return (NULL);
    result[i + j] = '\0';
    while (--j >= 0)
        result[j + i] = tail[j];
    while (--i >= 0)
        result[i] = head[i];
    return (result);
}

void    open_map(char *av, int *fd)
{
    char    *file;

    file = strjoin("maps/", av);
    if (!file)
        return ;
    *fd = open(file, O_RDONLY);
    if (*fd == -1)
        return ;
    free(file);
}