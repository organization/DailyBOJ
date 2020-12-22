#include <iostream>
#include <utility>
#include <cmath>
#include <vector>

#define F first
#define S second
#define pii std::pair<int, int>

int N;
long long power[32];

void preprocess() {
    for(int i = 0; i < 32; ++i) {
        power[i] = pow(3,i);
    }
}

void process(long long int left, std::vector<pii> &list, int current) {
    if(left == 1) {
        list.emplace_back(current,0);
    }
    else if(left % 2 == 0) {
        current++;
        process(left / 2, list, current);
    } else {
        int i = 20;
        while(power[i] > left) --i;
        if(left - power[i] == 0) {
            list.emplace_back(current,i);
        } else {
            list.emplace_back(current,i);
            process(left-power[i], list, current);
        }
    }
    return;
}

int main() {
    long long a;
    std::cin >> N;

    preprocess();
    auto * ans = new std::vector<pii>[N];

    for(int i = 0; i < N; ++i) {
        std::cin >> a;
        process(a, ans[i], 0);
    }

    for(int i = 0; i < N; ++i) {
        std::cout << ans[i].size() << std::endl;
        for(auto & j : ans[i]) {
            std::cout << j.F << " " << j.S << std::endl;
        }
    }
    delete []ans;
    return 0;
}