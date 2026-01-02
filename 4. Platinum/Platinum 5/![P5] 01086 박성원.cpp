#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int k;
    cin >> k;

    vector<long long> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (char c : s[i])
            a[i] = (a[i] * 10 + c - '0') % k;
    }


}