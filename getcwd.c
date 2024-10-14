/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:21:22 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/12 13:21:25 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h> // Para definir o tamanho máximo do caminho

int main() {
    char cwd[PATH_MAX]; // Define o buffer para armazenar o diretório

    // Obtém o diretório de trabalho atual
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Diretório de trabalho atual: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }

    return 0;
}
