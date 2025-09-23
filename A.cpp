#include <cassert>

#include "iostream"

double calc_area(double a, double b) {
    if (a<= 0 || b <= 0) {
        throw std::invalid_argument("Base and height must be positive");
    }

    return 0.5 * a * b;
}

double calc_volume(double base_area, double height) {
    if ( height <= 0) {
        throw std::invalid_argument("Height must be positive");
    }

    return (1.0 / 3.0) * base_area * height;
}

void test_calc_area() {
    std::cout << "Testing calc_area function:\n";

    double result = calc_area(4.0, 6.0);
    double expected = 12.0;
    assert(std::abs(result - expected) < 1e-9);
    std::cout << "calc_area(4, 6) = " << result << std::endl;

    result = calc_area(2.5, 4.0);
    expected = 5.0;
    assert(std::abs(result - expected) < 1e-9);
    std::cout << "calc_area(2.5, 4) = " << result << std::endl;

    result = calc_area(100.0, 50.0);
    expected = 2500.0;
    assert(std::abs(result - expected) < 1e-9);
    std::cout << "calc_area(100, 50) = " << result << std::endl;

    try {
        calc_area(-5.0, 10.0);
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument& e) {
        std::cout << "Negative base exception: " << e.what() << std::endl;
    }

    try {
        calc_area(5.0, -10.0);
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument& e) {
        std::cout << "Negative height exception: " << e.what() << std::endl;
    }

    try {
        calc_area(-5.0, -10.0);
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument& e) {
        std::cout << "Both negative exception: " << e.what() << std::endl;
    }

    try {
        calc_area(0.0, 10.0);
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument& e) {
        std::cout << "Zero base exception: " << e.what() << std::endl;
    }

    std::cout << "All area tests passed!\n\n";
}

void test_calc_volume() {
    std::cout << "Testing calc_volume function:\n";

    double result = calc_volume(12.0, 4.0);
    double expected = 16.0;
    assert(std::abs(result - expected) < 1e-9);
    std::cout << "calc_volume(12, 4) = " << result << std::endl;

    result = calc_volume(9.0, 2.5);
    expected = 7.5;
    assert(std::abs(result - expected) < 1e-9);
    std::cout << "calc_volume(9, 2.5) = " << result << std::endl;

    try {
        calc_volume(10.0, -2.0);
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument& e) {
        std::cout << "Negative height exception: " << e.what() << std::endl;
    }

    try {
        calc_volume(10.0, 0.0);
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument& e) {
        std::cout << "Zero height exception: " << e.what() << std::endl;
    }

    result = calc_volume(-9.0, 3.0);
    expected = -9.0;
    assert(std::abs(result - expected) < 1e-9);
    std::cout << "Negative base area: " << result << std::endl;

    std::cout << "All volume tests passed!\n\n";
}

void test_integration() {
    std::cout << "Testing integration of both functions:\n";

    double base = 6.0;
    double height_triangle = 8.0;
    double height_pyramid = 5.0;

    double area = calc_area(base, height_triangle);
    double volume = calc_volume(area, height_pyramid);

    double expected_volume = 40.0;
    assert(std::abs(volume - expected_volume) < 1e-9);
    std::cout << "Integration test: volume = " << volume << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    test_calc_area();
    test_calc_volume();
    test_integration();

    return 0;
}