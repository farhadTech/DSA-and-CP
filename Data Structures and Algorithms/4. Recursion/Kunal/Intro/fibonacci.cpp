#include <iostream>
using namespace std;

int fib(int n) {
    if(n == 0 or n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 4;
    int ans = fib(n);
    cout << "Fibonacci of " << n << " is: " << ans << '\n';
    return 0;
}
