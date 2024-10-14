/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:36:09 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 10:36:11 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

// Manipulador de sinal para SIGINT
void handle_sigint(int sig) {
    printf("Recebido SIGINT! (Pressione Ctrl+C)\n");
}

int main() {
    struct sigaction sa;

    // Configura o manipulador de sinal
    sa.sa_handler = handle_sigint; // Define o manipulador
    sigemptyset(&sa.sa_mask);       // Limpa o conjunto de sinais bloqueados
    sa.sa_flags = 0;                 // Nenhuma flag especial

    // Configura a ação para o sinal SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Aperte Ctrl+C para enviar SIGINT...\n");

    // Loop infinito aguardando sinais
    while (1) {
        pause(); // Espera por sinais
    }

    return 0;
}
