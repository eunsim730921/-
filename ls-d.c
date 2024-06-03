#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void lsd() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("디렉토리를 열 수 없습니다");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    lsd();
    return 0;
}

