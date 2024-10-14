/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:03:43 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 19:08:51 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main() {
    char *term_type = getenv("TERM");

    if (term_type == NULL) {
        printf("Erro: a variável de ambiente TERM não está definida.\n");
        return 1;
    }

    if (tgetent(NULL, term_type) != 1) {
        printf("Erro ao carregar o banco de dados termcap.\n");
        return 1;
    }

    // int cols = tgetnum("co");  
    // int lines = tgetnum("li");

    if (tgetnum("li") == -1 || tgetnum("co") == -1) {
        printf("Não foi possível obter as dimensões do terminal.\n");
    } else {
        printf("O terminal tem %d linhas e %d colunas.\n", tgetnum("li"), tgetnum("co"));
    }

    return 0;
}
