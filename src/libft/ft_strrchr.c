/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuzio <lmuzio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:58:17 by lmuzio            #+#    #+#             */
/*   Updated: 2022/01/18 17:58:18 by lmuzio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*find;

	find = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			find = (char *)s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return (find);
}
