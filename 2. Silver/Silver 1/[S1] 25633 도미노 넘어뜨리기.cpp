#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxDomino(int d, vector<int>& a)
{
    int n = a.size();

    int result = 1;
    int cand = 0;
    int w = a[d];
    for (int i = d + 1; i < n; i++)
    {
        if (w >= a[i])
        {
            w += a[i];
            result++;
        }
        else
            cand = max(cand, MaxDomino(i, a));
    }
    return max(result, cand);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = MaxDomino(0, a);
    cout << result << '\n';
}