#include <bits/stdc++.h>
using namespace std;

int karatsuba(int a, int b) {
    int n = max(to_string(a).size(), to_string(b).size());

    if(n == 1) return a*b;

    int m = n/2;
    int high1 = a / (int) pow(10, m);
    int low1 = a % (int) (pow(10, m));
    int high2 = b / (int) pow(10, m);
    int low2 = b % (int) (pow(10, m));

    int z0 = karatsuba(low1, low2);
    int z1 = karatsuba(low1+high1, low2+high2);
    int z2 = karatsuba(high1, high2);

    return z2 * pow(10, 2*m) + (z1 - z2 - z0) * pow(10, m) + z0;
}

int karatsubaSquare(int n) {
    return karatsuba(n, n);
}

int main() {
    int n; cin >> n;
    cout << karatsubaSquare(n) << endl;
}