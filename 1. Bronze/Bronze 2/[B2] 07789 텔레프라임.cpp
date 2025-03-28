#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPrime(int n)
{
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    bool result = IsPrime(stoi(a)) && IsPrime(stoi(b + a));
    if (result == true)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}