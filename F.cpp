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
    float alpha_f = 0.5f;
    float beta_f = 0.3f;

    double alpha_d = 0.5;
    double beta_d = 0.3;

    float Z1f = (sin(alpha_f) + cos(2 * beta_f - alpha_f)) / (cos(alpha_f) - sin(2 * beta_f - alpha_f));
    float Z2f = (1 + sin(2 * beta_f)) / cos(2 * beta_f);
    double Z1d = (sin(alpha_d) + cos(2 * beta_d - alpha_d)) / (cos(alpha_d) - sin(2 * beta_d - alpha_d));
    double Z2d = (1 + sin(2 * beta_d)) / cos(2 * beta_d);

    cout << fixed << setprecision(15);

    float diff_f = abs(Z1f - Z2f);
    int match_f = compareDecimalDigits(Z1f, Z2f, 7);

    cout << "a. Z1f и Z2f:" << endl;
    cout << "Z1f = " << Z1f << endl;
    cout << "Z2f = " << Z2f << endl;
    cout << "Разность: " << diff_f << endl;
    cout << "Совпадают до " << match_f << " знака после запятой" << endl << endl;

    double diff_d = abs(Z1d - Z2d);
    int match_d = compareDecimalDigits(Z1d, Z2d);

    cout << "b. Z1d и Z2d:" << endl;
    cout << "Z1d = " << Z1d << endl;
    cout << "Z2d = " << Z2d << endl;
    cout << "Разность: " << diff_d << endl;
    cout << "Совпадают до " << match_d << " знака после запятой" << endl << endl;

    double diff_mixed = abs((double)Z1f - Z1d);
    int match_mixed = compareDecimalDigits((double)Z1f, Z1d);

    cout << "c. Z1f и Z1d:" << endl;
    cout << "Z1f = " << Z1f << endl;
    cout << "Z1d = " << Z1d << endl;
    cout << "Разность: " << diff_mixed << endl;
    cout << "Совпадают до " << match_mixed << " знака после запятой" << endl;

    return 0;
}