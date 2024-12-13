#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        array<bool, 10> isExisted = { false, };
        int result = 1;
        while (true)
        {
            long long k = 1LL * n * result;
            do
            {
                isExisted[k % 10] = true;
                k /= 10;
            } while (k > 0);

            bool isAll = true;
            for (int i = 0; i < 10; i++)
                isAll &= isExisted[i];

            if (isAll)
                break;

            result++;
        }
        cout << result << '\n';
    }
}