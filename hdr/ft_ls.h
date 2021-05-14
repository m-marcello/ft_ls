/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 17:14:12 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/14 17:57:38 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "ft_ls_data.h"
# include "libft.h"

void	get_input(size_t argc, char **argv, t_input *input);
void	error(char *info, int errnum);
void	invalid_option(char c);

#endif