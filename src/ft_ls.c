/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 18:10:27 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/14 16:08:31 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_input	input;

	ft_bzero(&input, sizeof(t_input));
	get_input((size_t)argc, argv, &input);
	return (0);
}
