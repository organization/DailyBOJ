#include <iostream>
#include <cmath>

int ans = 0;
int T, N;
int sx, sy, ax, ay;
int px, py, pr;

void process() {
    double distance_s = std::sqrt(std::pow(std::abs(sx - px),2) + std::pow(std::abs(sy - py),2));
    double distance_a = std::sqrt(std::pow(std::abs(ax - px),2) + std::pow(std::abs(ay - py),2));
    if(distance_s < pr && distance_a < pr) return;
    else if(distance_s < pr) ans++;
    else if(distance_a < pr) ans++;
}

int main() {
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        std::cin >> sx >> sy >> ax >> ay;
        std::cin >> N;
        for (int l = 0; l < N; ++l) {
            std::cin >> px >> py >> pr;
            process();
        }
        std::cout << ans << '\n';
        ans = 0;
    }
    return 0;
}