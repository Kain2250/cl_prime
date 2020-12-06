/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:11:13 by kain2250          #+#    #+#             */
/*   Updated: 2020/12/06 23:44:18 by kain2250         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	load_kernel(t_cl *cl)
{
	int		fd;

	if ((fd = open("./kernels/kernel.cl", O_RDONLY)) < 0 || read(fd, 0, 0) < 0)
	{
		close(fd);
		print_error("[-] Failed to load kernel from file.", 1000);
	}
	cl->cl_sys.kernel_file = (char*)malloc(1000);
	cl->cl_sys.size_kernel = read(fd, cl->cl_sys.kernel_file, 1000);
	close(fd);
}


void				init_cl(t_cl *cl)
{
	cl_platform_id	platform_id;
	cl_uint			num_platforms;
	cl_device_id	device_id;
	cl_uint			num_devices;
	cl_int			ret;

	cl_err(ret = clGetPlatformIDs(1, &platform_id, &num_platforms));
	cl_err(ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id,
		&num_devices));
	cl->cl_sys.context = clCreateContext(NULL, 1, &device_id,
		NULL, NULL, &ret);
	cl_err(ret);
	cl->cl_sys.queue = clCreateCommandQueue(cl->cl_sys.context,
		device_id, 0, &ret);
	cl_err(ret);
	load_kernel(cl);
	cl->cl_sys.program = clCreateProgramWithSource(cl->cl_sys.context, 1,
		(const char **)&(cl->cl_sys.kernel_file),
		(const size_t *)&(cl->cl_sys.size_kernel), &ret);
	cl_err(ret = clBuildProgram(cl->cl_sys.program, 1, &device_id,
		"-I include/ -I kernels/ -Werror", NULL, NULL));
	cl->cl_sys.kernel = clCreateKernel(cl->cl_sys.program,
		"render_scene", &ret);
	cl_err(ret);
}