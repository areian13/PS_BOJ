#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> cnt(n);
    for (int i = 0; i < n * 2 - 1; i++)
    {
        int a;
        cin >> a;

        cnt[a - 1]++;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 1)
        {
            result = i;
            break;
        }
    }
    cout << result + 1 << '\n';
}