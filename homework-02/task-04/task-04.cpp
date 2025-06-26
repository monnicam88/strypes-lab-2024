#include <iostream>

int32_t synthesisByOne(const int32_t a, const int32_t b, const int32_t c) {
    return (!a && !b && !c) || (!a && b && !c) || (!a && b && c) || (a && b && c);
}

int32_t synthesisByZero(const int32_t a, const int32_t b, const int32_t c) {
    return !((!a && !b && c) || (a && !b && !c) || (a && !b && c) || (a && b && !c));
}

int32_t minimizedExpr(const int32_t a, const int32_t b, const int32_t c) {
    return (!a && !c) || (!a && b && c) || (a && b && c);
}

int main() {
    int32_t a, b, c;
    std::cout << "Test logic function F(a, b, c)" << std::endl;

    while (!std::cin.eof()) {
        std::cin >> a >> b >> c;
        // std::cout << "F(" << a << ", " << b << ", " << c << ") = " << synthesisByOne(a, b, c) << std::endl;
        // std::cout << "F(" << a << ", " << b << ", " << c << ") = " << synthesisByZero(a, b, c) << std::endl;
        std::cout << "F(" << a << ", " << b << ", " << c << ") = " << minimizedExpr(a, b, c) << std::endl;
    } 
    return 0;
}
