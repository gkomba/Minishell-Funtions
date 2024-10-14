/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:04:47 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 09:06:20 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    // Configura o sinal SIGINT para ser tratado pela função handle_sigint
    signal(SIGINT, handle_sigint);
    
    while (1) {
        printf("Running... Press Ctrl+C to send SIGINT\n");
        printf("Running... Press Ctrl+Z to exit\n");
        sleep(1);  // Aguarda um segundo
    }

    return 0;
}
