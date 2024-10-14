/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:27:02 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/12 13:27:26 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

int main() {
    char cwd[PATH_MAX]; // Buffer para armazenar o diretório atual

    // Obtém e exibe o diretório de trabalho atual
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Diretório de trabalho atual: %s\n", cwd);
    } else {
        perror("Erro ao obter o diretório de trabalho atual");
    }

    // Altera o diretório de trabalho atual
    const char *new_dir = "..";
    if (chdir(new_dir) == 0) {
        printf("Diretório de trabalho alterado para: %s\n", new_dir);
    } else {
        perror("Erro ao alterar o diretório de trabalho");
    }

    // Obtém e exibe o novo diretório de trabalho
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Novo diretório de trabalho: %s\n", cwd);
    } else {
        perror("Erro ao obter o novo diretório de trabalho");
    }

    return 0;
}
