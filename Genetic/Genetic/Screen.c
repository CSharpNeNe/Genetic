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
