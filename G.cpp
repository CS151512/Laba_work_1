#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int compareDecimalDigits(double a, double b, int max_precision = 15) {
    if (a == b) return max_precision;

    ostringstream oss1, oss2;
    oss1 << fixed << setprecision(max_precision) << a;
    oss2 << fixed << setprecision(max_precision) << b;

    string s1 = oss1.str();
    string s2 = oss2.str();

    size_t dot_pos1 = s1.find('.');
    size_t dot_pos2 = s2.find('.');

    if (dot_pos1 == string::npos || dot_pos2 == string::npos) {
        return 0;
    }

    int matching_digits = 0;
    for (int i = 1; i <= max_precision; i++) {
        if (dot_pos1 + i < s1.length() && dot_pos2 + i < s2.length()) {
            if (s1[dot_pos1 + i] == s2[dot_pos2 + i]) {
                matching_digits = i;
            } else {
                break;
            }
        }
    }

    return matching_digits;
}

int main() {
    const float PI_F = 3.14159265358979323846f;
    const double PI_D = 3.14159265358979323846;

    float alpha_f = PI_F / 6.0f;
    float beta_f = PI_F / 4.0f;

    double alpha_d = PI_D / 6.0;
    double beta_d = PI_D / 4.0;

    float Z1f = (sin(alpha_f) + cos(2 * beta_f - alpha_f)) / (cos(alpha_f) - sin(2 * beta_f - alpha_f));
    float Z2f = (1 + sin(2 * beta_f)) / cos(2 * beta_f);

    double Z1d = (sin(alpha_d) + cos(2 * beta_d - alpha_d)) / (cos(alpha_d) - sin(2 * beta_d - alpha_d));
    double Z2d = (1 + sin(2 * beta_d)) / cos(2 * beta_d);

    cout << "ВЫЧИСЛЕНИЕ И СРАВНЕНИЕ ЗНАЧЕНИЙ" << endl;
    cout << "================================" << endl << endl;

    cout << fixed << setprecision(10);

    cout << "Исходные значения:" << endl;
    cout << "Z1f = " << Z1f << endl;
    cout << "Z2f = " << Z2f << endl;
    cout << "Z1d = " << Z1d << endl;
    cout << "Z2d = " << Z2d << endl << endl;

    float diff_f = abs(Z1f - Z2f);
    int match_f = compareDecimalDigits(Z1f, Z2f, 7);

    cout << "1. Сравнение Z1f и Z2f:" << endl;
    cout << "   Разность: " << diff_f << endl;
    cout << "   Совпадают знаков после запятой: " << match_f << endl << endl;

    double diff_d = abs(Z1d - Z2d);
    int match_d = compareDecimalDigits(Z1d, Z2d);

    cout << "2. Сравнение Z1d и Z2d:" << endl;
    cout << "   Разность: " << diff_d << endl;
    cout << "   Совпадают знаков после запятой: " << match_d << endl << endl;

    double diff_mixed = abs((double)Z1f - Z1d);
    int match_mixed = compareDecimalDigits((double)Z1f, Z1d);

    cout << "3. Сравнение Z1f и Z1d:" << endl;
    cout << "   Разность: " << diff_mixed << endl;
    cout << "   Совпадают знаков после запятой: " << match_mixed << endl << endl;

    cout << "АНАЛИЗ РЕЗУЛЬТАТОВ:" << endl;
    cout << "===================" << endl;

    cout << "Точность типов данных:" << endl;
    cout << "- Float: 7 значащих цифр" << endl;
    cout << "- Double: 15 значащих цифр" << endl << endl;

    cout << "Разность между float и double: " << diff_mixed << endl;

    if (match_f == match_d) {
        cout << "Z1 и Z2 математически эквивалентны" << endl;
    } else {
        cout << "Z1 и Z2 имеют математические различия" << endl;
    }

    cout << "Double показывает более высокую точность вычислений" << endl;

    if (diff_mixed < 0.0001) {
        cout << "Разница между float и double незначительна" << endl;
    } else {
        cout << "Заметная разница между типами данных" << endl;
    }

    return 0;
}