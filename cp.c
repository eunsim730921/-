#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "방법: %s <파일> <바꿀 파일>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *source_file = argv[1];
    char *target_file = argv[2];

    FILE *source_fp = fopen(source_file, "rb");
    if (source_fp == NULL) {
        perror("실패");
        exit(EXIT_FAILURE);
    }

    FILE *target_fp = fopen(target_file, "wb");
    if (target_fp == NULL) {
        perror("실패");
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(source_fp)) != EOF) {
        if (fputc(ch, target_fp) == EOF) {
            perror("ㅆ기 실패");
            fclose(source_fp);
            fclose(target_fp);
            exit(EXIT_FAILURE);
        }
    }

    fclose(source_fp);
    fclose(target_fp);

    printf("%s를 %s로 복사 완료\n", source_file, target_file);

    return 0;
}

