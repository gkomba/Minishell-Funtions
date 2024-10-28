A função isatty em C é utilizada para verificar se um descritor de arquivo refere-se a um terminal (TTY) ou não. Essa função é útil para determinar se a saída de um programa está sendo redirecionada (por exemplo, para um arquivo ou um pipe) ou se está sendo exibida em um terminal.

Prototipo
c
Copy code
#include <unistd.h>

int isatty(int fd);
Parâmetros
fd: O descritor de arquivo que você deseja verificar. Normalmente, 0 (stdin), 1 (stdout) ou 2 (stderr).
Retorno
Retorna um valor diferente de zero (true) se o descritor de arquivo refere-se a um terminal.
Retorna zero (false) se não se refere a um terminal.
Exemplo de Uso: isatty.c

A função ttyname em C é usada para obter o nome do dispositivo de terminal associado a um descritor de arquivo (file descriptor). Isso é útil para identificar o terminal específico ao qual um processo está conectado, especialmente em sistemas com múltiplos terminais (como servidores ou shells).

Protótipo
c
Copy code
#include <unistd.h>

char *ttyname(int fd);
Parâmetros
fd: O descritor de arquivo que você quer verificar. Normalmente, pode ser:
STDIN_FILENO (0) — Entrada padrão
STDOUT_FILENO (1) — Saída padrão
STDERR_FILENO (2) — Saída de erro padrão
Retorno
Retorna um ponteiro para uma string que contém o nome do dispositivo de terminal associado ao descritor de arquivo.
Retorna NULL se o descritor de arquivo não estiver associado a um terminal ou se houver um erro.

Exemplo: ttyname.c

Quando Usar
Diagnóstico e Depuração: Saber exatamente a que terminal um processo está conectado pode ser útil para fins de diagnóstico, especialmente ao trabalhar com múltiplos terminais ou shells.
Programas Interativos: Em programas que envolvem entrada/saída interativa com o usuário, a função ttyname pode ser usada para identificar o terminal que está sendo usado, o que pode ser útil para registrar logs ou mensagens.
Aplicações Multi-terminal: Se você estiver criando uma aplicação que interage com múltiplos terminais ao mesmo tempo (por exemplo, multiplexadores de terminal como tmux), ttyname ajuda a identificar a conexão.

A função ttyslot em C é usada para determinar o número de slot de terminal associado ao processo atual no arquivo /etc/utmp, que contém informações sobre usuários logados no sistema. Ela retorna o índice da entrada do terminal no arquivo utmp, que é utilizado para rastrear sessões de usuários.

Protótipo
c
Copy code
#include <unistd.h>

int ttyslot(void);
Descrição
ttyslot retorna o número da entrada do terminal do processo atual no arquivo /etc/utmp.
O arquivo utmp armazena informações sobre logins ativos, como nome do usuário, terminal associado e tempo de login. É usado por ferramentas como who e w.
Retorno
Retorna um número inteiro representando o "slot" ou o índice da entrada no arquivo utmp correspondente ao terminal do processo atual.
Retorna 0 se não houver terminal associado ou se o slot não puder ser encontrado.
Exemplo de Uso: ttyslot.c

A função ioctl (Input/Output Control) em C é uma função poderosa que permite que programas interajam diretamente com dispositivos de hardware ou drivers. Ela envia comandos de controle para dispositivos (como terminais, discos, interfaces de rede, etc.) que não podem ser realizados usando funções comuns de leitura/escrita, proporcionando uma interface de comunicação entre o software e o hardware.

Protótipo
c
Copy code
#include <sys/ioctl.h>

int ioctl(int fd, unsigned long request, ...);
Parâmetros
fd: O descritor de arquivo do dispositivo ao qual você quer enviar o comando de controle. Por exemplo, pode ser um terminal (/dev/tty), uma interface de rede, um driver de dispositivo, etc.
request: O código que representa a operação ou comando específico que será executado no dispositivo. Há uma lista de comandos padrões disponíveis, mas alguns dispositivos podem ter seus próprios comandos específicos.
...: Parâmetros opcionais que podem ser passados dependendo do comando (request).
Retorno
Retorna 0 se a operação for bem-sucedida.
Retorna -1 se houver erro, e errno é configurado para indicar o erro específico.
Comandos Comuns
Aqui estão alguns exemplos de comandos comuns que podem ser usados com ioctl:

Comandos de terminal:

TIOCGWINSZ: Obtém o tamanho da janela do terminal.
TIOCSWINSZ: Define o tamanho da janela do terminal.
Comandos de rede:

SIOCGIFADDR: Obtém o endereço IP associado a uma interface de rede.
SIOCSIFFLAGS: Define flags em uma interface de rede (por exemplo, ativar ou desativar).
Dispositivos personalizados:

Drivers de dispositivos podem definir seus próprios comandos de controle específicos, comumente usados em drivers de dispositivos personalizados.

Exemplo de uso: ioctl.c

A função tcsetattr é usada em C para configurar os atributos de um terminal. Ela é parte da biblioteca de controle de terminal do POSIX, que permite que programas interajam com terminais de forma mais granular. Com tcsetattr, você pode modificar características como modos de entrada e saída, tempo de espera e comportamentos de controle.

Protótipo
c
Copy code
#include <termios.h>

int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
Parâmetros
fd: O descritor de arquivo do terminal que você deseja configurar. Geralmente, isso pode ser STDIN_FILENO (entrada padrão), STDOUT_FILENO (saída padrão) ou um descritor de arquivo obtido com open() em um dispositivo de terminal.
optional_actions: Um valor que controla como a mudança será aplicada. Os valores podem ser:
TCSANOW: A mudança é aplicada imediatamente.
TCSADRAIN: A mudança é aplicada após todos os dados que estão sendo transmitidos terem sido enviados.
TCSAFLUSH: A mudança é aplicada imediatamente, e todos os dados não transmitidos são descartados.
termios_p: Um ponteiro para uma estrutura termios, que contém os novos atributos do terminal que você deseja definir.
Estrutura termios
A estrutura termios é utilizada para definir os atributos do terminal e contém vários campos, incluindo:

c_iflag: Máscara de entrada (flags de entrada).
c_oflag: Máscara de saída (flags de saída).
c_cflag: Máscara de controle (flags de controle).
c_lflag: Máscara de linha (flags de linha).
c_cc: Array que contém caracteres especiais, como caracteres de controle (e.g., EOL, BRK, INTR).

Exemplo de uso: tcsetattr.c

A função tcgetattr é usada em C para obter os atributos atuais de um terminal. Esses atributos são representados pela estrutura termios, que contém diversas configurações sobre o comportamento do terminal, como o modo de entrada, modo de saída, controles de fluxo, etc.

Essa função é frequentemente usada quando você deseja alterar as configurações de um terminal (por exemplo, desativar o eco de entrada ou modificar como caracteres são processados). Antes de fazer alterações, você usa tcgetattr para salvar o estado atual do terminal, para que ele possa ser restaurado mais tarde.

Protótipo
c
Copy code
#include <termios.h>
#include <unistd.h>

int tcgetattr(int fd, struct termios *termios_p);
Parâmetros
fd: O descritor de arquivo do terminal. Normalmente, você usa STDIN_FILENO (descritor de entrada padrão), STDOUT_FILENO (descritor de saída padrão) ou um descritor de arquivo obtido com open() em um dispositivo de terminal.
termios_p: Um ponteiro para uma.
