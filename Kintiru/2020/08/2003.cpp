#include <iostream>

int N, M;

int main() {
    std::cin >> N >> M;
    int arr[N], sum = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    int begin = 0, cnt = 0, i = 0;
    while (i <= N) {
        if (sum == M) {
            cnt++;
            sum -= arr[begin++];
        }
        else if(sum < M) {
            sum += arr[i++];
        }
        else if(sum > M) { 
            sum -= arr[begin++];
        }
    }
    std::cout << cnt;
    return 0;
}