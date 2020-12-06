/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:52:35 by kain2250          #+#    #+#             */
/*   Updated: 2020/12/06 20:35:29 by kain2250         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# include "libft.h"

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


void					cl_err(int code);

#endif