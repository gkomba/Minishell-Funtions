/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:42:08 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 08:42:40 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
WIFEXITED é uma macro usada em conjunto com funções como wait(), waitpid(),
	wait3(), e wait4() para verificar se um processo filho terminou normalmente,
	ou seja, se ele terminou sem ser interrompido por um sinal.
*/
int	main(void)
{
			int status;

	pid_t pid1, pid2;
	// Cria o primeiro processo filho
	pid1 = fork();
	if (pid1 == 0)
	{
		// Processo filho 1
		printf("Processo filho 1 executando...\n");
		sleep(2); // Simula algum trabalho
		printf("Processo filho 1 terminando...\n");
		return (10); // Retorna 10 como código de saída
	}
	else if (pid1 > 0)
	{
		// Cria o segundo processo filho
		pid2 = fork();
		if (pid2 == 0)
		{
			// Processo filho 2
			printf("Processo filho 2 executando...\n");
			sleep(4); // Simula algum trabalho
			printf("Processo filho 2 terminando...\n");
			return (20); // Retorna 20 como código de saída
		}
		else if (pid2 > 0)
		{
			// Processo pai
			// Espera o processo filho 1 terminar
			waitpid(pid1, &status, 0);
			if (WIFEXITED(status))
			{
				printf("Processo filho 1 terminou com código de saída %d\n",
					WEXITSTATUS(status));
			}
			// Espera o processo filho 2 terminar
			waitpid(pid2, &status, 0);
			if (WIFEXITED(status))
			{
				printf("Processo filho 2 terminou com código de saída %d\n",
					WEXITSTATUS(status));
			}
		}
		else
		{
			perror("Erro ao criar o processo filho 2");
		}
	}
	else
	{
		perror("Erro ao criar o processo filho 1");
	}
	return (0);
}
