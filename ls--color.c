#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void lsc() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("디렉토리를 열 수 없습니다");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            struct stat fileStat;
            if (stat(entry->d_name, &fileStat) == -1) {
                perror("파일 정보를 가져올 수 없습니다");
                continue;
            }

            char *colorCode = (S_ISDIR(fileStat.st_mode)) ? "\x1B[34m" :
                              ((fileStat.st_mode & S_IXUSR) ? "\x1B[32m" : "");
            printf("%s%-s\x1B[0m ", colorCode, entry->d_name);
        }
    }
    printf("\n");

    closedir(dir);
}

int main() {
    lsc();
    return 0;
}

