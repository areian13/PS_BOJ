#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        array<int, MAX + 1> cnt = { 0, };
        for (int i = 0; i < n; i++)
        {
            char c;
            int a, b;
            cin >> c >> a >> b;

            for (int j = a; j < b; j++)
                cnt[j]++;
        }

        string result = "";
        for (int i = 0; i <= MAX; i++)
        {
            if (cnt[i] == 0)
                continue;
            result += 'A' + cnt[i] - 1;
        }
        cout << result << '\n';
    }
}