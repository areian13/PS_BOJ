#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxInc(vector<int>& a)
{
    int n = a.size();
    int result = 1;
    int i = 0, j = 1;
    while (j < n)
    {
        if (a[j - 1] > a[j])
            i = j;

        j++;
        result = max(result, j - i);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int p = MaxInc(a);
    reverse(a.begin(), a.end());
    int q = MaxInc(a);
    reverse(a.begin(), a.end());

    int result = max(p, q);
    cout << result << '\n';
}