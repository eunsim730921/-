#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void lsn() {
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

            printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
            printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
            printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
            printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
            printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
            printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
            printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
            printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
            printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
            printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

            printf(" %ld", fileStat.st_nlink);
            printf(" %d", fileStat.st_uid);
            printf(" %d", fileStat.st_gid);
            printf(" %5ld", fileStat.st_size);

            char timeBuf[80];
            struct tm *timeinfo = localtime(&fileStat.st_mtime);
            strftime(timeBuf, sizeof(timeBuf), "%b %d %H:%M", timeinfo);
            printf(" %s", timeBuf);

            printf(" %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    lsn();
    return 0;
}


