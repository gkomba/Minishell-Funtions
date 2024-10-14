/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_replace_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:03:10 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 17:50:34 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

void correct_input(char *input) {
    // Exemplo de correção: substitui "erro" por "correto"
    if (strstr(input, "ls >> file -l")) {
        rl_replace_line("ls -l >> file", 1); // Substitui a linha e limpa o histórico
        rl_redisplay(); // Redesenha a linha com a nova entrada
    }
}

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

        // Chama a função para corrigir a entrada se necessário
        correct_input(input);

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
