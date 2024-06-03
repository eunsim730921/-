#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void listFilesWithType() {
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
        
        printf("%s", entry->d_name);
        if (S_ISDIR(fileStat.st_mode)) {
            printf("/");
        } else if (fileStat.st_mode & S_IXUSR) {
            printf("*");
        }
        printf("\t");
    }

    printf("\n");
    closedir(dir);
}

int main() {
    listFilesWithType();
    return 0;
}

