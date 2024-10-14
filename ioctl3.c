/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioctl3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:25:36 by gkomba            #+#    #+#             */
/*   Updated: 2024/10/09 14:26:03 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
    int fd;
    long size;

    // Abre o dispositivo de bloco (disco)
    fd = open("/dev/sda", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Obtém o tamanho do disco
    if (ioctl(fd, BLKGETSIZE64, &size) == -1) {
        perror("ioctl");
        close(fd);
        return 1;
    }

    printf("Tamanho do disco: %ld bytes.\n", size);
    close(fd);
    return 0;
}