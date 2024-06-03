#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void lls() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("디렉토리를 열 수 없습니다");
        return;
    }

    struct dirent *entry;
    struct stat fileStat;
    long total_blocks = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            if (stat(entry->d_name, &fileStat) == -1) {
                continue;
            }
            total_blocks += fileStat.st_blocks;
        }
    }

    printf("total %ld\n", total_blocks / 2);

    rewinddir(dir);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            if (stat(entry->d_name, &fileStat) == -1) {
                continue;
            }
            printf("%-4ld %-8s ", fileStat.st_blocks / 2, entry->d_name);
        }
    }

    closedir(dir);
    printf("\n");
}

int main() {
    lls();
    return 0;
}

