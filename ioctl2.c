/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioctl2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:23:00 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 14:23:03 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
    int fd;
    struct ifreq ifr;

    // Cria um socket para se comunicar com a interface de rede
    fd = socket(AF_INET, SOCK_DGRAM, 0);

    // Copia o nome da interface de rede, por exemplo "eth0"
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ);

    // Obtém as flags da interface
    ioctl(fd, SIOCGIFFLAGS, &ifr);

    // Define a flag IFF_UP para ativar a interface
    ifr.ifr_flags |= IFF_UP;

    // Aplica as flags modificadas de volta à interface
    ioctl(fd, SIOCSIFFLAGS, &ifr);

    close(fd);
    return 0;
}