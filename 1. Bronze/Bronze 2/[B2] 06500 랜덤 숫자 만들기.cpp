#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000
const int n = 4;

int NextA(int a)
{
    string sa = to_string(a * a);
    while (sa.size() < n * 2)
        sa = '0' + sa;
    return stoi(sa.substr(n / 2, n));
}

int main()
{
    FastIO;

    while (true)
    {
        int a0;
        cin >> a0;

        if (a0 == 0)
            break;

        array<bool, MAX> has = { false, };
        has[a0] = true;

        int ai = a0;
        int result = 1;
        while (true)
        {
            int na = NextA(ai);
            if (has[na])
                break;

            ai = na;
            has[na] = true;
            result++;
        }
        cout << result << '\n';
    }
}