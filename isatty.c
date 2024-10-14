/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isatty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:07:34 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 13:08:27 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main()
{
    if (isatty(STDOUT_FILENO))
    {
        printf("A saída está sendo exibida em um terminal.\n");
    }
    else
    {
        printf("A saída NÃO está sendo exibida em um terminal.\n");
    }
    return 0;
}
