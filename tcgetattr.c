#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void set_raw_mode(struct termios *oldt) {
    struct termios newt;
    tcgetattr(STDIN_FILENO, oldt); // Obtém os atributos atuais do terminal
    newt = *oldt;

    // Desativa o modo canônico e o eco, para capturar teclas diretamente
    newt.c_lflag &= ~(ICANON | ECHO);

    // Aplicamos as configurações imediatamente
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void restore_mode(struct termios *oldt) {
    tcsetattr(STDIN_FILENO, TCSANOW, oldt); // Restaura as configurações antigas
}

int main() {
    struct termios oldt;
    char c;

    set_raw_mode(&oldt); // Configura o terminal em modo raw

    printf("Pressione Ctrl+C ou Ctrl+D para capturar (Ctrl+C para sair).\n");

    while (1) {
        read(STDIN_FILENO, &c, 1); // Lê um caractere por vez

        // Verifica se Ctrl+C (ASCII 3) foi pressionado
        if (c == 3) { 
            printf("\nCtrl+C Capturado (ASCII 3)\n");
            break; // Sai do loop
        }

        // Verifica se Ctrl+D (ASCII 4) foi pressionado
        if (c == 4) { 
            printf("\nCtrl+D Capturado (ASCII 4)\n");
            continue; // Continua a execução
        }

        // Caso outro caractere seja pressionado, exibe o caractere e seu valor ASCII
        printf("Você pressionou: '%c' (ASCII: %d)\n", c, c);
    }

    restore_mode(&oldt); // Restaura o modo normal do terminal
    printf("Saindo...\n");
    return 0;
}
