/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:00:01 by root              #+#    #+#             */
/*   Updated: 2025/12/12 17:36:46 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **tab, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_count_words(char const *s, char c)
{
	int	nb_wrds;
	int	in_words;

	in_words = 0;
	nb_wrds = 0;
	while (*s)
	{
		if (*s != c && !in_words)
		{
			in_words = 1;
			nb_wrds++;
		}
		if (*s == c)
			in_words = 0;
		s++;
	}
	return (nb_wrds);
}

static void	ft_write_in_line(char *tab, char const *s, char c, int *start_wrd)
{
	int	i;

	i = 0;
	while (s[*start_wrd] && s[*start_wrd] != c)
	{
		tab[i] = s[*start_wrd];
		i++;
		(*start_wrd)++;
	}
	tab[i] = '\0';
}

static int	ft_malloc_line(char const *s, char c, char	**tab, int nb_words)
{
	int	start_wrd;
	int	size_wrd;
	int	word;

	start_wrd = 0;
	word = 0;
	while (s[start_wrd] && word < nb_words)
	{
		while (s[start_wrd] == c)
			start_wrd++;
		size_wrd = 0;
		while (s[start_wrd + size_wrd] != c && s[start_wrd + size_wrd])
			size_wrd++;
		tab[word] = (char *)malloc(sizeof(char) * (size_wrd + 1));
		if (!tab[word])
		{
			ft_free_split(tab, word);
			return (0);
		}
		ft_write_in_line(tab[word], s, c, &start_wrd);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	char	**tab;

	nb_words = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!tab)
		return (NULL);
	if (!ft_malloc_line(s, c, tab, nb_words))
		return (NULL);
	return (tab);
}
