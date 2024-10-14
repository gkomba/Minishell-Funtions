/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:49:22 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 08:50:07 by gkomba           ###   ########.fr       */
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
        sleep(3); // Simula alguma tarefa
        printf("Processo filho terminando...\n");
        return 0;
    } else {
        // Processo pai
        int status;
        struct rusage usage;
        wait4(pid, &status, 0, &usage); // Espera e coleta o uso de recursos
        printf("Processo filho terminou. Memória máxima usada: %ld KB\n", usage.ru_maxrss);
    }

    return 0;
}
