#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Bubble(vector<int>& a, int k)
{
    int n = a.size();
    int result = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                result++;
            }

            if (result == k)
                return result;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = Bubble(a, k);
    if (cnt < k)
        cout << -1 << '\n';
    else
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
}