#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pty.h>
#include <utmp.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    int master_fd; // Descritor do terminal mestre
    pid_t pid; // Identificador do processo filho
    char slave_name[100];

    // Cria o pseudo-terminal
    master_fd = posix_openpt(O_RDWR);
    if (master_fd == -1) {
        perror("posix_openpt");
        exit(EXIT_FAILURE);
    }

    // Concede permissões ao terminal escravo
    if (grantpt(master_fd) == -1) {
        perror("grantpt");
        exit(EXIT_FAILURE);
    }

    // Desbloqueia o terminal escravo
    if (unlockpt(master_fd) == -1) {
        perror("unlockpt");
        exit(EXIT_FAILURE);
    }

    // Obtém o nome do dispositivo escravo
    if (ptsname_r(master_fd, slave_name, sizeof(slave_name)) != 0) {
        perror("ptsname_r");
        exit(EXIT_FAILURE);
    }

    // Cria um processo filho
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Processo filho
        // Abre o dispositivo escravo
        int slave_fd = open(slave_name, O_RDWR);
        if (slave_fd == -1) {
            perror("open slave");
            exit(EXIT_FAILURE);
        }

        // Redireciona a entrada e saída padrão para o escravo
        dup2(slave_fd, STDIN_FILENO);
        dup2(slave_fd, STDOUT_FILENO);
        dup2(slave_fd, STDERR_FILENO);
        close(slave_fd); // Fecha o descritor do escravo

        // Executa um shell (por exemplo, /bin/bash)
        execlp("bash", "bash", NULL);
        perror("execlp"); // Se falhar, imprime erro
        exit(EXIT_FAILURE);
    } else { // Processo pai
        // Fecha o descritor do escravo no pai
        close(master_fd);
        printf("Uma nova janela de terminal será aberta com o terminal escravo: %s\n", slave_name);
        
        // Abre uma nova janela de terminal usando o comando apropriado
        char command[256];
        snprintf(command, sizeof(command), "gnome-terminal -- bash -c 'cat %s; exec bash'", slave_name);
        system(command); // Executa o comando para abrir a nova janela de terminal

        // Espera o processo filho terminar
        wait(NULL);
    }

    return 0;
}