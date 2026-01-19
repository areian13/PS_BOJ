#include <iostream>
#include <unordered_set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHappy(int n, unordered_set<int>& check)
{
    if (n == 1) return true;
    if (check.count(n)) return false;

    check.insert(n);
    int k = 0;
    while (n > 0)
    {
        int d = n % 10;
        k += d * d;
        n /= 10;
    }
    return IsHappy(k, check);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_set<int> check;
    bool result = IsHappy(n, check);
    cout << (result ? "HAPPY" : "UNHAPPY") << '\n';
}