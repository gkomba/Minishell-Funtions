/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcsetattr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:54:49 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 16:56:35 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

void set_raw_mode(struct termios *oldt) {
    struct termios newt;
    // Obtém os atributos atuais do terminal
    tcgetattr(STDIN_FILENO, oldt);
    newt = *oldt;

    // Ativa o modo raw
    newt.c_lflag &= ~(ECHO | ICANON); // Desativa eco e modo canônico
    newt.c_cc[VMIN] = 1; // Lê um caractere
    newt.c_cc[VTIME] = 0; // Sem timeout

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void restore_mode(struct termios *oldt) {
    // Restaura os atributos do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, oldt);
}

int main() {
    struct termios oldt;

    set_raw_mode(&oldt);

    printf("Pressione as setas do teclado (ESC para sair):\n");
    while (1) {
        char c;
        read(STDIN_FILENO, &c, 1); // Lê um caractere

        if (c == 27) { // ESC
            break;
        } else if (c == '\033') { // Se o primeiro byte é '\033'
            read(STDIN_FILENO, &c, 1); // Lê o próximo byte
            if (c == '[') {
                read(STDIN_FILENO, &c, 1); // Lê o próximo byte
                switch (c) {
                    case 'A':
                        printf("Seta para cima pressionada.\n");
                        break;
                    case 'B':
                        printf("Seta para baixo pressionada.\n");
                        break;
                    case 'C':
                        printf("Seta para a direita pressionada.\n");
                        break;
                    case 'D':
                        printf("Seta para a esquerda pressionada.\n");
                        break;
                }
            }
        }
    }

    restore_mode(&oldt);
    printf("Saindo...\n");

    return 0;
}