#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10
#define MOD 5

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        bool isAllCorrect = true;
        for (int j = 0; j < MAX; j++)
        {
            int a;
            cin >> a;

            isAllCorrect &= (a == j % MOD + 1);
        }

        if (isAllCorrect)
            cout << i + 1 << '\n';
    }
}