#include "prueba.h"
#include "libft/libft.h"

int ft_validinput(char *line)   //revisar y ser mas restrictivo
{
    int i;
    int stop;
    int breath;

    i = 0;
    breath = 0;
    while (line[i])
    {
        stop = i;
        if (line[i] == '*')
            i++;
        else
        {
            if (line[i] == '-' || line[i] == '+')
                i++;
            while ((line[i] >= '0' && line[i] <= '9'))
            {
                if (line[i + 1] == '\0' || line[i + 1] == '\n' || line[i + 1] == ' ')
                    breath++;
                i++;
            }
            if (line[i] == ',' && line[i + 1] == '0' && line[i + 2] == 'x')
                i += 3;
        }
        while (line[i] == ' ' || line [i] == '\n')
            i++;
        if (stop == i)
            return (-1);
    }    
    return (breath);
}

void    set_hole(char  *line, int **data_row)
{
    char *dup;

    dup = line;
    dup++;
    line = dup;
    *data_row[0] = -1;
    *data_row[1] = -42;
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
    if (ft_strncmp(line, ",0x", 3) == 0)
    {
        line += 3;
        line = get_IntColor(line, color);
    }
    else
        *color = -1;
    return (line);
}


void    procces_line(int ****data, int row,  char *line)
{
    int colum;

    colum = -1;
    if (*line == ' ')
        line++;
    while (*line)
    {
        (*data)[row][++colum] = (int *)malloc(sizeof(int) * 2);
        if (!(*data)[row][colum])
            {
                printf(" faalla en esta linea ---->%d\n", row);
                return ;
            }
        if (*line == '*')
            set_hole(line, &(*data)[row][colum]);
        else
        {
            line = get_height(line, &(*data)[row][colum][0]);
            line = get_color(line, &(*data)[row][colum][1]);
        }
        while (*line != '\0' && (*line < '0' || *line > '9'))
            line++;
    }
}

void    realloc_data(int ****data, int breadth, int row, char *line)
{
    if (row == 0)
        *data = (int ***)malloc(sizeof(int *) * (1));
    else
        *data = (int ***)realloc(*data, (sizeof(int *) * (row + 1)));
    if (!*data)
    {
        printf(" faalla en esta linea ---->%d\n", row);
        return ;
    }
    (*data)[row] = (int **)malloc(sizeof(int *) * (breadth));
    if (!(*data)[row])
    {
        printf(" faalla en esta linea ---->%d\n", row);
        return ;
    }
    procces_line(data, row, line);
}
void    realloc_dim(int **width, int row, int breadth)
{
    if (row == 0)
        *width = (int *)malloc(sizeof(int) * 1);
    else
        *width = (int *)realloc(*width, (sizeof(int) * (row + 1)));
    if (!*width)
    {
        printf(" faalla en esta linea ---->%d\n", row);
        return ;
    }
    (*width)[row] = breadth;
    
}
void    parser(t_map **map, t_dim **dim, char *filename)
{
    char    *line;
    int     fd;
    int     row;
    int     breadth;
    int     i;

    if (open_map(filename, &fd) == -1)
        return ;
    row = -1;
    while (1)
    {
        breadth = 0;
        i = 0;
        line = get_next_line(fd);
        //printf("line: %s\n", line);
        if (!line)
            break ;
        breadth = ft_validinput(line);
        if (breadth == -1)
            return ;
        row++;
        realloc_dim(&(*dim)->width, row, breadth);
        realloc_data(&(*map)->data, breadth, row, line);
        free(line);
    }
    (*dim)->height = row;
}
