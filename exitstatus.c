/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitstatus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:45:22 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 08:45:24 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Processo filho
        printf("Processo filho executando...\n");
        sleep(2); // Simula alguma tarefa
        return 42; // Retorna 42 como código de saída
    } else if (pid > 0) {
        // Processo pai
        int status;
        wait(&status); // Espera o processo filho terminar

        if (WIFEXITED(status)) {
            // Verifica se o processo terminou normalmente
            int exit_code = WEXITSTATUS(status); // Obtém o código de saída
            printf("Processo filho terminou normalmente com código de saída: %d\n", exit_code);
        } else {
            printf("Processo filho não terminou normalmente\n");
        }
    } else {
        perror("Erro no fork");
    }

    return 0;
}
