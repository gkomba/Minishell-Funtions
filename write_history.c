/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:03:42 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 18:03:48 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define HISTORY_FILE ".my_shell_history" // Nome do arquivo de histórico

int main() {
    char *input;

    // Lê o histórico do arquivo
    read_history(HISTORY_FILE);

    while (1) {
        input = readline("mini-shell> "); // Captura a entrada do usuário

        if (input == NULL) {
            break; // Sai se houver erro ou EOF
        }

        if (*input) {
            add_history(input); // Adiciona ao histórico
            write_history(HISTORY_FILE); // Salva o histórico no arquivo
        }

        // Processar a entrada (neste caso, apenas imprime)
        printf("Você digitou: %s\n", input);

        free(input); // Libera memória da entrada
    }

    // Salva o histórico ao sair
    write_history(HISTORY_FILE);

    return 0;
}
