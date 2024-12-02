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
//유전자 1번째부터 6번째까지 색깔과 문자 출력
void print_random_character_and_score() {
    // 랜덤 문자를 생성 (0부터 5까지)
    char characters[] = { 'X', 'B', 'N', 'S', 'G' };
    int scores[] = { -10, -10, -10, 40, 20 };  // 각 문자의 점수
    Color colors[] = { RED, RED, RED, YELLOW, YELLOW };  // 빨간색은 X, B, N, 노란색은 S, G

    // 랜덤 인덱스 생성
    int index = rand() % 5;  // 0부터 4까지의 랜덤 인덱스

    // 색상 설정
    set_text_color(colors[index]);

    // 문자 출력
    printf("%c: %d점\n", characters[index], scores[index]);
}