#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int calculate(int a, int b, std::function<int(int, int)> operation) {
    return operation(a, b);
}

int main() {
    int x = 5;
    int y = 3;

    // Using function pointers directly
    int (*funcPtr)(int, int) = add;
    int result = funcPtr(x, y);
    std::cout << "Using function pointer: " << result << std::endl;

    // Using std::function with named functions
    std::function<int(int, int)> func = subtract;
    result = func(x, y);
    std::cout << "Using std::function with named functions: " << result << std::endl;

    // Using std::function with lambda functions
    func = [](int a, int b) { return a * b; };
    result = func(x, y);
    std::cout << "Using std::function with lambda functions: " << result << std::endl;

    // Using std::function with calculate function
    result = calculate(x, y, add);
    std::cout << "Using std::function with calculate function: " << result << std::endl;

    return 0;
}
