/*
     Author : Mahedi-Hasan10
     Date : 31-03-2023
     Topic:
*/
#include <bits/stdc++.h>
using namespace std;
int getSum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return getSum(arr, n - 1) + arr[n - 1];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getSum(arr, n) << "\n";
    return 0;
}