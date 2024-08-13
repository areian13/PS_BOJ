#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountInZero(string& k)
{
    int n = k.size();

    int l = 0;
    while (l < n && k[l] == '0')
        l++;

    int r = n - 1;
    while (r >= 0 && k[r] == '0')
        r--;

    int result = 0;
    for (int i = l; i <= r; i++)
        result += (k[i] == '0');
    return result;
}

int main()
{
    FastIO;

    string k;
    cin >> k;

    int result = CountInZero(k);
    cout << result << '\n';
}