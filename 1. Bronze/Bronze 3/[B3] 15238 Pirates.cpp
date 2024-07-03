#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string str;
    cin >> n >> str;

    array<int, 26> cnt = { 0, };
    for (int i = 0; i < n; i++)
        cnt[str[i] - 'a']++;

    char alp = '\0';
    int len = 0;
    for (int i = 0; i < 26; i++)
    {
        if (len < cnt[i])
        {
            len = cnt[i];
            alp = i + 'a';
        }
    }
    cout << alp << ' ' << len << '\n';
}