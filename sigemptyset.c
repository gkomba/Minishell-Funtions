/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigemptyset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:37:16 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 10:40:49 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig) {
    printf("Caught SIGUSR1 (signal %d)\n", sig);
}

int main() {
    struct sigaction sa;
    sigset_t set;

    // Inicializa a máscara de sinais
    sigemptyset(&set);  // Conjunto vazio

    // Configura o manipulador de sinal
    sa.sa_handler = handle_sigusr1;
    sa.sa_mask = set;   // Define a máscara de sinais (vazio neste caso)
    sa.sa_flags = 0;

    // Define a ação para SIGUSR1
    sigaction(SIGUSR1, &sa, NULL);

    printf("Waiting for SIGUSR1... (pid: %d)\n", getpid());

    // Loop infinito aguardando sinais
    // kill -SIGUSR1 PID
    while (1) {
        pause();  // Espera até que um sinal seja recebido
    }

    return 0;
}
