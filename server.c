/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:57:05 by rtracee           #+#    #+#             */
/*   Updated: 2021/09/16 22:49:14 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int c)
{
	if (c == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (c < 0)
	{
		write(1, "-", 1);
		ft_putnbr(c * (-1));
	}
	else
	{
		if (c >= 10)
			ft_putnbr(c / 10);
		c = c % 10 + 48;
		write(1, &c, 1);
	}
}

static void	ft_processing(int a)
{
	static int		x;
	static int		total;

	if (!x)
		x = 128;
	if (a == SIGUSR1)
		total += x;
	 x /= 2;
	if (x == 0)
	{
		if (total == '\0')
			write(1, "\n", 1);
		else
			write(1, &total, 1);
		x = 128;
		total = 0;
	}
}

void	ft_pid_output(int pid)
{
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_pid_output(pid);
	signal(SIGUSR1, ft_processing);
	signal(SIGUSR2, ft_processing);
	while (1)
		pause();
	return (0);
}
