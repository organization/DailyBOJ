#include <iostream>
#include <string>

int main(){
    int n;
    std::cin >> n;
    std::string a[n];
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int groups = 0;
    for(int i = 0; i < n; i++) {
        std::string tmp = "";
        int tmpCount = 0;
        for(int l = 0; l < a[i].length(); l++) {
            if(!(a[i].length() - 1)) {
                groups++;
                goto outer;
            } else if(l == 0) {
                tmp = a[i][l];
            } else {
                if(a[i][l] == tmp[tmpCount]) {
                    continue;
                } else {
                    tmp += a[i][l];
                    tmpCount++;
                }
            }
        }
        for(int j = 0; j < tmpCount; j++) {
            for(int k = j + 1; k <= tmpCount; k++) {
                if(tmp[j] == tmp[k]) goto outer;
            }
        }
        groups++;
        outer:;
    }
    std::cout << groups;
    return 0;
}