#ifndef _TERMODE_H_
#define _TERMODE_H_

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#define NONBLOCKING_OFF 0
#define NONBLOCKING_ON 1

#define CANONICAL_OFF 0
#define CANONICAL_ON 1

struct termios new_term, old_term;

void termode_nonblocking(int mode) {
    if(mode != NONBLOCKING_OFF && mode != NONBLOCKING_ON) return;

    if(mode == NONBLOCKING_ON) {
        fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
    }

    if(mode == NONBLOCKING_OFF) {
        fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL, 0) &~ O_NONBLOCK);
    }
}

void termode_canonical(int mode) {
    if(mode != CANONICAL_ON && mode != CANONICAL_OFF) return;

    if(mode == CANONICAL_ON) {
        tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
    }

    if(mode == CANONICAL_OFF) {
        tcgetattr(STDIN_FILENO, &old_term);

        new_term = old_term;
        new_term.c_lflag &= ~(ICANON);
        new_term.c_cc[VMIN] = 0;
        new_term.c_cc[VTIME] = 0;

        tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
    }
}

#endif
