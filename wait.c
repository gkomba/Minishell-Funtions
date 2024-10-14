/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:38:06 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 08:38:49 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		// Processo filho
        printf("Sou o processo filho. PID = %d\n", getpid());
		printf("Processo filho executando...\n");
		sleep(2); // Simula alguma tarefa
		printf("Processo filho terminando...\n");
		return (0);
	}
	else
	{
		// Processo pai
		wait(&status); // Aguarda o término do filho
        printf("Sou o processo pai. PID = %d\n", getpid());
		printf("Processo filho terminou com status %d\n", status);
	}
	return (0);
}
