#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 9

bool In99(int n)
{
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 1; j <= MAX; j++)
        {
            if (i * j == n)
                return true;
        }
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    bool result = In99(n);
    if (result)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}