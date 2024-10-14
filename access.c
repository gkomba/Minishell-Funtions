/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:03:47 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/11 08:03:50 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    const char *filename = "example.txt";

    // Verifica se o arquivo existe
    if (access(filename, F_OK) != -1) {
        printf("O arquivo %s existe.\n", filename);
        
        // Verifica se o arquivo pode ser lido
        if (access(filename, R_OK) == 0) {
            printf("O arquivo %s pode ser lido.\n", filename);
        } else {
            printf("O arquivo %s não pode ser lido.\n", filename);
        }
        
        // Verifica se o arquivo pode ser escrito
        if (access(filename, W_OK) == 0) {
            printf("O arquivo %s pode ser escrito.\n", filename);
        } else {
            printf("O arquivo %s não pode ser escrito.\n", filename);
        }

        // Verifica se o arquivo pode ser executado
        if (access(filename, X_OK) == 0) {
            printf("O arquivo %s pode ser executado.\n", filename);
        } else {
            printf("O arquivo %s não pode ser executado.\n", filename);
        }
    } else {
        printf("O arquivo %s não existe.\n", filename);
    }

    return 0;
}
