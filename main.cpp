#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Print(vector<int>& arr)
{
    for (int x : arr)
        cout << x << ' ';
    cout << '\n';
}

void Merge(int start, int mid, int end, vector<int>& arr, bool order)
{
    int n = end - start + 1;
    vector<int> temp(n);

    int l = start;
    int r = mid + 1;
    int t = 0;
    while (l <= mid && r <= end)
        temp[t++] = (order ^ (arr[l] <= arr[r])) ? arr[l++] : arr[r++];

    int s = (l <= mid ? l : r);
    int e = (l <= mid ? mid : end);
    for (int i = s; i <= e; i++)
        temp[t++] = arr[i];

    for (int i = start; i <= end; i++)
        arr[i] = temp[i - start];
}

void MergeSort(int start, int end, vector<int>& arr, bool order = 0)
{
    if (start == end)
        return;

    int mid = (start + end) / 2;
    MergeSort(start, mid, arr, order);
    MergeSort(mid + 1, end, arr, order);
    Merge(start, mid, end, arr, order);
}

int main()
{
    FastIO;

    vector<int> arr, temp = { 2,6,4,3,7,8,1,9,5,0 };

    arr = temp;
    MergeSort(0, arr.size() - 1, arr);
    Print(arr);

    arr = temp;
    MergeSort(0, arr.size() - 1, arr, 1);
    Print(arr);
}