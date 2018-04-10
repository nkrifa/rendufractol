/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:39:33 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/24 23:41:54 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2 || ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 4)
	{
		ft_putendl("Error");
		ft_putstr_fd("Put 1 / 2 / 3 / 4 as param", 2);
		ft_putstr_fd(" to get Julia / Mandelbrot / Tricorn / Trijulia", 2);
		return (0);
	}
	if ((e = init_env(argv[1])) != NULL)
	{
		ft_draw(e);
		mlx_key_hook(e->win, key_hook, e);
		mlx_mouse_hook(e->win, ft_mouse, e);
		mlx_loop(e->mlx);
		mlx_destroy_window(e->mlx, e->win);
	}
	return (0);
}
