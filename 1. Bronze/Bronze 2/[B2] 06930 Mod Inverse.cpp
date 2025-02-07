#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ModInverse(int x, int m)
{
    vector<bool> has(m, false);
    int n = 0;
    while (!has[x * n % m])
    {
        has[x * n % m] = true;
        if (x * n % m == 1)
            return n;
        n++;
    }
    return -1;
}

int main()
{
    FastIO;

    int x, m;
    cin >> x >> m;

    int result = ModInverse(x, m);
    if (result == -1)
        cout << "No such integer exists." << '\n';
    else
        cout << result << '\n';
}