#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int compare(const void *a, const void *b) {
    struct stat fileStatA, fileStatB;
    stat(*(const char **)a, &fileStatA);
    stat(*(const char **)b, &fileStatB);
    return fileStatB.st_mtime - fileStatA.st_mtime;
}

void lst() {
    struct dirent *entry;
    DIR *dp = opendir(".");
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    char *files[1024];
    int count = 0;

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        files[count++] = strdup(entry->d_name);
    }

    qsort(files, count, sizeof(char *), compare);

    for (int i = 0; i < count; i++) {
        printf("%-20s", files[i]);
        free(files[i]);
        if ((i + 1) % 5 == 0 || i == count - 1) printf("\n");
    }

    closedir(dp);
}

int main() {
    lst();
    return 0;
}


