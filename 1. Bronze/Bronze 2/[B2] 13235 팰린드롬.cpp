#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    string t = s;
    reverse(t.begin(), t.end());

    cout << (t == s ? "true" : "false") << '\n';
}