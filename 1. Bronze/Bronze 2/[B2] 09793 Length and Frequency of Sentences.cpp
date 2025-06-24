#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 75

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, MAX + 1> result = { 0, };
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        int k = s.size();
        int cnt = 1;
        for (int j = 0; j < k - 1; j++)
            cnt += (s[j] == ' ' && s[j] != s[j + 1]);
        result[cnt]++;
    }

    for (int i = 1; i <= MAX; i++)
    {
        if (result[i] != 0)
            cout << i << ' ' << result[i] << '\n';
    }
}