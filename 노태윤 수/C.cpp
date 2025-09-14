#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeNextPalin(string& p)
{
    int d = p.size();
    int h = d / 2 - (~d & 1);
    int i = 0;
    while (h - i >= 0)
    {
        char v = (p[h - i] - '0' + 1) % 10 + '0';
        p[h - i] = p[h + i + (~d & 1)] = v;

        if (v != '0')
            break;
        i++;
    }

    if (p[0] == '0')
        p = '1' + string(d - 1, '0') + '1';
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
        MakeNextPalin(p);
        if (stoll(p) > n)
            break;
        result++;
    }
    cout << result << '\n';
}