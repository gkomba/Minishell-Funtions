/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:10:15 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 11:59:04 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>  // Necessário para usar tputs e outros

int main() {
    char *term_type = getenv("TERM");
    char buffer[2048];  // Buffer para armazenar as strings de controle
    char *area = buffer;

    if (term_type == NULL) {
        printf("Erro: a variável de ambiente TERM não está definida.\n");
        return 1;
    }

    // Inicializa o banco de dados termcap
    if (tgetent(NULL, term_type) != 1) {
        printf("Erro ao carregar o banco de dados termcap.\n");
        return 1;
    }

    // Obtém a string para limpar a tela
    char *clear_scree = tgetstr("ve", &area);  // "cl" é o código para limpar a tela
    if (clear_scree == NULL) {
        printf("Capacidade de limpar a tela não disponível.\n");
        return 1;
    }

    // Obtém a string para mover o cursor para o canto superior esquerdo
    char *home_cursor = tgetstr("md", &area);  // "ho" é o código para mover o cursor para "home"
    if (home_cursor == NULL) {
        printf("Capacidade de mover o cursor para o início não disponível.\n");
        return 1;
    }

    // Usa tputs para enviar as sequências de controle para o terminal
    tputs(clear_scree, 1, putchar);  // Limpa a tela
    tputs(home_cursor, 1, putchar);   // Move o cursor para o canto superior esquerdo

    //printf("Tela limpa e cursor movido para o canto superior esquerdo.\n");

    return 0;
}
