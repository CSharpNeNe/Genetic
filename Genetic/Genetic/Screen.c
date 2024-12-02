#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WIDTH 80  // ȭ�� �ʺ�
// ���ڿ��� ����� ����ϴ� �Լ�
void print_centered(const char* str)  { 
    int len = strlen(str);
    int padding = (WIDTH - len) / 2;  // ���� ���� ���
    for (int i = 0; i < padding; i++) {
        printf(" ");  // ���� ���� ���
    }
    printf("%s\n", str);  // ���ڿ� ���
}

int main() {
    system("cls");  //�ܼ� ����

    // ���� ������ ����� ���
    print_centered("������ ���� ����");

    printf("\n\n");

    // ������ ���
    print_centered("1. ���� 2.���� 3.���� ");

    return 0;
}
//������ 1��°���� 6��°���� ����� ���� ���
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
}