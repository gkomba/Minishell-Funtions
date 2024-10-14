/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:48:51 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 08:48:56 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    // Loop infinito para ler várias linhas até o usuário digitar "exit"
    while (1) {
        // Exibe o prompt e lê a entrada do usuário
        input = readline("Digite um comando: ");

        // Se o usuário digitar "exit", saímos do loop
        if (input == NULL || strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Adiciona o comando ao histórico (se não estiver vazio)
        if (input[0] != '\0') {
            add_history(input);
        }

        // Exibe o que o usuário digitou
        printf("Você digitou: %s\n", input);

        // Libera a memória alocada pela função readline
        free(input);
    }

    return 0;
}