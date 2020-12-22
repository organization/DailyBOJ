#include <iostream>
#include <cstring>
#include <algorithm>

int n;
int left[1002], right[1002], dp[1002][1002];

int main() {
    std::cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        std::cin >> left[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> right[i];
    }
    for (int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
        {
            dp[i][j] = std::max(dp[i][j-1],dp[i-1][j]);
            if(abs(left[i] - right[j]) <= 4)
                dp[i][j] = dp[i-1][j-1] + 1;
        }
    }
    std::cout << dp[n][n];
    return 0;
}