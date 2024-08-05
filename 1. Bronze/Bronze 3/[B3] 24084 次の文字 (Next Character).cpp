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

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i + 1] == 'J')
            cout << s[i] << '\n';
    }
}