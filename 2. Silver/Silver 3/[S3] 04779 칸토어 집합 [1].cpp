#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeCantor(int start, int end, string& result)
{
    if (start == end)
        return;

    int m1 = start + (end - start) * 1 / 3;
    int m2 = start + (end - start) * 2 / 3;

    for (int i = m1 + 1; i <= m2; i++)
        result[i] = ' ';

    MakeCantor(start, m1, result);
    MakeCantor(m2 + 1, end, result);
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        int k = pow(3, n);

        string result(k, '-');
        MakeCantor(0, k - 1, result);
        cout << result << '\n';
    }
}