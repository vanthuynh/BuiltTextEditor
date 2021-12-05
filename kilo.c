#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios; // store orginal terminal attributes in here

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode); // register disableRawMode() to be called automatically

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON); // ICANON flag that turn off canonical mode

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}