#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    vector<int> px, cx;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P')
            px.push_back(i);
        else if (s[i] == 'C')
            cx.push_back(i);
    }

    int k = min(px.size(), cx.size());
    for (int i = 0; i < k; i++)
        swap(s[px[i]], s[cx[i]]);

    cout << s << '\n';
}