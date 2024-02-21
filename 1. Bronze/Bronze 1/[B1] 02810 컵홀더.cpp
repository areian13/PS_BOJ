#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string seat;
    cin >> n >> seat;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (seat.substr(i, 2) == "LL")
        {
            cnt++;
            i++;
        }
    }
    int result = (cnt <= 1 ? n : n - cnt + 1);
    cout << result << '\n';
}