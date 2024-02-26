#include <iostream>
#include <stdlib.h> // atoi ����� ����
#include <string.h> // memset ����� ����

using namespace std;

int main(int argc, char* argv[])
{
    // ���ڰ� �־�� ��.
    if (argc < 2) {
        cout << "Usage : prime2 [interger]" << endl;
        return 0;
    }

    // �־��� ���ڴ� 2���� ū ������ ��.
    int n = atoi(argv[1]);
    if(n < 2) {
        cout << "Error : n must be greater than 1 " << endl;
        return 0;
    }

    int *parray;

    // �޸� �Ҵ�
    parray = new int [n+1];
    if(parray == 0) {
        cout << "Error : Memory allocation failed" << endl;
        return 0;
    }

    // �޸𸮸� 0���� �ʱ�ȭ
    memset(parray, 0, sizeof(int)*(n+1));

    int i, j;
    // �Ҽ� ���ϱ� ����
    for(i = 2; i <= n ; i++) {
        if(parray[i] == 1) // �̹� �־��� ��, �� �Ҽ��� �ƴϸ� �� �������� �Ѿ��
            continue;
        j = i; // i�� �������� �ؼ�
        while((j += i) <= n) {
            parray[j] = 1;
        }
    }

    // �Ҽ��� ���
    for (i = 2; i <= n; i++) {
        if(parray[i] == 0)
            cout << i;
    }
    cout << endl;

    // �Ҵ�� �޸𸮸� ����
    delete [] parray;
    return 0;
}