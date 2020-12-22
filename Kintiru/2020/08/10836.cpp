#include <iostream>

int c[701][701], outside[1400];

void getFirst(int m, int d) {
    int row = m - 1, col=0;
    for (int i = 0; i < 2 * m - 1; ++i){
        if (row == 0) {
            c[row][col] = outside[i];
            col++;
        } else {
            c[row][col] = outside[i];
            row--;
        }
    }

}

void process(int m, int n) {
    getFirst(m, n);
    for(int j = 1; j < m; ++j) { //가로열 루프 left to right
        for(int l = 1; l < m; ++l) {
            c[l][j] = c[0][j];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n, a, b, z;
    std::cin >> m >> n;

    //set all value that are needed to 1
    for (int i = 0; i < 2*m-1; ++i) {
        outside[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b >> z;
        for (int j = a + b - 1; j >= a; --j) {
            outside[j] += 1;
        }
        for (int j = 2*m-2; j >= a + b ; --j) {
            outside[j] += 2;
        }
    }

    process(m,n);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j){
            std::cout << c[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}