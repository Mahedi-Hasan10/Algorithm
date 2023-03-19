/*
     Author : Mahedi-Hasan10
     Date : 17-03-2023
     Topic: Calculate the value of n to the power m using recursion
*/
#include <bits/stdc++.h>
using namespace std;
int POW(int n, int m)
{
    if (m != 0)
    {
        return n * POW(n, m - 1);
    }
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << POW(n, m) << "\n";
    return 0;
}