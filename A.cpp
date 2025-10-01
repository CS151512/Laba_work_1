#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

double calc_area(double a, double b) {
    if (a <= 0 || b <= 0) {
        throw std::invalid_argument("Base and height must be positive");
    }

    return 0.5 * a * b;
}

double calc_volume(double base_area, double height) {
    if (height <= 0) {
        throw std::invalid_argument("Height must be positive");
    }

    return (1.0 / 3.0) * base_area * height;
}

int main() {
    fast_io();
    double a, b,c;
    std::cin>>a>>b>>c;

    try {
        double base = a;
        double height_triangle = b;
        double height_pyramid = c;

        double area = calc_area(base, height_triangle);
        std::cout << "Area: " << area << "\n";

        double volume = calc_volume(area, height_pyramid);
        std::cout << "Volume: " << volume << "\n";

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred.\n";
        return 1;
    }

    return 0;
}