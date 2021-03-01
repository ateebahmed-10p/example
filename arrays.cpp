#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int len = 0 ;
    scanf("%d" , &len);
    int arr[len];
    for (int i = 0; i<len ; i++)
        scanf("%d" , &arr[i]);

    for (int i = len-1 ; i >= 0 ; i-- )
        printf("%d ", arr[i] );

    return 0;
}
