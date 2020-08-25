#include <iostream>
#include <string>

int main(void) {
	std::string S;
	int n, dp[101];
	std::cin >> S >> n;
	std::string A[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> A[i];
	}

	dp[S.length()] = 1;
	for (int p = S.length()-1; p >= 0; --p) {
		for (int j = 0; j < n; j++) {
			if (S.find(A[j], p) == p && dp[p + A[j].length()] == 1) {
				dp[p] = 1;
				break;
			}
			else dp[p] = 0;
		}
	}

	std::cout << dp[0];
	return 0;
}
