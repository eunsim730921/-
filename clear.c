#include <stdio.h>

void clear() {
    printf("\033[2J\033[H");
}

int main() {
    clear();
    return 0;
}

