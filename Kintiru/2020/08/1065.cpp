#include <iostream>
#include <string>

int main()                                                          {
    int n, count                                                    ;
    std::cin >> n                                                   ;
    if(n < 100)                                                     {
        std::cout << n                                              ;}
    else                                                            {
        count = 99                                                  ;
        for(int i = 100; i <= n; ++i)                               {
            std::string s = std::to_string(i)                       ;
            if(((int)s[0])-((int)s[1]) == ((int)s[1])-((int)s[2]))  {
                count++                                             ;}}
        std::cout << count                                          ;}
    return 0                                                        ;}