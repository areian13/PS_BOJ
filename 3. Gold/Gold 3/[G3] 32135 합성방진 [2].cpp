#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void MakeRow(int u, vector<int>& a, vector<bool>& isUsed, bool& find)
{
    int n = a.size();
    if (u == n)
    {
        find = !isPrime(a[n - 1] + a[0]);
        return;
    }

    for (int i = 2; i <= n; i++)
    {
        if (isUsed[i] || isPrime(a[u - 1] + i))
            continue;

        a[u] = i;
        isUsed[i] = true;
        MakeRow(u + 1, a, isUsed, find);
        isUsed[i] = false;

        if (find)
            break;
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    vector<bool> isUsed(n + 1, false);
    a[0] = 1, isUsed[1] = true;
    bool find = false;
    MakeRow(1, a, isUsed, find);

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[(i + j) % n] << ' ';
        cout << '\n';
    }
}