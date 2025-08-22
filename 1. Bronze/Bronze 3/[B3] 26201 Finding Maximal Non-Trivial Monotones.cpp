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

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
            continue;

        int l = 0;
        while (i + l + 1 < n && s[i + l + 1] == 'a')
            l++;

        result += l == 0 ? 0 : l + 1;
        i += l;
    }

    cout << result << '\n';
}