#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define WIDTH 80  // 화면 너비
#define _CRT_SECURE_NO_WARNINGS //scanf 경고 무시
// 문자열을 가운데로 출력하는 함수

typedef enum {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
    BRIGHT_BLACK = 8,
    BRIGHT_BLUE = 9,
    BRIGHT_GREEN = 10,
    BRIGHT_CYAN = 11,
    BRIGHT_RED = 12,
    BRIGHT_MAGENTA = 13,
    BRIGHT_YELLOW = 14,
    BRIGHT_WHITE = 15
} Color; //색깔 함수

void set_text_color(Color text_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, text_color);
}


void print_centered(const char* str)  { 
    int len = strlen(str);
    int padding = (WIDTH - len) / 2;  // 양쪽 여백 계산
    for (int i = 0; i < padding; i++) {
        printf(" ");  // 왼쪽 여백 출력
    }
    printf("%s\n", str);  // 문자열 출력
} //글자 중앙 출력 함수

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
} //유전자 1번째부터 6번째까지 색깔과 문자 출력

void display_menu() {
    // 메뉴를 화면에 출력
    print_centered("유전자 결합 게임");
    printf("\n");  // 한 줄 공백

    print_centered("1. 시작");
    print_centered("2. 설명");
    print_centered("3. 종료");
}

int main() {
    // 랜덤 시드를 초기화
    srand(time(NULL));

    // 게임 시작 화면 출력
    display_menu();

    // 사용자 선택을 받기 위한 변수
    int choice;
    printf("\n선택: ");
    scanf("%d", &choice);

    // 선택에 따른 처리
    switch (choice) {
    case 1:
        // 게임 시작
        printf("\n게임을 시작합니다!\n\n");
        // 1번부터 6번까지 랜덤으로 문자 출력 및 점수 출력
        for (int i = 0; i < 6; i++) {
            print_random_character_and_score();
        }
        break;
    case 2:
        // 게임 설명
        printf("\n게임 설명:\n");
        printf("이 게임은 X, B, N, S, G 문자가 랜덤으로 나와 점수를 부여합니다.\n");
        printf("X, B, N은 -10점, S는 40점, G는 20점입니다.\n");
        printf("랜덤하게 점수를 계산하고 출력합니다.\n");
        break;
    case 3:
        // 종료
        printf("\n게임을 종료합니다.\n");
        break;
    default:
        // 잘못된 선택
        printf("\n잘못된 선택입니다. 1, 2, 3 중에서 선택해 주세요.\n");
        break;
    }

    return 0;
}