/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:58:37 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 19:01:16 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <term.h>

int main() {
    char *term_type = getenv("TERM");
    
    if (tgetent(NULL, term_type) != 1) {
        printf("Erro ao carregar o banco de dados termcap.\n");
        return 1;
    }
    // Verifica se o terminal suporta a capacidade de mover o cursor (flag "bs" para "backspace").
    if (tgetflag("bs")) {
        printf("O terminal suporta a tecla Backspace.\n");
    } else {
        printf("O terminal não suporta a tecla Backspace.\n");
    }

    return 0;
}
