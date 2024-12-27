#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        int pre = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            if (pre != a)
                cout << a << ' ';

            pre = a;
        }
        cout << '$' << '\n';
    }
}