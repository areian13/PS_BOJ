#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsIn(int num, vector<int>& a)
{
    int start = 0;
    int end = a.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (a[mid] < num)
            start = mid + 1;
        else if (num < a[mid])
            end = mid - 1;
        else
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int result = n;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        result += (IsIn(num, a) ? -1 : +1);
    }
    cout << result << '\n';
}