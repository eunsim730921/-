#include <stdio.h>
#include <string.h>

void help(const char *command) {
    if (strcmp(command, "ls") == 0) {
        printf("ls 명령어는 현재 디렉토리의 파일과 디렉토리를 나열합니다.\n");
        printf("사용법: ls [옵션]\n");
    } else if (strcmp(command, "mkdir") == 0) {
        printf("mkdir 명령어는 새 디렉토리를 생성합니다.\n");
        printf("사용법: mkdir [디렉토리 이름]\n");
    } else if (strcmp(command, "rm") == 0) {
        printf("rm 명령어는 파일이나 디렉토리를 삭제합니다.\n");
        printf("사용법: rm [파일 또는 디렉토리]\n");
    } else {
        printf("도움말을 제공할 수 없는 명령어입니다.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s [도움말을 표시할 명령어]\n", argv[0]);
        return 1;
    }

    help(argv[1]);

    return 0;
}

