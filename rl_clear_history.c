/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_clear_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:16:12 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 10:49:34 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <term.h>
#include <curses.h>

int main() {
    char *input;
     char *term_type = getenv("TERM");
    char buffer[2048];  // Buffer para armazenar as strings de controle
    char *area = buffer;

    // Loop para ler várias linhas até o usuário digitar "exit"
    while (1) {
        input = readline("Digite um comando: ");

        
        // Se o usuário digitar "clear", limpa o histórico
        if (input != NULL && strcmp(input, "clear") == 0) {
            rl_clear_history();
            
            printf("Histórico limpo!\n");
        }

        // Se o usuário digitar "exit", saímos do loop
        if (input == NULL || strcmp(input, "exit") == 0) {
            free(input);
            break;
        }


    }
        // Adiciona a entrada ao histórico
        if (input[0] != '\0') {
            add_history(input);
        }

        printf("Você digitou: %s\n", input);

        // Libera a memória alocada pela função readline
        free(input);

    return 0;
}
