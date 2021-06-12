/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_errors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 09:31:12 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/25 09:31:12 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

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
    }
    return (argv);
}

Test(get_input, inv_opt, .exit_code = -1)
{
    char *input = "-j";

    int argc = get_argc(input);
    char **argv = get_argv(input);
    t_input input;

    get_input(argc, argv, &input);
}

// invalid option
// double option
// file does not exist
// too many arguments
