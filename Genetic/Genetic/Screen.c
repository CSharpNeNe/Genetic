#define _CRT_SECURE_NO_WARNINGS //scanf ��� ����
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
} //���� �Լ�


void print_centered(const char* str)  { 
    int len = strlen(str);
    int padding = (WIDTH - len) / 2;  // ���� ���� ���
    for (int i = 0; i < padding; i++) {
        printf(" ");  // ���� ���� ���
    }
    printf("%s\n", str);  // ���ڿ� ���
} //���� �߾� ��� �Լ�

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
    printf("%c",characters[index]);
} //������ 1��°���� 6��°���� ����� ���� ���

int calculate_score(char* characters) {
    int score = 0;
    for (int i = 0; i < 6; i++) {
        switch (characters[i]) {
        case 'X':
        case 'B':
        case 'N':
            score -= 10;
            break;
        case 'S':
            score += 40;
            break;
        case 'G':
            score += 20;
            break;
        default:
            break;
        }
    }
    return score; //���� ������ִ� �Լ�, X,B,N�� -10��, S�� 40��, G�� 20��

void display_menu() {
    // �޴��� ȭ�鿡 ���
    print_centered("������ ���� ����");
    printf("\n");  // �� �� ����

    print_centered("1. ����");
    print_centered("2. ����");
    print_centered("3. ����");
}

int main() {
    // ���� �õ带 �ʱ�ȭ
    srand(time(NULL));
    // ���� ���� ȭ�� ���
    display_menu();

    int game_running = 1;
    while (game_running) {
        // ����� ������ �ޱ� ���� ����
        char input[100];
        int choice;

        printf("\n����: ");

        // �Է� ���� �ʱ�ȭ
        memset(input, 0, sizeof(input));

        // ���ڿ��� �Է� �ޱ�
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // �Է� ���� �� ó��
            printf("\n�Է� ������ �߻��߽��ϴ�.\n");
            continue;
        }

        // ���� ���� ����
        input[strcspn(input, "\n")] = 0;

        // �Է��� �������� Ȯ��
        if (sscanf(input, "%d", &choice) != 1) {
            printf("\n�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���.\n");
            continue;
        }

        // ���ÿ� ���� ó��
        if (choice == 1) {
            // ���� ����
            printf("\n������ �����մϴ�!\n\n");
            // 1������ 6������ �������� ���� ��� �� ���� ���
            for (int i = 0; i < 6; i++) {
                print_random_character_and_score();
            }
            printf("\n");
        }
        else if (choice == 2) {
            // ���� ����
            printf("\n���� ����:\n");
            printf("�� ������ X, B, N, S, G ���ڰ� �������� ���� ������ �ο��մϴ�. ���ڸ� ������ �ٲ� �� �ִ� ��ȸ�� 3�� �ְ�, ���� ���� ������ ����ϴ°� ��ǥ�Դϴ�.\n");
            printf("X, B, N�� -10��, S�� 40��, G�� 20���Դϴ�.\n");
            printf("�����ϰ� ������ ����ϰ� ����մϴ�.\n");
        }
        else if (choice == 3) {
            // ����
            printf("\n������ �����մϴ�.\n");
            game_running = 0;
        }
        else {
            // �߸��� ����
            printf("\n�߸��� �����Դϴ�. 1, 2, 3 �߿��� ������ �ּ���.\n");
        }
    }
    return 0;
}