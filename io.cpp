#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i = 0;
    long l = 0;
    char c;
    float f = 0;
    double d = 0;
    scanf("%d %ld %c %f %lf" , &i , &l , &c , &f , &d);
    printf("%d \n", i);
    printf("%ld \n", l);
    printf("%c \n", c);
    printf("%f \n", f);
    printf("%lf \n", d);
    return 0;
}