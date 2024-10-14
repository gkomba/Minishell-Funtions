/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:26:18 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 15:44:07 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// Obtém o valor da variável de ambiente HOME
	char *home = getenv("HOME");

	// Verifica se a variável está definida
	if (home != NULL)
	{
		printf("O diretório HOME é: %s\n", home);
	}
	else
	{
		printf("A variável de ambiente HOME não está definida.\n");
	}
	return (0);
}