/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:18:10 by omadali           #+#    #+#             */
/*   Updated: 2024/12/13 04:30:49 by omadali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void signal_hand(int signal)
{
    if (signal == SIGUSR1)
        printf("sigusr1 alındı\n");
    else if(signal == SIGUSR2)
        printf("sigusr2 alındı \n");
}

int main()
{
    signal(SIGUSR1, signal_hand);
    signal(SIGUSR2,signal_hand);
    printf("PID: %d\n", getpid());
    while(1)
    {
        pause();
    }
    return (0);
}