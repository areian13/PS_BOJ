#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Histo(int s, int e, vector<int>& h)
{
    if (s > e) return 0;
    if (s == e) return h[s];

    int m = (s + e) / 2;
    int result = max(Histo(s, m, h), Histo(m + 1, e, h));

    int l = m, r = m, d = h[m], w = 1;
    while (s <= l && r <= e)
    {
        int ld = s < l ? min(d, h[l - 1]) : 0;
        int rd = r < e ? min(d, h[r + 1]) : 0;

        if (ld >= rd)
        {
            d = ld;
            l--;
        }
        else
        {
            d = rd;
            r++;
        }
        result = max(result, ++w * d);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int result = Histo(0, n - 1, h);
    cout << result << '\n';
}