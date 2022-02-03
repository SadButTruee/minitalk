/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:59:27 by rtracee           #+#    #+#             */
/*   Updated: 2021/09/16 22:16:30 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int c);
void	ft_pid_output(int pid);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putstr1(char *str);
void	ft_errors(int nbr, char *str);

#endif