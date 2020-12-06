/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:52:35 by kain2250          #+#    #+#             */
/*   Updated: 2020/12/06 19:27:43 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <CL/cl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/fcntl.h>

typedef struct			s_cl_sys
{
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	queue;
	char				*kernel_file;
	size_t				size_kernel;
	cl_mem				pixel_buf;
	cl_mem				objects_buf;
	cl_mem				light_buf;
	cl_mem				cam_buf;
}						t_cl_sys;

typedef struct			s_cl
{
	t_cl_sys			cl_sys;
}						t_cl;

void					init_cl(t_cl *cl);


void					err_out(char *message, int code);

#endif