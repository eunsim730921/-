#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "방법: %s <디렉토리 이름>\n", argv[0]);
        return 1;
    }
    const char *dir_name = argv[1];

    if (mkdir(dir_name, 0755) == -1) {
        perror("mkdir");
        return 1;
    }

    printf("디렉토리 '%s' 만듬.\n", dir_name);
    return 0;
}
