/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyslot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:49:11 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 13:49:16 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    int slot = ttyslot();

    if (slot > 0) {
        printf("Este processo está usando o terminal na posição %d no arquivo /etc/utmp.\n", slot);
    } else {
        printf("Nenhum terminal associado ou erro ao determinar o slot.\n");
    }

    return 0;
}
