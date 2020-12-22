#include <iostream>
#include <cmath>

int main() {
    int n;

    std::cin >> n;

    int x1, x2, r1, y1, y2, r2;
    int * a = new int[n];

    for(int i = 0; i < n; ++i) {
        std::cin >> x1 >> x2 >> r1 >> y1 >> y2 >> r2;
        double distance = std::sqrt(std::pow(x1 - y1,2) + std::pow(x2 - y2,2));
        if(abs(r1-r2) >= distance) {
            if(distance == 0 && r1 == r2) {
                a[i] = -1;
            } else if (abs(r1-r2) > distance) {
                a[i] = 0;
            } else {
                a[i] = 1;
            }
        } else {
            if(r1 + r2 > distance) {
                a[i] = 2;
            } else if (r1 + r2 == distance) {
                a[i] = 1;
            } else {
                a[i] = 0;
            }
        }
    }

    for(int i = 0; i < n; ++i)
        std::cout << a[i] << std::endl;
    delete[] a;
    return 0;
}

