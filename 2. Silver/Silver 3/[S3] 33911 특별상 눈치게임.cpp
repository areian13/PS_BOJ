#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> cnt(101, 0);
    for (int i = 0; i < n * 3; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int result = 0, selected = 0, deleted = 0;
    for (int i = 100; i >= 1; i--)
    {
        if (cnt[i] == 0)
        {
            int k = 99 - selected - deleted;
            result += (deleted == 2 ? 1 : (deleted == 1 ? k : k * (k - 1) / 2));
            selected++;
        }
        else if (cnt[i] == 1)
            deleted++;

        if (deleted >= 3)
            break;
    }
    cout << result << '\n';
}