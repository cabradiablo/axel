#ifndef PRUEBA_H
# define PRUEBA_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#  endif

# include "libft/libft.h"

typedef struct s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_dim 
{
    int		height;
    int		*width;
}				t_dim;

typedef struct s_map
{
	int 	***data;
	int		interval_x[2];
	int		interval_y[2];
	int		interval_z[2];
}	t_map;


//parser.c
void    parser(t_map **map, t_dim **dim, char *filename);
void    realloc_data(int ****data, int width, int row,  char *line);
void    realloc_dim(int **width, int row, int breadth);
void    procces_line(int ****data, int row,  char *line);
char    *get_color(char *line, int *color);
char    *get_height(char *line, int *nbr);
void    set_hole(char  *line, int **data_row);
int     ft_validinput(char *line);

//error.c
void    ft_error(char *msg);

//utils.c
char    *strjoin(char *head, char *tail);
int     open_map(char *av, int *fd);
void	print_map(int ***map, t_dim *dim);
char    *get_IntColor(char *line, int *color);

#endif