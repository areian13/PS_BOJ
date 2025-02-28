#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeNextP(string& p)
{
    int n = p.size();

    int i = 0;
    while (i <= n / 2 - (n % 2 == 0))
    {
        char k = (p[n / 2 + i] - '0' + 1) % 10 + '0';
        p[n / 2 + i] = k;
        p[n / 2 - i - (n % 2 == 0)] = k;
        i++;

        if (k != '0')
            break;
    }

    if (p[0] == '0')
        p = '1' + string(n - 1, '0') + '1';
}

int main()
{
    FastIO;

    long long n;
    cin >> n;

    string p = "0";
    int result = 0;
    while (true)
    {
        MakeNextP(p);
        if (stoll(p) > n)
            break;
        result++;
    }

    cout << result << '\n';
}