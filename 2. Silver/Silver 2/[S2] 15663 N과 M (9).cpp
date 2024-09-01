#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void PrintNM(int k, vector<int>& result, vector<bool>& isUsed, vector<int>& arr)
{


    int n = arr.size();
    int m = result.size();

    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isUsed[i])
            continue;
        if (i > 0 && arr[i] == arr[i - 1] && !isUsed[i - 1])
            continue;

        isUsed[i] = true;
        result[k] = arr[i];
        PrintNM(k + 1, result, isUsed, arr);
        isUsed[i] = false;
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<bool> isUsed(n, false);
    vector<int> result(m);
    PrintNM(0, result, isUsed, arr);
}