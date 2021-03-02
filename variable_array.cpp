#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; // N : number of elements inside main array
    int Q; // Q : number of queries to be made
    std::vector<std::vector<int>> arr; // arr : main container
    string delim = " ";
    // reading the values of N , Q:
    
    string l;
    std::getline(std::cin, l);
    int mid = l.find(delim);
    N = std::stoi( l.substr(0, mid));
    Q = std::stoi( l.substr(mid, l.length()) );
    arr.reserve(N);
    // reading the sub arrays
    for(int i = 0 ; i < N ; i++)
    {
        string s;
        std::getline(cin , s);

        // splitting the string 
        s = s + ' ';
        string token;
        int pos = 0;
        vector<int> subarr;

        int f = s.find(delim);
        int subarr_length = std::stoi(s.substr(0 , f));
        s.erase(0, f + delim.length());
        subarr.reserve(subarr_length);

        while( (pos = s.find(delim)) != string::npos )
        {
            token = s.substr(0,pos);
            s.erase(0, pos + delim.length());
            subarr.push_back( std::stoi(token) );
        }
        
        //append the subarr vector in arr vector:
        arr.push_back( std::move(subarr) );
    }

    // now we have the container to make queries from 
    int i,j;
    int answers[Q];
    for (int k =0 ; k < Q; k++)
    {
        cin >> i;
        cin >> j;
    	answers[k] = arr[i][j];
    }

    for(int o = 0 ; o < Q ; o++)
        printf("%d \n" , answers[o]);
    return 0;
}