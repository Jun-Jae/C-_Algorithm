#include <iostream>

using namespace std;

int get_gcd(int u, int v)
{
    int t;
    while (u > 0) {
        if (u < v) {
            t = u; u = v; v = t;
        }
        u = u - v;
    }
    return v;
}

int gcd_modulus(int u, int v) // 개선된 유클리드 함수
{
    int t;
    while (v > 0) {
        t = u % v;
        u = v;
        v = t;
    }
    return u;
}

int gcd_recursion(int u, int v) // 재귀함수 사용
{
    if (v == 0) {
        return u;
    } else {
        return gcd_recursion(v, u % v);
    }

}

int main() {

    int u, v;
    int gcd;

    u = 280;
    v = 30; 

    cout << "get_gcd result : ";
    gcd = get_gcd(u, v);
    cout << gcd << endl;

    cout << "gcd_modulus result : ";
    gcd = gcd_modulus(u, v);
    cout << gcd << endl;

    cout << "gcd_recursion result : ";
    gcd = gcd_recursion(u, v);
    cout << gcd << endl;
}