#include "prueba.h"
#include "libft/libft.h"


void    print_3int(int ***data)
{
    int row;
    int colum;
    int ind;

    row = 0;
    while (data)
    {
        colum = 0;
        while (data[row])
        {
            ind = 0;
            while (data[row][colum])
            {
                while (data[row][colum][ind])
                    printf("%d-", data[row][colum][ind++]);
            }
            printf("  ");
            colum++;
        }
        printf("\n");
        row++;
    }
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