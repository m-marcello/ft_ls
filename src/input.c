/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 17:43:15 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/14 16:12:10 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/errno.h>
#include <stdlib.h>

static void	save_options(const char *option_str, t_option *option)
{
	while (*option_str != '\0')
	{
		if (*option_str == 'a')
			option->a = 1;
		else if (*option_str == 'd')
			option->d = 1;
		else if (*option_str == 'g')
			option->g = 1;
		else if (*option_str == 'l')
			option->l = 1;
		else if (*option_str == 'r')
			option->r = 1;
		else if (*option_str == 'R')
			option->rr = 1;
		else if (*option_str == 's')
			option->s = 1;
		else if (*option_str == 'S')
			option->ss = 1;
		else if (*option_str == 't')
			option->t = 1;
		else if (*option_str == 'u')
			option->u = 1;
		else
			error(ft_strndup(option_str, 1), EINVAL);
		++option_str;
	}
}

static void	save_file(const char *path, t_input *input)
{
	input->file = ft_strdup(path);
	ft_printf("file is %s\n", input->file);
}

void	get_input(size_t argc, char **argv, t_input *input)
{
	size_t	idx;

	idx = 1;
	while (idx < argc && argv[idx][0] == '-')
	{
		save_options(&(argv[idx][1]), &(input->option));
		++idx;
	}
	if (idx == argc)
		save_file(getenv("PWD"), input);
	else if (idx == argc - 1)
		save_file(argv[idx], input);
	else
		error("Too many arguments.", 0);
}
