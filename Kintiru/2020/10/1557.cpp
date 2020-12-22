#include <cstdio>

long long int K;
long long int low, high;
long long int mobius[1000001];

/*
 * GOAL: Set Mobius function
 */
void getMobius() {
    //set all values to 1
    for(int i = 1; i <= 1000000; ++i)
        mobius[i] = 1;

    for(int i = 2; i * i <= 1000000; ++i) {
        if(mobius[i] == 1) {

            for(int j = i*i; j <= 1000000; j += i*i) {
                mobius[j] = 0;
            }
            for(int j = i; j <= 1000000; j+=i) {
                mobius[j] *= -i;
            }
        }
    }
    for (int i = 2; i <= 1000000; i++)
    {
        if (mobius[i] == i) mobius[i] = 1;
        else if (mobius[i] == -i) mobius[i] = -1;
        else if (mobius[i] < 0) mobius[i] = 1;
        else if (mobius[i] > 0) mobius[i] = -1;
    }
}

long long int squareFree(long long int n){
    long long int k = 0;
    for(long long int i = 1; i*i <= n; ++i)
        k += (mobius[i]*(n/(i*i)));
    return k;
}

int main() {
    low = 0;
    high = 1e12;
    scanf("%lld", &K);
    getMobius();
    while(low + 1 < high) {
        long long int mid = (low + high) / 2;
        if(squareFree(mid) < K)
            low = mid;
        else high = mid;
    }

    printf("%lld", high);

    return 0;
}
