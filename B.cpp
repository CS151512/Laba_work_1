#include "iostream"

double f_to_c(double f) {
    return 5.0/9.0 * (f - 32.0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double f;
    std::cin>>f;

    std::cout<<f_to_c(f)<<"\n";

    return 0;
}