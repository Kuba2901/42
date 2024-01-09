/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:54:38 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/10 00:25:33 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static const char	*get_begin(char const *s1, char const *set)
{
	while (*s1 && ft_is_trim(*s1, set))
		s1++;
	return (s1);
}

static const char	*get_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen((char *)s1) - 1;
	while (s1[end] && ft_is_trim(s1[end], set))
		end--;
	return (&(s1[end]));
}

#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	int			size;
	const char	*beg;
	const char	*end;
	int			i;

	beg = get_begin(s1, set);
	end = get_end(s1, set) + 1;
	size = end - beg + 1;
	ret = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (beg - end)
	{
		ret[i] = *beg;
		i++;
		beg++;
	}
	return (ret);
}


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Test case 1: Basic trimming
    const char *str1 = "   Hello, World!   ";
    const char *set1 = " ";
    char *result1 = ft_strtrim(str1, set1);
    printf("Test 1: Trimmed string: '%s'\n", result1);
    free(result1);

    // Test case 2: Trim with multiple characters
    const char *str2 = "---Trim Me---";
    const char *set2 = "-";
    char *result2 = ft_strtrim(str2, set2);
    printf("Test 2: Trimmed string: '%s'\n", result2);
    free(result2);

    // Test case 3: Trim with different set of characters
    const char *str3 = ">>>Trim<<<";
    const char *set3 = ">";
    char *result3 = ft_strtrim(str3, set3);
    printf("Test 3: Trimmed string: '%s'\n", result3);
    free(result3);

    // Test case 4: Trim an already trimmed string
    const char *str4 = "Already Trimmed";
    const char *set4 = " ";
    char *result4 = ft_strtrim(str4, set4);
    printf("Test 4: Trimmed string: '%s'\n", result4);
    free(result4);

    // Test case 5: Trim an empty string
    const char *str5 = "";
    const char *set5 = " ";
    char *result5 = ft_strtrim(str5, set5);
    printf("Test 5: Trimmed string: '%s'\n", result5);
    free(result5);

    return 0;
}
