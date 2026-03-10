#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsInteger(vector<int>& a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == j || j == k || k == i)
                    continue;
                if ((a[i] - a[j]) % a[k] != 0)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool result = IsInteger(a);
    cout << (result ? "yes" : "no") << '\n';
}