#include <iostream>

int main() {
    long long sum = 0;
    int N = 0;
    
    std::cout << "Enter a whole number (N): ";
    std::cin >> N;

    for (int i = 1; i <= N; i++)
        sum += i;
    std::cout << "Sum of the numbers from 1 to " << N << " is: " << sum << std::endl;

    return 0;
}