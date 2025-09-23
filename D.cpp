#include <iostream>

int main() {

    int start_h, start_m, start_s;
    int end_h, end_m, end_s;

    std::cin >> start_h >> start_m >> start_s;

    std::cin >> end_h >> end_m >> end_s;

    int start_total_seconds = start_h * 3600 + start_m * 60 + start_s;
    int end_total_seconds = end_h * 3600 + end_m * 60 + end_s;

    int diff_seconds = end_total_seconds - start_total_seconds;

    if (diff_seconds < 0) {
        diff_seconds += 24 * 3600;
    }

    int duration_h = diff_seconds / 3600;
    int duration_m = (diff_seconds % 3600) / 60;
    int duration_s = diff_seconds % 60;

    std::cout << "Продолжительность промежутка: "
              << duration_h << " ч "
              << duration_m << " мин "
              << duration_s << " сек" << std::endl;

    return 0;
}