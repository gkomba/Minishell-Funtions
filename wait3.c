/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:46:51 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 08:49:07 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Processo filho
        printf("Processo filho executando...\n");
        sleep(22); // Simula alguma tarefa
        printf("Processo filho terminando...\n");
        return 0;
    } else {
        // Processo pai
        int status;
        struct rusage usage;
        wait3(&status, 0, &usage); // Aguarda e coleta o uso de recursos
        printf("Processo filho terminou. Tempo de usuário: %ld segundos\n", usage.ru_utime.tv_sec);
    }

    return 0;
}
