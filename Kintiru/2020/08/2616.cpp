#include <iostream>

int main() {
    int n, m;
    std::cin >> n;
    int sum[n+1], dp[4][50001];
    for (int i = 1; i <= n; i++) {
        std::cin >> sum[i];
        sum[i] += sum [i-1];
    }
    std::cin >> m;
    
    for (int i = 1; i <= 3; ++i) {
        for (int j = i*m; j <= n; j++) {
            dp[i][j] = std::max(dp[i][j-1],dp[i-1][j-m] + sum[j] - sum[j-m]);
        }
    }
    std::cout << dp[3][n];
    return 0;
}