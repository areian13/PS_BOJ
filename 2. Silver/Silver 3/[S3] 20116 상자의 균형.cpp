#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsStable(int l, vector<int>& x)
{
    int n = x.size();
    long long sum = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        sum += x[i];
        double mx = 1. * sum / (n - i);
        if (!(x[i - 1] - l < mx && mx < x[i - 1] + l))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, l;
    cin >> n >> l;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    bool result = IsStable(l, x);
    cout << (result ? "stable" : "unstable") << '\n';
}