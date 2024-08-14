#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> caps(n);
    for (int i = 0; i < n; i++)
        cin >> caps[i];

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        for (int j = l; j <= r; j++)
            cout << caps[j] << '\n';
    }
}