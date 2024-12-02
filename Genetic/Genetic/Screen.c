#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WIDTH 80  // 화면 너비
// 문자열을 가운데로 출력하는 함수
void print_centered(const char* str)  { 
    int len = strlen(str);
    int padding = (WIDTH - len) / 2;  // 양쪽 여백 계산
    for (int i = 0; i < padding; i++) {
        printf(" ");  // 왼쪽 여백 출력
    }
    printf("%s\n", str);  // 문자열 출력
}

int main() {
    system("cls");  //콘솔 정리

    // 게임 제목을 가운데에 출력
    print_centered("유전자 결합 게임");

    printf("\n\n");

    // 선택지 출력
    print_centered("1. 시작 2.설명 3.종료 ");

    return 0;
}
