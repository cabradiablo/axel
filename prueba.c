#include "prueba.h"
#include "libft/libft.h"



int ft_validinput(char  c, char next) //mirar return dentro de los ifs
{

    if ((c >= '0' && c <= '9') || c == '*' || c == '-' || c == '+')
    {
        if (!next || next == '\n' || next == ' ' || next == ',')
            return (1);
        else
            return (0);
    }
    else if (c == ' ' || c == ',' || c == 'x')
        return (0);
    else if (c == '\n')
        return (0);
    return (-1);
}

void    set_hole(char  *line, int *data_row)
{
    char *dup;

    dup = line;
    dup++;
    line = dup;
    data_row[0] = -1;
    data_row[1] = -1;
}

char *get_height(char *line, int *nbr)
{
    int neg;
    int num;
    char *dup;
    
    neg = 1;
    num = 0;
    dup = line;
    if (*dup == '-' || *dup == '+')
    {
        if (*dup++ == '-')
            neg *= -1;
    }
    while (*dup >= '0' && *dup <= '9')
    {
        num = num * 10 + (*dup++ - '0');
    }
    *nbr = num * neg;
    line = dup;
    return (line);
}


char    *get_color(char *line, int *color)
{
    if (*line == ',' && *line + 1 == '0' && *line + 2 == 'x')
    {
        *line += 3;
        get_height(line, color);
    }
    else
        *color = -1;
    return (line);
}

void    procces_line(int ***data, int row,  char *line)
{
    int colum;

    colum = -1;
    while (*line)
    {
        data[row][++colum] = (int *)malloc(sizeof(int) * 2);
        if (!data[row][colum])
            return ;
        if (*line == '*')
            set_hole(line, &data[row][colum][0]);
        else
        {
            line = get_height(line, &data[row][colum][0]);
            line = get_color(line, &data[row][colum][1]);
        }
        while (*line == ' ' || *line == '\n')
            line++;
    }
}

void    realloc_data(int ***data, int *datadim_width, int row,  char *line)
{
    int     i;
    int     width;

    width = 0;
    if (row)
        data = (int ***)malloc(sizeof(int *));
    else
        data = (int ***)realloc(data, (sizeof(int *) * (row + 1)));
    if (!data) 
        return ;
    i = -1;
    while (line[++i])
        width += ft_validinput(line[i], line[i + 1]);
    data[row] = (int **)malloc(sizeof(int *) * (width));
    if (!data[row])
        return ;
    procces_line(data, row, line);
    (void)datadim_width;
    //*datadim_width = width;
}

void    parser(t_map **map, char *filename)
{
    char    *line;
    int     fd;
    int     row;

    open_map(filename, &fd);
    if (fd == -1)
        return ;
    row = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        realloc_data((*map)->data, &((*map)->dim->width[row]), row, line); 
        free(line);
        row++;
    }
    (*map)->dim->height = row;
}
