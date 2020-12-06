/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:26:20 by cwing             #+#    #+#             */
/*   Updated: 2020/12/07 00:56:02 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void 		print_error(char *message, int code)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	if (code != 0)
	{
		ft_putstr_fd(" code: ", STDERR_FILENO);
		ft_putnbr_fd(code, STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	cl_kernel_err(int code)
{
	if (code == CL_INVALID_PROGRAM)
		print_error("CL: Invalid program", 0);
	else if (code == CL_COMPILER_NOT_AVAILABLE)
		print_error("CL: Compiler not avalible", 0);
	else if (code == CL_INVALID_OPERATION)
		print_error("CL: Invalid operation", 0);
	else if (code == CL_BUILD_PROGRAM_FAILURE)
		print_error("CL: Bild program failure", 0);
	else if (code == CL_INVALID_BINARY)
		print_error("CL: Invalid binary", 0);
	else
		print_error("CL: Xz wtf error", code);
}

void		cl_err(int code)
{
	if (code == CL_SUCCESS)
		return ;
	else if (code == CL_INVALID_CONTEXT)
		print_error("CL: Invalid context", 0);
	else if (code == CL_INVALID_PLATFORM)
		print_error("CL: Invalid platform", 0);
	else if (code == CL_INVALID_VALUE)
		print_error("CL: Invalid value", 0);
	else if (code == CL_INVALID_DEVICE)
		print_error("CL: Invalid device", 0);
	else if (code == CL_DEVICE_NOT_FOUND)
		print_error("CL: Device not found", 0);
	else if (code == CL_OUT_OF_HOST_MEMORY)
		print_error("CL: Out of host memory", 0);
	else if (code == CL_OUT_OF_RESOURCES)
		print_error("CL: Out of resources", 0);
	else
		cl_kernel_err(code);
}
