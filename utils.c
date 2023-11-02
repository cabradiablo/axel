#include "prueba.h"
#include "libft/libft.h"

void	print_map(int ***map, t_dim *dim)
{
    (void)map;
    //int i = 0;
    printf("%ld\n", (long)dim->height);
    /*
	int	row;
	int	column;
	
    row = -1;
    printf("Numero de filas total :%d\n", dim->height);
    while (++row <= dim->height)
	{
        printf("fila nº: %d   de ancho : %d\n", row, dim->width[row]);
		column = -1;
		while (++column <= dim->width[row])
		{
			printf("%d,", map[row][column][0]);
            printf("%d ", map[row][column][1]);
		}
		printf("\n");
	}
    */
}
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

int open_map(char *av, int *fd)
{
    char    *file;

    file = strjoin("./maps/", av);
    if (!file)
        return (-1);
    *fd = open(file, O_RDONLY);
    free(file);
    if (*fd == -1)
        return (-1);
    else
        return (0);
}