/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:45:57 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 13:46:05 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    char *terminal;

    terminal = ttyname(STDIN_FILENO);
    if (terminal != NULL) {
        printf("O terminal associado a stdin é: %s\n", terminal);
    } else {
        printf("stdin não está associado a um terminal.\n");
    }

    return 0;
}
