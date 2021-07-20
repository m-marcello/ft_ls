/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:38:50 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/27 16:11:55 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_data.h"

#include <stdarg.h>

char	**input_array(size_t size, ...)
{
	size_t	idx;
	char	**array;
	va_list ap;

	array = (char**)save_memalloc(sizeof(char*) * (size + 1));
	va_start(ap, size);
	array[0] = "ft_ls";
	idx = 1;
	while (idx < size)
	{
		array[idx] = va_arg(ap, char*);
		++idx;
	}
	va_end(ap);
	return(array);
}
