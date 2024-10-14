#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_ARGS 100

void parse_command(char *input, char **args, char **redirect_file, int *append) {
    char *token;
    int i = 0;

    // Inicializa os valores de redirecionamento
    *redirect_file = NULL;
    *append = 0;

    // Divide a entrada em argumentos
    token = strtok(input, " \n");
    while (token != NULL && i < MAX_ARGS - 1) {
        // Verifica redirecionamento
        if (strcmp(token, ">>") == 0) {
            *append = 1; // Indicador para anexo
            token = strtok(NULL, " \n");
            if (token != NULL) {
                *redirect_file = token; // Nome do arquivo
            }
            break;
        } else if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " \n");
            if (token != NULL) {
                *redirect_file = token; // Nome do arquivo
            }
            break;
        } else {
            args[i++] = token; // Adiciona argumento
        }
        token = strtok(NULL, " \n");
    }
    args[i] = NULL; // Termina a lista de argumentos
}

void execute_command(char **args, char *redirect_file, int append) {
    pid_t pid = fork();
    
    if (pid == 0) { // Processo filho
        if (redirect_file != NULL) {
            int fd;
            if (append) {
                fd = open(redirect_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
            } else {
                fd = open(redirect_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            }
            if (fd == -1) {
                perror("Erro ao abrir o arquivo");
                exit(1);
            }
            dup2(fd, STDOUT_FILENO); // Redireciona saída padrão
            close(fd);
        }

        // Reorganiza args para garantir que as opções estão corretas
        int i;
        char *command[MAX_ARGS];
        int j = 0;

        for (i = 0; args[i] != NULL; i++) {
            if (strcmp(args[i], ">") == 0 || strcmp(args[i], ">>") == 0) {
                break; // Para evitar que as opções sejam movidas
            }
            command[j++] = args[i]; // Copia para o novo array
        }

        // Adiciona opções após o comando
        command[j] = NULL;

        execvp(command[0], command); // Executa o comando
        perror("Erro ao executar o comando"); // Se execvp falhar
        exit(1);
    } else if (pid < 0) {
        perror("Erro ao criar processo filho");
    } else {
        wait(NULL); // Espera o processo filho terminar
    }
}

int main() {
    char input[MAX_LINE];
    char *args[MAX_ARGS];
    char *redirect_file;
    int append;

    while (1) {
        printf("mini-shell> ");
        if (fgets(input, MAX_LINE, stdin) == NULL) {
            break; // Sai se houver erro ou EOF
        }

        parse_command(input, args, &redirect_file, &append);
        if (args[0] != NULL) {
            execute_command(args, redirect_file, append);
        }
    }

    return 0;
}
