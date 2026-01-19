#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    int t;
    cin >> s >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;

        swap(s[a], s[b]);
    }
    cout << s << '\n';
}