/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 17:43:15 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/14 17:56:46 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <sys/stat.h>

static void	save_options(const char *option_str, t_option *option)
{
	while (*option_str != '\0')
	{
		if (*option_str == 'a')
			option->a = 1;
		else if (*option_str == 'd' && option->a == 0)
			option->d = 1;
		else if (*option_str == 'g' && option->g == 0)
			option->g = 1;
		else if (*option_str == 'l' && option->l == 0)
			option->l = 1;
		else if (*option_str == 'r' && option->r == 0)
			option->r = 1;
		else if (*option_str == 'R' && option->rr == 0)
			option->rr = 1;
		else if (*option_str == 's' && option->s == 0)
			option->s = 1;
		else if (*option_str == 'S' && option->ss == 0)
			option->ss = 1;
		else if (*option_str == 't' && option->t == 0)
			option->t = 1;
		else if (*option_str == 'u' && option->u == 0)
			option->u = 1;
		else
			error_inv_option(*option_str);
		++option_str;
	}
}

void	get_input(size_t argc, char **argv, t_input *input)
{
	size_t		idx;
	struct stat	buf;

	idx = 1;
	ft_bzero(&buf, sizeof(struct stat));
	while (idx < argc && argv[idx][0] == '-')
	{
		save_options(&(argv[idx][1]), &(input->option));
		++idx;
	}
	if (idx == argc)
		input->file = ft_strdup(getenv("PWD"));
	else if (idx == argc - 1)
	{
		input->file = ft_strdup(argv[idx]);
		if (stat(input->file, &buf) != 0)
			print_error_and_exit(input->file, 0);
	}
	else
		print_error_and_exit("Too many arguments.", -1);
}
