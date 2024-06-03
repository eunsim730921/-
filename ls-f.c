#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void lsf() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("디렉토리를 열 수 없습니다");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\t", entry->d_name);
    }

    printf("\n");
    closedir(dir);
}

int main() {
    lsf();
    return 0;
}

