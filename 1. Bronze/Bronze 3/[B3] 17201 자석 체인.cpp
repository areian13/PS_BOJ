#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    bool result = true;
    for (int i = 0; i < n - 1; i++)
        result &= (s[i * 2 + 1] != s[(i + 1) * 2]);

    if (result == true)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}