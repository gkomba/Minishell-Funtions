/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_autocmplt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:02:03 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 11:02:48 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <math.h>

// Lista de comandos válidos
const char *valid_commands[] = {
    "cd",
    "ls",
    "exit",
    "clear",
    "history",
    "pwd",
    "mkdir",
    "rmdir",
    "touch",
    "rm"
};

// Função para calcular a distância de Levenshtein entre duas strings
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else {
                int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
                matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1,    // Inserção
                                         matrix[i][j - 1] + 1),   // Remoção
                                         matrix[i - 1][j - 1] + cost);  // Substituição
            }
        }
    }
    
    return matrix[len1][len2];
}

// Função para encontrar o comando mais próximo com base na distância de Levenshtein
const char* find_closest_command(const char *input) {
    int closest_distance = 9999;
    const char *closest_command = NULL;
    
    for (int i = 0; i < sizeof(valid_commands) / sizeof(valid_commands[0]); i++) {
        int distance = levenshtein(input, valid_commands[i]);
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_command = valid_commands[i];
        }
    }
    
    return closest_command;
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
        
        // Adiciona o comando ao histórico
        if (input[0] != '\0') {
            add_history(input);
        }

        // Compara o comando com a lista de comandos válidos
        const char *closest_command = find_closest_command(input);

        if (strcmp(input, closest_command) != 0) {
            // Se o comando não corresponder, sugere a correção
            printf("Comando não encontrado: '%s'. Você quis dizer '%s'?\n", input, closest_command);
            strcpy(input, closest_command);  // Aplica a correção automática
        }

        // Comando para sair
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Aqui você pode adicionar a lógica para lidar com o comando corrigido
        printf("Executando: %s\n", input);

        // Libera a memória alocada pela função readline
        free(input);
    }

    return 0;
}