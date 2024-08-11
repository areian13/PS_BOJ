#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPattern(vector<int>& a)
{
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == a[i] % 2)
            return false;
    }
    return true;
}

array<int, 2> PatternIndex(vector<int>& a)
{
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i == j)
                continue;

            swap(a[i], a[j]);
            if (IsPattern(a))
                return { i + 1,j + 1 };
            else
                swap(a[i], a[j]);
        }
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    array<int, 2> result = PatternIndex(a);
    cout << result[0] << ' ' << result[1] << '\n';
}