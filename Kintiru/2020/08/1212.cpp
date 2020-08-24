#include <stdio.h>

int main()
{
    char octnum[333335];
    long i = 0;
    scanf("%s", octnum);
    
    while (octnum[i])
    {
        switch (octnum[i])
        {
        case '0':
            if(i!=0l) printf("000");
            else {printf("0");}
            break;
        case '1':
            if(i == 0l) printf("1");
            else {printf("001");}
            break;
        case '2':
            if(i == 0l) printf("10");
            else {printf("010");}
            break;
        case '3':
            if(i == 0l) printf("11");
            else {printf("011");}
            break;
        case '4':
            printf("100"); break;
        case '5':
            printf("101"); break;
        case '6':
            printf("110"); break;
        case '7':
            printf("111"); break;
        }
        i++;
    }
    return 0;
}