#include <iostream>

void evendigits(long long n, int& ans) {
    if (n == 0) {
        return;
    }

    if ((n % 10) % 2 == 0) {
        ++ans;
    }
    evendigits(n / 10, ans);
}

int main () {
    std::cout << "How many even digits are in the number N?\n";
    long long n = 9223372036854775806;
    int ans = 0;
    std::cout << "Number N: " << n << "\n";
    evendigits(n, ans);
    std::cout << "The number of even digit in the number N: " << ans << "\n";
}