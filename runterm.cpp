#include <iostream>

int calculateNimSum(int n) {
    int m = 0; // Number of bits in the binary representation
    int nimSum = 0;

    // Convert n to binary and count the number of bits
    while (n > 0) {
        nimSum ^= n;
        n /= 2;
        m++;
    }

    return nimSum;
}

bool isFirstPlayerWinning(int n) {
    int nimSum = calculateNimSum(n);

    // If nimSum is 0, the first player loses
    // Otherwise, the first player wins
    return (nimSum != 0);
}

int main() {
    int n;
    std::cout << "Enter the number of stones in the pile (n): ";
    std::cin >> n;

    if (isFirstPlayerWinning(n)) {
        std::cout << "First player wins!" << std::endl;
    } else {
        std::cout << "First player loses!" << std::endl;
    }

    return 0;
}
