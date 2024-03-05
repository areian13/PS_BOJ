#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string BinSum(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);

    int n = a.size();
    int m = b.size();

    int gap = n - m;

    for (int i = n - 1; i >= gap; i--)
        a[i] += b[i - gap] - '0';

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= '2')
        {
            a[i] -= 2;
            if (i == 0)
                a = '1' + a;
            else
                a[i - 1]++;
        }
    }

    int idx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != '0')
            break;
        idx++;
    }

    return a.substr(idx);
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    string result = BinSum(a, b);
    cout << result << '\n';
}