#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int v, vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == v)
            return i;
    }
    return -1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> result;
    while (!a.empty())
    {
        int aidx = max_element(a.begin(), a.end()) - a.begin();
        int bidx = Find(a[aidx], b);

        if (bidx != -1)
        {
            result.push_back(a[aidx]);
            a.erase(a.begin(), a.begin() + aidx + 1);
            b.erase(b.begin(), b.begin() + bidx + 1);
        }
        else
            a.erase(a.begin() + aidx);
    }

    int k = result.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++)
        cout << result[i] << ' ';
    cout << '\n';
}