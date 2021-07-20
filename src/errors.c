/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 11:37:02 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/14 18:09:52 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <string.h>

/*
** Prints the error and, if applicable, error information and exits with -1
**
** errnum == 0
**	calls `perror`
** info == NULL && errnum valid
**	prints the string corresponding to errnum
** info != NULL && errnum valid
**	appends 'ft_ls: ' in front of info and prints it with the string corres-
**	ponding with errnum
** info != NULL && errnum == -1
**	appends 'ft_ls: ' in front of info and prints it as error
*/

void	print_error_and_exit(char *info, int errnum)
{
	char	*msg;

	msg = NULL;
	if (info != NULL)
	{
		msg = ft_strnew(ft_strlen(info) + 7);
		ft_strncpy(msg, "ft_ls: ", 7);
		ft_strcat(msg, info);
	}
	if (errnum == 0)
		perror(msg);
	else if (msg == NULL && 0 < errnum && errnum < 103)
		ft_dprintf(2, "%s\n", strerror(errnum));
	else if (msg != NULL && 0 < errnum && errnum < 103)
		ft_dprintf(2, "%s: %s\n", msg, strerror(errnum));
	else if (msg != NULL && errnum == -1)
		ft_dprintf(2, "%s\n", msg);
	ft_strdel(&msg);
	exit(1);
}

void	error_inv_option(char option)
{
	char	*info;

	info = ft_strnew(ft_strlen(INVALID_OPTION) + 4 + ft_strlen(USAGE));
	ft_strcat(info, INVALID_OPTION);
	ft_strncat(info, "'", 1);
	ft_strncat(info, &option, 1);
	ft_strncat(info, "'\n", 2);
	ft_strcat(info, USAGE);
	print_error_and_exit(info, -1);
}
