#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; // N : number of elements inside main array
    int Q; // Q : number of queries to be made
    
    cin >> N >> Q;
    std::vector<std::vector<int>*> arr; // arr : main container
    arr.reserve(N);

    // reading the sub arrays
    for(int i = 0 ; i < N ; i++)
    {
        vector<int>* subarr = new vector<int>;
        int k;
        cin >> k;
        subarr->reserve(k);
        for (int j = 0 ; j < k ; j++)
        {
            cin >> (*subarr)[j];
        }
        arr.push_back( subarr );
    }

    // now we have the container to make queries from 
    int i,j;
    for (int k =0 ; k < Q; k++)
    {
        cin >> i >> j;
    	cout << (*arr[i])[j] << endl;
    }

    return 0;
}