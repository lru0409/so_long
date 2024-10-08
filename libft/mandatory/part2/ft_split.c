/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:33:45 by rolee             #+#    #+#             */
/*   Updated: 2024/06/19 10:37:06 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	get_word_count(char const *s, char c);
static int	get_word_len(char const *s, char c);
static int	alloc_put_word(char **result, char const *s, char c, int i);
static int	set_result(char **result, char const *s, char c, int word_count);

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;

	word_count = get_word_count(s, c);
	if (word_count == 0)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	result[word_count] = NULL;
	if (set_result(result, s, c, word_count) == -1)
		return (NULL);
	return (result);
}

static int	get_word_count(char const *s, char c)
{
	int	flag;
	int	idx;
	int	count;

	flag = 0;
	idx = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[idx])
	{
		if (s[idx] == c)
			flag = 0;
		else
		{
			if (flag == 0)
				count++;
			flag = 1;
		}
		idx++;
	}
	return (count);
}

static int	set_result(char **result, char const *s, char c, int word_count)
{
	int	word_idx;
	int	str_idx;

	str_idx = 0;
	while (s[str_idx] == c && s[str_idx])
		str_idx++;
	word_idx = 0;
	while (word_idx < word_count)
	{
		if (alloc_put_word(result, &s[str_idx], c, word_idx) == -1)
			return (-1);
		while (s[str_idx] != c && word_idx + 1 != word_count)
			str_idx++;
		while (s[str_idx] == c && word_idx + 1 != word_count)
			str_idx++;
		word_idx++;
	}
	result[word_idx] = NULL;
	return (0);
}

static int	alloc_put_word(char **result, char const *s, char c, int i)
{
	int	idx;

	result[i] = (char *)malloc(get_word_len(s, c) + 1);
	if (!result[i])
	{
		idx = 0;
		while (idx < i)
		{
			free(result[idx]);
			idx++;
		}
		free(result);
		return (-1);
	}
	idx = 0;
	while (s[idx] != c && s[idx])
	{
		result[i][idx] = s[idx];
		idx++;
	}
	result[i][idx] = 0;
	return (0);
}

static int	get_word_len(char const *s, char c)
{
	int	idx;

	idx = 0;
	while (s[idx] != c && s[idx])
		idx++;
	return (idx);
}
