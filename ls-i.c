#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void lsi() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("디렉토리를 열 수 없습니다");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        struct stat fileStat;
        if (stat(entry->d_name, &fileStat) == -1) {
            perror("파일 정보를 가져올 수 없습니다");
            continue;
        }
        printf("%llu %s\t", (unsigned long long)fileStat.st_ino, entry->d_name);
    }

    printf("\n");
    closedir(dir);
}

int main() {
    lsi();
    return 0;
}

