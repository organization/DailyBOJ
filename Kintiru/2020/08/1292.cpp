#include <iostream>

int main() {
    int a, b, ans = 0;
    std::cin >> a >> b;
    int k[b], next = 1, t = 1;
    for(int i = 0; i < b; ++i) {
        if(!t) {t = ++next;}
        if(i >= a-1) {
            ans += next;
        }
        t--;
    }
    std::cout << ans;
    return 0;
}