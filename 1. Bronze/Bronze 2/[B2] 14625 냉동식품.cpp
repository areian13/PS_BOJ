#include <iostream>
#include <string>
#include <format>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int sh, sm, eh, em, n;
    cin >> sh >> sm >> eh >> em >> n;

    int s = sh * 60 + sm;
    int e = eh * 60 + em;
    int result = 0;
    for (int t = s; t <= e; t++)
    {
        string st = format("{:02d} {:02d}", t / 60, t % 60);
        result += (st.find(n + '0') != -1);
    }
    cout << result << '\n';
}