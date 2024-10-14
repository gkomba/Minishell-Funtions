/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:58:33 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/10 17:59:31 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*input;

	while (1)
	{
		// Captura a entrada do usuário
		input = readline("mini-shell> ");
		// Verifica se a entrada não é nula
		if (input == NULL)
		{
			break ; // Sai se houver erro ou EOF
		}
		// Adiciona a entrada ao histórico
		if (*input)
		{
			add_history(input); // Adiciona ao histórico
		}
		// Processar a entrada (neste caso, apenas imprime)
		printf("Você digitou: %s\n", input);
		free(input); // Libera memória da entrada
	}
	return (0);
}
