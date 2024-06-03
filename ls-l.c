#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

void printFileInfo(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) == -1) {
        perror("파일 정보를 가져올 수 없습니다");
        return;
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
    printf((fileStat.st_mode & S_IXOTH) ? "x " : "- ");

    printf("%ld ", (long)fileStat.st_nlink);
    struct passwd *pw = getpwuid(fileStat.st_uid);
    printf("%s ", pw->pw_name);
    struct group *gr = getgrgid(fileStat.st_gid);
    printf("%s ", gr->gr_name);
    printf("%ld ", (long)fileStat.st_size);
    char timebuf[80];
    strftime(timebuf, sizeof(timebuf), "%b %e %R", localtime(&fileStat.st_mtime));
    printf("%s ", timebuf);
    printf("%s\n", filename);
}
int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("디렉토리를 열 수 없습니다");
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            printFileInfo(entry->d_name);
        }
    }
    closedir(dir);
    return 0;
}

