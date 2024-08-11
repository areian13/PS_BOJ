#include <iostream>
#include <vector>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> SamePrePost(vector<string>& a)
{
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 1; k <= min(a[i].size(), a[j].size()); k++)
            {
                if (a[i].substr(0, k) == a[j].substr(a[j].size() - k, k))
                    return { i + 1,j + 1 };
            }
        }
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    array<int, 2> result = SamePrePost(a);
    if (result[0] == -1)
        cout << -1 << '\n';
    else
        cout << result[0] << ' ' << result[1] << '\n';
}