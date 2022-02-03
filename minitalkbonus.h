/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalkbonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:17:30 by rtracee           #+#    #+#             */
/*   Updated: 2021/09/16 22:37:49 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALKBONUS_H
# define MINITALKBONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	ft_pid_output(int pid);
void	ft_putnbr(int c);
void	ft_errors(int nbr, char *str);
int		ft_atoi(const char *str);
void	ft_putstr1(char *str);

#endif