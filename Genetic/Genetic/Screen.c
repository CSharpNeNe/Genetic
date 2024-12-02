#define _CRT_SECURE_NO_WARNINGS //scanf ��� ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define WIDTH 80  // ȭ�� �ʺ�

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
} Color; // ���� �Լ�

void set_text_color(Color text_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, text_color);
} // ���� ���� �Լ�

void reset_text_color() {
    set_text_color(WHITE);  // ������ �⺻���� WHITE�� �ǵ�����
} // ���� �ʱ�ȭ �Լ�

void print_centered(const char* str) {
    int len = strlen(str);
    int padding = (WIDTH - len) / 2;  // ���� ���� ���
    for (int i = 0; i < padding; i++) {
        printf(" ");  // ���� ���� ���
    }
    printf("%s\n", str);  // ���ڿ� ���
} // ���� �߾� ��� �Լ�

void print_random_character_and_score(char* character, Color* color) {
    // ���� ���ڸ� ���� (0���� 5����)
    char characters[] = { 'X', 'B', 'N', 'S', 'G' };
    int scores[] = { -30, -20, -10, 40, 20 };  // �� ������ ����
    Color colors[] = { RED, RED, RED, YELLOW, YELLOW };  // �������� X, B, N, ������� S, G

    // ���� �ε��� ����
    int index = rand() % 5;  // 0���� 4������ ���� �ε���

    // ���� ����
    *color = colors[index];
    *character = characters[index];
} // ������ ���ڿ� ���� ���� ���

int calculate_score(char* characters) {
    int score = 0;
    int s_count = 0; // S�� Ƚ��
    int g_count = 0; // G�� Ƚ��
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

    // S�� ������ 2�� �̻��̸� 100�� �߰�
    if (s_count >= 2)
        score += 100;
    // G�� ������ 2�� �̻��̸� 50�� �߰�
    if (g_count >= 2)
        score += 50;
    return score;
} // ���� ���� ��� �Լ�

void display_menu() {
    // �޴��� ȭ�鿡 ���
    print_centered(" _____                     _    _       ");
    print_centered("|  __ |                   | |  (_)      ");
    print_centered("| |  |/  ___  _ __    ___ | |_  _   ___ ");
    print_centered("| | __  / _ || '_ |  / _ || __|| | / __|");
    print_centered("| |_| ||  __/| | | ||  __/| |_ | || (__ ");
    print_centered("|____/ |___||_| |_| |___| |__| |_| |___|");
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



        // �Է� ���� �ʱ�ȭ
        memset(input, 0, sizeof(input));

        // ���ڿ��� �Է� �ޱ�
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // �Է� ���� �� ó��
            continue;
        }

        // ���� ���� ����
        input[strcspn(input, "\n")] = 0;

        // �Է��� �������� Ȯ��
        if (sscanf(input, "%d", &choice) != 1) {
            continue;
        }

        // ���ÿ� ���� ó��
        if (choice == 1) {
            // ���� ����
            system("cls");
            printf("\n������ �����մϴ�!\n\n");

            // 6���� ���� ���ڿ� ���� �迭 �غ�
            char characters[6];
            Color colors[6];

            // 6���� ���� ���� ����
            for (int i = 0; i < 6; i++) {
                print_random_character_and_score(&characters[i], &colors[i]);
            }

            // ���� ��ȸ 3�� ����
            int chances = 3;
            while (chances > 0) {
                system("cls");
                printf("\n������ �����մϴ�!\n\n");
                printf("\n���� ���� ��ȸ: %d\n", chances);
                printf("���� ���ڴ�: ");
                for (int i = 0; i < 6; i++) {
                    set_text_color(colors[i]);  // �� ���ڿ� ���� ���� ����
                    printf("%c ", characters[i]);
                    reset_text_color();  // �� ���� �ڿ� ���� �ʱ�ȭ
                }
                printf("\n");

                printf("������ ������ ��ȣ(1~6)�� �Է��ϰų� 7�� �Է��ϸ� ���� ����: ");
                int index;
                if (scanf("%d", &index) != 1 || (index < 0 || index > 7)) {
                    // �߸��� �Է� ó��
                    while (getchar() != '\n'); // �Է� ���� ����
                    printf("�߸��� �Է��Դϴ�. 1~6 �Ǵ� 7�� �Է��ϼ���.\n");
                    continue;
                }

                if (index == 7) {
                    // ���� ����
                    break;
                }

                if (index >= 1 && index <= 6) {
                    // ���õ� �ε����� 0���� �����ϴ� �ε����� ���߱�
                    index--;

                    // ���� ����
                    print_random_character_and_score(&characters[index], &colors[index]);
                    chances--;
                }
                else {
                    printf("�߸��� �����Դϴ�. 1~6 �Ǵ� 7�� �Է��ϼ���.\n");
                }
            }

            // ���� ���� �� ���� ���ڸ� �����ְ� ���� ��� �� ���
            system("cls");
            printf("\n���� ���:\n");
            for (int i = 0; i < 6; i++) {
                set_text_color(colors[i]);  // �� ���ڿ� ���� ���� ����
                printf("%c ", characters[i]);
                reset_text_color();  // �� ���� �ڿ� ���� �ʱ�ȭ
            }

            // ���� ���
            int final_score = calculate_score(characters);
            printf("\n���� ����: %d\n", final_score);
            printf("\n������ ����Ϸ��� '1'�� �Է��ϰ�, �����Ϸ��� '3'�� �Է��ϼ���.\n");
            

        }
        else if (choice == 2) {
            // ���� ����
            system("cls");
            display_menu();
            printf("\n���� ����:\n");
            printf("Genetic�� X, B, N, S, G ���ڰ� �������� ������ 6���� �������Դϴ�. ���ڸ� ������ �ٲ� �� �ִ� ��ȸ�� 3�� �ְ�, ���� ���� �����ڸ� �����ϴ°� ��ǥ�Դϴ�.\n");
            printf("X, B, N�� ���� -30, -20, -10��, S�� 40��, G�� 20���Դϴ�. ���� ���� ������ ����غ�����.\n");
            printf("S�� 2�� �̻��̸� 100�� �߰�,G�� 2�� �̻��̸� 50�� �߰��Ǿ� ������ �ջ�ǹǷ�, ���� �����ڸ� ����� ���� ����غ�����.");
        }
        else if (choice == 3) {
            // ����
            printf("\n������ �����մϴ�.\n");
            game_running = 0;  // ���� ����
        }
        else {
            // �߸��� ���� �ÿ��� ��µ��� ����
        }
    }
    return 0;
}
