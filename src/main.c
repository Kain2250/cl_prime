/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:55:17 by kain2250          #+#    #+#             */
/*   Updated: 2020/12/06 19:15:14 by kain2250         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(void)
{
	t_cl	*cl;

	cl = (t_cl *)malloc(sizeof(t_cl));
	init_cl(cl);
	(void)cl;
	return (0);
}