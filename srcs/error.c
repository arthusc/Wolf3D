/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:14:55 by achambon          #+#    #+#             */
/*   Updated: 2017/10/13 20:03:14 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	error_arg(void)
{
	write(1, "error argv\n", 12);
	write(1, "<filename> <map>\n", 18);
	exit(1);
}

void	error_map(void)
{
	write(1, "error map\n", 10);
	exit(1);
}