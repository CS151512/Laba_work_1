#include "iostream"

double area_func(double a, double b, double c) {
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double a,b,c;
    std::cin>>a>>b>>c;

    std::cout<<area_func(a,b,c)<<"\n";

    return 0;
}