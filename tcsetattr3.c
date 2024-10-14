/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcsetattr3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:16:20 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 18:51:34 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios oldt, newt;
    char password[100];

    // Obtém os atributos atuais do terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Desativa o eco de entrada
    newt.c_lflag &= ~ECHO;

    // Aplica as novas configurações
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    printf("Digite sua senha: ");
    fgets(password, sizeof(password), stdin); // Lê a entrada do usuário
    printf("%s\n", password);
    // Restaura os atributos do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    printf("\nSenha recebida com sucesso!\n");

    return 0;
}
