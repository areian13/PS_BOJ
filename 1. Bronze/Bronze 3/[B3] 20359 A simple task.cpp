#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int o = 0, p = 0;
    if (n > 0)
    {
        int temp = n;
        while (true)
        {
            if (temp % 2 == 0)
            {
                p++;
                temp /= 2;
            }
            else
                break;
        }
        o = temp;
    }
    cout << o << ' ' << p << '\n';
}