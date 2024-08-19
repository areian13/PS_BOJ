#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<char, int> p;
    p['A'] = 4;
    p['K'] = 3;
    p['Q'] = 2;
    p['J'] = 1;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (char c : s)
            result += p[c];
    }
    cout << result << '\n';
}