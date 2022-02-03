/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientbonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:27:17 by rtracee           #+#    #+#             */
/*   Updated: 2021/09/16 22:50:42 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	ft_putstr1(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

void	ft_errors(int nbr, char *str)
{
	if (nbr != 3)
	{
		ft_putstr1("Error: incorrect number of arguments\n");
		exit (0);
	}
	while (*str)
	{
		if (*str == '-')
			str++;
		while (*str)
		{
			if (*str > '9' || *str < '0')
			{
				ft_putstr1("Error: incorrect PID\n");
				exit(0);
			}
			str++;
		}
	}
}

static void	ft_processing(pid_t pid, char c)
{
	int	s;

	s = 128;
	while (s > 0)
	{
		if (c & s)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr1("Error: signal transmission error\n");
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr1("Error: signal transmission error\n");
				exit(0);
			}
		}
		usleep(130);
		s /= 2;
	}
}

static void	ft_confirmation(int s)
{
	if (s == SIGUSR1)
		ft_putstr1("Message delivered\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	signal(SIGUSR1, ft_confirmation);
	ft_errors(argc, argv[1]);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str != '\0')
		ft_processing(pid, *(str++));
	ft_processing(pid, '\0');
	return (0);
}
