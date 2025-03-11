#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsSpecial(int x)
{
    return x == (x / 100 + x % 100) * (x / 100 + x % 100);
}

int main()
{
    FastIO;

    int x;
    cin >> x;

    int result = -1;
    for (int i = x + 1; i < 10'000; i++)
    {
        if (IsSpecial(i))
        {
            result = i;
            break;
        }
    }
    cout << result << '\n';
}