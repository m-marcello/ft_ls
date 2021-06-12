/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls_data.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 17:16:38 by mmarcell      #+#    #+#                 */
/*   Updated: 2021/05/14 18:02:37 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_DATA
# define FT_LS_DATA

# define USAGE "usage: ls [-RSadglrstu] [file ...]"
# define INVALID_OPTION "invalid option -- "

typedef struct s_option
{
	unsigned int	a : 1;
	unsigned int	d : 1;
	unsigned int	g : 1;
	unsigned int	l : 1;
	unsigned int	r : 1;
	unsigned int	rr : 1;
	unsigned int	s : 1;
	unsigned int	ss : 1;
	unsigned int	t : 1;
	unsigned int	u : 1;
}t_option;

typedef struct s_input
{
	t_option	option;
	char		*file;
}t_input;

#endif
