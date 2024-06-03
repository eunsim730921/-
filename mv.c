#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("방법: %s [이동할 파일 또는 디렉토리] [대상 경로]\n", argv[0]);
        return 1;
    }

    if (rename(argv[1], argv[2]) == -1) {
        perror("실패");
        return 1;
    }

    printf("%s를 %s로 이동했습니다.\n", argv[1], argv[2]);

    return 0;
}

