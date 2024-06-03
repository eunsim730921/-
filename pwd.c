#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char pwd[1024];
    if (getcwd(pwd, sizeof(pwd)) != NULL) {
        printf("%s\n", pwd);
    } else {
        perror("getcwd() error");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

