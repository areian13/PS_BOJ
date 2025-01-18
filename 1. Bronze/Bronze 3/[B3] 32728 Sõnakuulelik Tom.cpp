#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    array<string, 3> result = { "", };
    array<int, 26> idx = { 0, };
    idx['s' - 'a'] = 0;
    idx['r' - 'a'] = 1;
    idx['p' - 'a'] = 2;
    for (char c : s)
    {
        int p = 0;
        while (result[(idx[c - 'a'] + p) % 3].size() == k)
            p++;

        result[(idx[c - 'a'] + p) % 3] += c;
    }

    for (int i = 0; i < 3; i++)
        cout << result[i] << '\n';
}