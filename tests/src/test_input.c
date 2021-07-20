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
#include <criterion/criterion.h>
#include <stdlib.h>

//#include <stdarg.h>

//char	**input_array(size_t size, ...)
//{
	//size_t	idx;
	//char	**array;
	//va_list ap;
//
	//array = (char**)save_memalloc(sizeof(char*) * (size + 1));
	//va_start(ap, size);
	//array[0] = "ft_ls";
	//idx = 1;
	//while (idx < size)
	//{
		//array[idx] = va_arg(ap, char*);
		//++idx;
	//}
	//va_end(ap);
	//return(array);
//}

int get_argc(char *arg_str)
{
	int argc = 1;

	while (*arg_str)
	{
		if (*arg_str == ' ' && *(arg_str + 1) && *(arg_str + 1) != ' ')
			++argc;
		++arg_str;
	}
	return (argc);
}

char **get_argv(char *arg_str)
{
	int argc = get_argc(arg_str);
	char **arg_split = ft_strsplit(arg_str, ' ');
	char **argv = ft_save_memalloc((size_t)argc);

	int i = 0;
	while (i < argc)
	{
		if (arg_split[i] == NULL)
		{
			ft_putendl("arg_split and argc are not congruent.");
			break;
		}
		argv[i] = arg_split[i];
		++i;
	}
	return (argv);
}

Test(get_input, no_input)
{
	char *arg = "ft_ls";
	int argc_expected = 1;
	char *file_ecpected = getenv("PWD");

	int argc = get_argc(arg);
	cr_assert(eq(i32, argc, argc_expected));
	char **argv = get_argv(arg);
	t_input input;
	get_input(argc, argv, &input);
	cr_assert(eq(str, input.file, file_ecpected));
}

