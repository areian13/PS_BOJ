#include <iostream>
#include <array>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool MoreDraw(int sum, array<int, 12>& cnt)
{
    if (sum >= 21)
        return false;

    int x = min(21 - sum, 11);
    int under = accumulate(cnt.begin(), cnt.begin() + x + 1, 0);
    int over = accumulate(cnt.begin() + x, cnt.end(), 0);

    return over < under;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 12> cnt = { 0,0,4,4,4,4,4,4,4,4,12,4 };
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        sum += a;
        cnt[a]--;
    }

    bool result = MoreDraw(sum, cnt);
    if (result == true)
        cout << "VUCI" << '\n';
    else
        cout << "DOSTA" << '\n';
}