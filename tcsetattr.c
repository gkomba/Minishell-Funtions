/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcsetattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:19:45 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 16:27:55 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main() {
    while(1)
    {
    struct termios oldt, newt;

    // Obtém os atributos atuais do terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Desativa o eco de entrada
    newt.c_lflag &= ~ECHO;

    // Aplica as novas configurações
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) != 0) {
        perror("tcsetattr");
        return 1;
    }

    printf("Digite algo (não será exibido): ");
    char input[100];
    fgets(input, sizeof(input), stdin); // Lê a entrada do usuário

    // Restaura os atributos do terminal
    if (tcsetattr(STDIN_FILENO, TCSANOW, &oldt) != 0) {
        perror("tcsetattr");
        return 1;
    }

    printf("\nVocê digitou: %s", input);
    }
    return 0;
}