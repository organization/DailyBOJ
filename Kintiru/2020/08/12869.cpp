#include <iostream>
#include <algorithm>
#include <limits>
#include <bits/stdc++.h>

int dp[61][61][61];
int f(int x, int y, int z) {
    // x,y,z 중 하나라도 음수가 되거나 다 0인 경우 방지
    if(x < 0) x = 0;
    if(y < 0) y = 0;
    if(z < 0) z = 0;
    if(!x&&!y&&!z) return 0;
    int &res = dp[x][y][z]; //해당 dp[x][y][z]에 있는 값 alias
    if (res != -1) return res; //이미 계산이 되어있는 경우

    // x y z 최소까지 계산해서 빼는 최소값을 재귀로 점점 더해올리는 형식
    // INT_MAX 는 첫 최솟값 비교를 위해 그냥 쓴 것. 어느정도 큰 값이면 상관 X.
    res = std::numeric_limits<int>::max();
    res = std::min(res, f(x-9,y-3,z-1) + 1);
    res = std::min(res, f(x-9,y-1,z-3) + 1);
    res = std::min(res, f(x-3,y-9,z-1) + 1);
    res = std::min(res, f(x-3,y-1,z-9) + 1);
    res = std::min(res, f(x-1,y-9,z-3) + 1);
    res = std::min(res, f(x-1,y-3,z-9) + 1);
    return res;
}
int main() {
    int n, svc[3] = {0,0,0};
    std::cin >> n;
    // dp 배열 안의 모든 값을 -1로 세팅
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i){
        std::cin >> svc[i];
    }
    std::cout << f(svc[0], svc[1], svc[2]);
}