#include <iostream>

int attempts(int n, int k = 3) {

    if (n < 0) return 0;
    
    if (n == 0) return 1;

    int totalJumps = 0;
    for (int i = 1; i <= k; i++) {
        totalJumps += attempts(n - i, k);
    }
    
    return totalJumps;
}

int main() {
    std::cout << "Rabbit jumps!\n";
    int n = 5, k = 3;
    std::cout << "Jumps attempts: " << attempts(n,k) << std::endl;

}