#include<iostream>
#include<unordered_set>
using namespace std;
bool isSubArrayZero(int arr[], int n)
{
    unordered_set<int> Set;
    int sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        sum += arr[i];
        if (sum == 0 || Set.find(sum) != Set.end())
            return true;
        Set.insert(sum);
    }
    return false;
}
int main()
{
    int arr[] = {-3, 2, 1, 9, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (isSubArrayZero(arr, n))
        cout << "Yes, a sub-array with sum 0 exist";
    else
        cout << "No, a sub-array with sum 0 does not exist";
    return 0;
}
