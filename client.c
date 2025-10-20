/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:18:13 by omadali           #+#    #+#             */
/*   Updated: 2024/12/14 19:35:47 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(char *c)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (c[a])
	{
		if (c[a] > 47 && c[a] < 58)
		{
			b = b * 10 + (c[a] - '0');
		}
		else
			return (0);
		a++;
	}
	return (b);
}

void	bit_change(int pid, char a)
{
	int	c;

	c = 0;
	while (c++ < 8)
	{
		if ((a & 1) == 1)
			kill(pid, SIGUSR1);
		else if ((a & 1) == 0)
			kill(pid, SIGUSR2);
		a = a >> 1;
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	int	b;
	int	c;

	if (argc != 3 || argv[1][0] == '-')
	{
		return (write(1, "wrong input", 11));
	}
	c = ft_atoi(argv[1]);
	b = 0;
	while (argv[2][b])
	{
		bit_change(c, argv[2][b++]);
	}
	return (0);
}
