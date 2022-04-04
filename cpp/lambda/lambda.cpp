#include <iostream>

int main() {
    auto sqr = [](auto i) constexpr { return i * i; };
    constexpr int a = sqr(3);
    std::cout << a << std::endl;

    auto add = [](int a, int b) { return a + b; };
    std::cout << add(2, 4) << std::endl;

    return 0;
}