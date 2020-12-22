#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

char reverse_case (char c) {
    if (std::isupper(c)) 
        return std::tolower(c); 
    else
        return std::toupper(c); 
}

int main() {
    std::string s;
    std::cin >> s;
    std::transform(s.begin(), s.end(), s.begin(), reverse_case);
    std::cout << s;
    return 0;
}