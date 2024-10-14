/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:35:51 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 08:37:42 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t pid = fork(); // Cria um processo filho

	if (pid == 0)
	{
		// Processo filho
		printf("Sou o processo filho. PID = %d\n", getpid());
	}
	else if (pid > 0)
	{
		// Processo pai
		printf("Sou o processo pai. PID = %d\n", getpid());
	}
	else
	{
		// Caso de erro
		perror("Erro no fork");
	}

	return (0);
}