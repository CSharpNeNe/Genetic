#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define WIDTH 80  // ȭ�� �ʺ�
// ���ڿ��� ����� ����ϴ� �Լ�

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
} Color; //���� �Լ�

void set_text_color(Color text_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, text_color);
}


void print_centered(const char* str)  { 
    int len = strlen(str);
    int padding = (WIDTH - len) / 2;  // ���� ���� ���
    for (int i = 0; i < padding; i++) {
        printf(" ");  // ���� ���� ���
    }
    printf("%s\n", str);  // ���ڿ� ���
} //���� �߾� ��� �Լ�

int main() {
    system("cls");  //�ܼ� ����

    // ���� ������ ����� ���
    print_centered("������ ���� ����");

    printf("\n\n");

    // ������ ���
    print_centered("1. ���� 2.���� 3.���� ");

    srand(time(NULL));

    // 1������ 6������ ���
    for (int i = 0; i < 6; i++) {
        print_random_character_and_score();
    }

    return 0;
}

void print_random_character_and_score() {
    // ���� ���ڸ� ���� (0���� 5����)
    char characters[] = { 'X', 'B', 'N', 'S', 'G' };
    int scores[] = { -10, -10, -10, 40, 20 };  // �� ������ ����
    Color colors[] = { RED, RED, RED, YELLOW, YELLOW };  // �������� X, B, N, ������� S, G

    // ���� �ε��� ����
    int index = rand() % 5;  // 0���� 4������ ���� �ε���

    // ���� ����
    set_text_color(colors[index]);

    // ���� ���
    printf("%c: %d��\n", characters[index], scores[index]);
} //������ 1��°���� 6��°���� ����� ���� ���