#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR* dir = opendir(".");
    if (!dir) {
        perror("디렉토리를 열 수 없습니다");
        return 1;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\t", entry->d_name);
    }
    printf("\n");

    closedir(dir);
    return 0;
}

