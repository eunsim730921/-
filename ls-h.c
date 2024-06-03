#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <math.h>

void formatSize(long size, char *formattedSize) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unitIndex = 0;
    double formatted = size;

    while (formatted >= 1024 && unitIndex < 4) {
        formatted /= 1024;
        unitIndex++;
    }

    sprintf(formattedSize, "%.1f %s", formatted, units[unitIndex]);
}

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("디렉토리를 열 수 없습니다");
        return 1;
    }

    struct dirent *entry;
    int count = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            struct stat fileStat;
            char formattedSize[20];

            if (stat(entry->d_name, &fileStat) == -1) {
                perror("파일 정보를 가져올 수 없습니다");
                return 1;
            }

            formatSize(fileStat.st_size, formattedSize);
            printf("%-30s", entry->d_name);
            count++;
            if (count % 4 == 0) {
                printf("\n");
            }
        }
    }

    if (count % 4 != 0) {
        printf("\n");
    }

    closedir(dir);
    return 0;
}

