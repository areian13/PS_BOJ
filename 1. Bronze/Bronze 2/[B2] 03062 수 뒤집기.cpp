#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string n;
        cin >> n;

        string r = n;
        reverse(r.begin(), r.end());

        string sum = to_string(stoi(n) + stoi(r));
        string rev = sum;
        reverse(rev.begin(), rev.end());

        if (sum == rev)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}