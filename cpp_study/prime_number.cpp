#include <iostream>
#include <math.h>

using namespace std;

int is_prime(int n)
{
    int i;
    for (i = 2; i < n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int is_prime2(int n)
{
    int i, sqrn;
    sqrn = (int)sqrt(n);
    for(i = 2; i < sqrn; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {

    int n;
    int result1, result2;

    n = 1483;

    result1 = is_prime(n);
    cout << result1 << endl;

    result2 = is_prime2(n);
    cout << result2 << endl;
}