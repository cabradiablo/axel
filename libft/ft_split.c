/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:58:51 by alepinto          #+#    #+#             */
/*   Updated: 2023/05/01 04:07:53 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_security(char **matrix, int row)
{
	if (!matrix[row])
	{
		while (row--)
			free(matrix[row]);
		free(matrix);
		return (1);
	}
	return (0);
}

static int	ft_seglen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_segcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
				count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		row;
	char	**matrix;

	if (!s)
		return (NULL);
	i = 0;
	row = 0;
	matrix = malloc(sizeof(char *) * (ft_segcount(s, c) + 1));
	if (matrix == NULL)
		return (NULL);
	while (row < ft_segcount(s, c))
	{
		if (s[i] != c)
		{
			matrix[row] = ft_substr(s, i, ft_seglen(s, c, i));
			if (ft_security(matrix, row++) == 1)
				return (NULL);
			i += ft_seglen(s, c, i);
		}
		else
			i++;
	}
	matrix[ft_segcount(s, c)] = NULL;
	return (matrix);
}
/*
int main(void)
{
	char const *s = "hola lool"
	char c = 'b';
	printf("%s", ft_split(s, c));
	return (0);
}*/
