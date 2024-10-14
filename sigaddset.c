/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaddset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:55:51 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/12 12:59:45 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigterm(int sig) {
    printf("Caught SIGTERM (signal %d)\n", sig);
    // Aqui você pode realizar tarefas de limpeza
}

int main() {
    struct sigaction sa;
    sigset_t set;

    // Inicializa o conjunto de sinais
    sigemptyset(&set);  // Começa com um conjunto vazio

    // Adiciona SIGTERM ao conjunto
    sigaddset(&set, SIGTERM);
    sigaddset(&set, SIGINT);

    // Configura a ação para SIGTERM
    sa.sa_handler = handle_sigterm;
    sa.sa_mask = set;   // Define a máscara de sinais que serão bloqueados
    sa.sa_flags = 0;

    // Define a ação para SIGTERM
    sigaction(SIGTERM, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);

    printf("Waiting for SIGTERM... (pid: %d)\n", getpid());

    // Loop infinito aguardando sinais
    while (1) {
        pause();  // Espera até que um sinal seja recebido
    }

    return 0;
}
