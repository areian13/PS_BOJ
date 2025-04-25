#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            for (int j = 0; j < i; j++)
                result += (a[j] <= a[i]);
        }
        cout << result << '\n';
    }
}