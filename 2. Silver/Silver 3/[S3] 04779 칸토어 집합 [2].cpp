#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsCantor(int i, int k)
{
    if ((i / k) % 3 == 1)
        return false;
    if (k == 1)
        return true;
    return IsCantor(i, k / 3);
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

        for (int i = 0; i < k; i++)
        {
            char result = IsCantor(i, k) ? '-' : ' ';
            cout << result;
        }
        cout << '\n';
    }
}