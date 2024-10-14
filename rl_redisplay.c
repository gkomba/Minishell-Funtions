/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_redisplay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:24:09 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 10:56:27 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdlib.h> 

int main() {
    char *input;

    // Inicializa readline com um prompt
while(1)
{
    input = readline("b2broot> ");

    if (input != NULL)
    {
        add_history(input);

        // Simula uma alteração na linha de comando
       // strcpy(rl_line_buffer, "Comando modificado!");
        
        // Força o redesenho do prompt com a nova linha
    printf("%s\n", input);
    }
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
    rl_redisplay();
    return 0;
}
