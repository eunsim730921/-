#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINE_COUNT 5

void head(FILE *file, int line_count) {
    char buffer[1024];
    while (line_count > 0 && fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
        line_count--;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "방법: %s <파일 이르,ㅁ>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("실패");
        return 1;
    }

    head(file, DEFAULT_LINE_COUNT);

    fclose(file);
    return 0;
}

