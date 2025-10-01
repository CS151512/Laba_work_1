#include <iostream>
#include <cmath>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();
    float alpha_f,beta_f;
    cin>>alpha_f>>beta_f;
    double alpha_d,beta_d;
    cin>>alpha_d>>beta_d;

    float Z1f = (sin(alpha_f) + cos(2 * beta_f - alpha_f)) / (cos(alpha_f) - sin(2 * beta_f - alpha_f));
    float Z2f = (1 + sin(2 * beta_f)) / cos(2 * beta_f);

    double Z1d = (sin(alpha_d) + cos(2 * beta_d - alpha_d)) / (cos(alpha_d) - sin(2 * beta_d - alpha_d));
    double Z2d = (1 + sin(2 * beta_d)) / cos(2 * beta_d);

    cout << "Результаты для float:" << endl;
    cout << "Z1f = " << Z1f << endl;
    cout << "Z2f = " << Z2f << endl;
    cout << endl;

    cout << "Результаты для double:" << endl;
    cout << "Z1d = " << Z1d << endl;
    cout << "Z2d = " << Z2d << endl;

    return 0;
}