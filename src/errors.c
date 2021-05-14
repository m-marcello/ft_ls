/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 11:37:02 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/14 16:22:32 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <string.h>

void	error(char *info, int errnum)
{
	if (info != NULL && 0 < errnum && errnum < 103)
		ft_dprintf(2, "%s: %s\n", info, strerror(errnum));
	else if (info == NULL && 0 < errnum && errnum < 103)
		ft_dprintf(2, "%s\n", strerror(errnum));
	else if (info != NULL && errnum == 0)
		ft_dprintf(2, "%s\n", info);
	exit(-1);
}
