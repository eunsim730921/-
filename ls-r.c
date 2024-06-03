#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

void lsr() {
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
        printf("%s ", files[i]);
        free(files[i]);
    }
    printf("\n");

    closedir(dp);
}

int main() {
    lsr();
    return 0;
}

