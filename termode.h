#ifndef _TERMODE_H_
#define _TERMODE_H_

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#define NONBLOCKING_OFF 0
#define NONBLOCKING_ON 1

void termode_nonblocking(int mode) {
    if(mode != NONBLOCKING_OFF && mode != NONBLOCKING_ON) return;

    if(mode == NONBLOCKING_ON) {
        fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
    }

    if(mode == NONBLOCKING_OFF) {
        fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL, 0) &~ O_NONBLOCK);
    }
}

#endif
