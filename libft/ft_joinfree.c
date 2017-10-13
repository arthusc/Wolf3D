/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:27:49 by achambon          #+#    #+#             */
/*   Updated: 2017/10/04 15:47:29 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *s1, char *s2, char **addr)
{
	char	*join;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((join = ft_strnew(len)) == 0)
		return (NULL);
	join = ft_strcpy(join, (char*)s1);
	join = ft_strcat(join, s2);
	if (addr)
		free(*addr);
	return (join);
}
