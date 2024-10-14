/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_new_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:09:54 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 11:09:56 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    while (1) {
        // Lê a entrada do usuário
        input = readline("minishell> ");

        // Se a entrada for nula (Ctrl+D), encerra o shell
        if (input == NULL) {
            printf("\nSaindo...\n");
            break;
        }

        // Se a linha de entrada estiver vazia, ignore
        if (input[0] == '\0') {
            free(input);
            continue;
        }

        // Adiciona o comando ao histórico
        add_history(input);

        // Processa o comando
        if (strcmp(input, "clear") == 0) {
            // Limpa a tela e move o cursor para uma nova linha
            printf("\033[H\033[J"); // Sequência de escape ANSI para limpar a tela
            rl_on_new_line(); // Indica que o cursor está em uma nova linha
            continue;
        }

        // Comando para sair
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Simula a execução do comando
        printf("Executando: %s\n", input);

        // Libera a memória alocada pela função readline
        free(input);
    }

    return 0;
}
