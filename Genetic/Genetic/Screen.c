#define _CRT_SECURE_NO_WARNINGS //scanf 경고 무시
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define WIDTH 80  // 화면 너비

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
} Color; // 색깔 함수

void set_text_color(Color text_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, text_color);
} // 색깔 설정 함수

void reset_text_color() {
    set_text_color(WHITE);  // 색상을 기본값인 WHITE로 되돌리기
} // 색상 초기화 함수

void print_centered(const char* str) {
    int len = strlen(str);
    int padding = (WIDTH - len) / 2;  // 양쪽 여백 계산
    for (int i = 0; i < padding; i++) {
        printf(" ");  // 왼쪽 여백 출력
    }
    printf("%s\n", str);  // 문자열 출력
} // 글자 중앙 출력 함수

void print_random_character_and_score(char* character, Color* color) {
    // 랜덤 문자를 생성 (0부터 5까지)
    char characters[] = { 'X', 'B', 'N', 'S', 'G' };
    int scores[] = { -30, -20, -10, 40, 20 };  // 각 문자의 점수
    Color colors[] = { RED, RED, RED, YELLOW, YELLOW };  // 빨간색은 X, B, N, 노란색은 S, G

    // 랜덤 인덱스 생성
    int index = rand() % 5;  // 0부터 4까지의 랜덤 인덱스

    // 색상 설정
    *color = colors[index];
    *character = characters[index];
} // 유전자 문자와 색깔 랜덤 출력

int calculate_score(char* characters) {
    int score = 0;
    int s_count = 0; // S의 횟수
    int g_count = 0; // G의 횟수
    for (int i = 0; i < 6; i++) {
        switch (characters[i]) {
        case 'X':
            score -= 30;
            break;
        case 'B':
            score -= 20;
            break;
        case 'N':
            score -= 10;
            break;
        case 'S':
            score += 40;
            s_count++;
            break;
        case 'G':
            score += 20;
            g_count++;
            break;
        default:
            break;
        }
    }

    // S의 개수가 2개 이상이면 100점 추가
    if (s_count >= 2)
        score += 100;
    // G의 개수가 2개 이상이면 50점 추가
    if (g_count >= 2)
        score += 50;
    return score;
} // 최종 점수 계산 함수

void display_menu() {
    // 메뉴를 화면에 출력
    print_centered(" _____                     _    _       ");
    print_centered("|  __ |                   | |  (_)      ");
    print_centered("| |  |/  ___  _ __    ___ | |_  _   ___ ");
    print_centered("| | __  / _ || '_ |  / _ || __|| | / __|");
    print_centered("| |_| ||  __/| | | ||  __/| |_ | || (__ ");
    print_centered("|____/ |___||_| |_| |___| |__| |_| |___|");
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

    int game_running = 1;
    while (game_running) {
        // 사용자 선택을 받기 위한 변수
        char input[100];
        int choice;



        // 입력 버퍼 초기화
        memset(input, 0, sizeof(input));

        // 문자열로 입력 받기
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // 입력 오류 시 처리
            continue;
        }

        // 개행 문자 제거
        input[strcspn(input, "\n")] = 0;

        // 입력이 숫자인지 확인
        if (sscanf(input, "%d", &choice) != 1) {
            continue;
        }

        // 선택에 따른 처리
        if (choice == 1) {
            // 게임 시작
            system("cls");
            printf("\n게임을 시작합니다!\n\n");

            // 6개의 랜덤 문자와 색상 배열 준비
            char characters[6];
            Color colors[6];

            // 6개의 문자 랜덤 생성
            for (int i = 0; i < 6; i++) {
                print_random_character_and_score(&characters[i], &colors[i]);
            }

            // 수정 기회 3번 제공
            int chances = 3;
            while (chances > 0) {
                system("cls");
                printf("\n게임을 시작합니다!\n\n");
                printf("\n남은 수정 기회: %d\n", chances);
                printf("현재 문자는: ");
                for (int i = 0; i < 6; i++) {
                    set_text_color(colors[i]);  // 각 문자에 대해 색상 설정
                    printf("%c ", characters[i]);
                    reset_text_color();  // 각 문자 뒤에 색상 초기화
                }
                printf("\n");

                printf("수정할 문자의 번호(1~6)를 입력하거나 7을 입력하면 수정 종료: ");
                int index;
                if (scanf("%d", &index) != 1 || (index < 0 || index > 7)) {
                    // 잘못된 입력 처리
                    while (getchar() != '\n'); // 입력 버퍼 비우기
                    printf("잘못된 입력입니다. 1~6 또는 7을 입력하세요.\n");
                    continue;
                }

                if (index == 7) {
                    // 수정 종료
                    break;
                }

                if (index >= 1 && index <= 6) {
                    // 선택된 인덱스를 0부터 시작하는 인덱스로 맞추기
                    index--;

                    // 문자 수정
                    print_random_character_and_score(&characters[index], &colors[index]);
                    chances--;
                }
                else {
                    printf("잘못된 선택입니다. 1~6 또는 7을 입력하세요.\n");
                }
            }

            // 게임 종료 후 최종 문자를 보여주고 점수 계산 후 출력
            system("cls");
            printf("\n최종 결과:\n");
            for (int i = 0; i < 6; i++) {
                set_text_color(colors[i]);  // 각 문자에 대해 색상 설정
                printf("%c ", characters[i]);
                reset_text_color();  // 각 문자 뒤에 색상 초기화
            }

            // 점수 계산
            int final_score = calculate_score(characters);
            printf("\n최종 점수: %d\n", final_score);
            printf("\n게임을 계속하려면 '1'을 입력하고, 종료하려면 '3'을 입력하세요.\n");
            

        }
        else if (choice == 2) {
            // 게임 설명
            system("cls");
            display_menu();
            printf("\n게임 설명:\n");
            printf("Genetic은 X, B, N, S, G 문자가 랜덤으로 구성된 6개의 유전자입니다. 문자를 지정해 바꿀 수 있는 기회가 3번 있고, 가장 좋은 유전자를 구성하는게 목표입니다.\n");
            printf("X, B, N은 각각 -30, -20, -10점, S는 40점, G는 20점입니다. 가장 높은 점수를 기록해보세요.\n");
            printf("S가 2개 이상이면 100점 추가,G가 2개 이상이면 50점 추가되어 점수가 합산되므로, 좋은 유전자를 만들기 위해 노력해보세요.");
        }
        else if (choice == 3) {
            // 종료
            printf("\n게임을 종료합니다.\n");
            game_running = 0;  // 게임 종료
        }
        else {
            // 잘못된 선택 시에는 출력되지 않음
        }
    }
    return 0;
}
