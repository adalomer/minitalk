
#include <stdio.h>
#include <unistd.h>


int main()
{
    // int a = 3;
    // int b = 1;
    // printf("%d\n",a & b); // 11 01
    // a = 2;
    // printf("%d\n",a & b); // 10 01
    // a = 4;
    // printf("%d \n",a & b); //100 01
    // a = 5;
    // printf("%d\n",a & b); //101 1
    // a = a >> 1;
    // printf("%d", a & b);

    char a;
    a = 'a'; //97 //1100001 32 16
    char d;
    
    if ( a > 127)
        return(write(1,"hata",4));
    d = a;
    d = d >> 1;
    printf("%c",d);
}
