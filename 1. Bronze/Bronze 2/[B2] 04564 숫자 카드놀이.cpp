#include <iostream>
#include <vector>

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

        while (true)
        {
            cout << n << ' ';

            if (n / 10 == 0)
                break;

            int temp = 1;
            while (n > 0)
            {
                temp *= n % 10;
                n /= 10;
            }
            n = temp;
        }
        cout << '\n';
    }
}