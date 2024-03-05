#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsFibo(vector<int>& x)
{
    int k = x.size();
    for (int i = 2; i < k; i++)
    {
        if (x[i] != x[i - 1] + x[i - 2])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int k;
        cin >> k;

        vector<int> x(k);
        for (int i = 0; i < k; i++)
            cin >> x[i];

        string result = IsFibo(x) ? "YES" : "NO";
        cout << result << '\n';
    }
}