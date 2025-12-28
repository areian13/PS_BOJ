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

    char p = 'A';
    int result = 0;
    for (char c : s)
    {
        result += min(abs(c - p), abs(abs(c - p) - 26));
        p = c;
    }
    cout << result << '\n';
}