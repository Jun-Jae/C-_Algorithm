#include <iostream>
#include <stdlib.h> // atoi 사용을 위해
#include <string.h> // memset 사용을 위해

using namespace std;

int main(int argc, char* argv[])
{
    // 인자가 있어야 함.
    if (argc < 2) {
        cout << "Usage : prime2 [interger]" << endl;
        return 0;
    }

    // 주어진 인자는 2보다 큰 수여야 함.
    int n = atoi(argv[1]);
    if(n < 2) {
        cout << "Error : n must be greater than 1 " << endl;
        return 0;
    }

    int *parray;

    // 메모리 할당
    parray = new int [n+1];
    if(parray == 0) {
        cout << "Error : Memory allocation failed" << endl;
        return 0;
    }

    // 메모리를 0으로 초기화
    memset(parray, 0, sizeof(int)*(n+1));

    int i, j;
    // 소수 구하기 루프
    for(i = 2; i <= n ; i++) {
        if(parray[i] == 1) // 이미 주어진 수, 즉 소수가 아니면 그 다음수로 넘어간다
            continue;
        j = i; // i를 기점으로 해서
        while((j += i) <= n) {
            parray[j] = 1;
        }
    }

    // 소수의 출력
    for (i = 2; i <= n; i++) {
        if(parray[i] == 0)
            cout << i;
    }
    cout << endl;

    // 할당된 메모리를 해제
    delete [] parray;
    return 0;
}