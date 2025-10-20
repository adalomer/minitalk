/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:18:10 by omadali           #+#    #+#             */
/*   Updated: 2024/12/14 19:31:11 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	signal_hand(int signal)
{
	static int	a = 0;
	static int	b = 1;

	if (signal == SIGUSR1)
		a = a + b;
	b = b * 2;
	if (b > 128)
	{
		write(1, &a, 1);
		b = 1;
		a = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_hand);
	signal(SIGUSR2, signal_hand);
	ft_putnbr(getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
