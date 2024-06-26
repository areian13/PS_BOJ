#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        array<int, 2> cnt = { 0,0 };
        do
        {
            cnt[n % 2]++;
            n /= 2;
        } while (n > 0);

        string result = (cnt[0] == cnt[1] ? "straight" : (cnt[0] > cnt[1] ? "left" : "right"));
        cout << result << '\n';;
    }
}