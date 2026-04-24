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

    int result = 5;
    for (int i = 0; i < n - 4; i++)
    {
        string e = s.substr(i, 5);
        int cnt = 0;
        for (int i = 0; i < 5; i++)
            cnt += (e[i] != "eagle"[i]);
        result = min(result, cnt);
    }
    cout << result << '\n';
}