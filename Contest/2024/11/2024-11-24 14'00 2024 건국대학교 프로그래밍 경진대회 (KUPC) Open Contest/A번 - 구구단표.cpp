#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 9

bool In99(int n)
{
    if (n == 1)
        return true;
    if (n > MAX * MAX)
        return false;
    for (int i = 2; i <= MAX; i++)
    {
        if (n % i == 0)
            return true;
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