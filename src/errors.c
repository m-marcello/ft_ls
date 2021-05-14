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

void	invalid_option(char option)
{
	char	*info;

	info = ft_strnew(ft_strlen(ILLEGAL_OPTION) + 2 + ft_strlen(USAGE));
	ft_strcat(info, ILLEGAL_OPTION);
	ft_strncat(info, &option, 1);
	ft_strncat(info, "\n", 1);
	ft_strcat(info, USAGE);
	error(info, -1);
}

void	error(char *info, int errnum)
{
	char	*msg;

	msg = NULL;
	if (info != NULL)
	{
		msg = ft_strnew(ft_strlen(info) + 7);
		ft_strncpy(msg, "ft_ls: ", 7);
		ft_strcat(msg, info);
	}
	if (msg != NULL && 0 < errnum && errnum < 103)
		ft_dprintf(2, "%s: %s\n", msg, strerror(errnum));
	else if (msg == NULL && 0 < errnum && errnum < 103)
		ft_dprintf(2, "%s\n", strerror(errnum));
	else if (msg != NULL && errnum == -1)
		ft_dprintf(2, "%s\n", msg);
	else if (errnum == 0)
		perror(msg);
	ft_strdel(&msg);
	exit(-1);
}
