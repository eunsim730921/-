#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct {
    char name[256];
    off_t size;
} FileInfo;

int compare(const void *a, const void *b) {
    FileInfo *fileA = (FileInfo *)a;
    FileInfo *fileB = (FileInfo *)b;
    return (fileB->size - fileA->size);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    FileInfo *files = NULL;
    int count = 0, capacity = 10;

    files = (FileInfo *)malloc(sizeof(FileInfo) * capacity);
    if (!files) {
        perror("Failed to allocate memory");
        return 1;
    }

    dir = opendir(".");
    if (!dir) {
        perror("Cannot open directory");
        free(files);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &statbuf) == -1) {
            perror("Cannot get file information");
            continue;
        }

        if (count >= capacity) {
            capacity *= 2;
            files = (FileInfo *)realloc(files, sizeof(FileInfo) * capacity);
            if (!files) {
                perror("Failed to reallocate memory");
                closedir(dir);
                return 1;
            }
        }

        strcpy(files[count].name, entry->d_name);
        files[count].size = statbuf.st_size;
        count++;
    }
    closedir(dir);

    qsort(files, count, sizeof(FileInfo), compare);

    for (int i = 0; i < count; i++) {
        printf("%s ", files[i].name);
    }
    printf("\n");

    free(files);

    return 0;
}

