/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:41:09 by achambon          #+#    #+#             */
/*   Updated: 2017/10/01 15:22:46 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5
# define CHECKMALLOC(x) if (!x) return (-1);
# define NBFD 5000

# include <fcntl.h>
# include "libft.h"

int		ft_mycpy(char **dst, char *src);
int		get_next_line(int fd, char **file);

#endif
