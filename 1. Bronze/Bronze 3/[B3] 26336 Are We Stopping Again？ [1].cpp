#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int d, o, f;
        cin >> d >> o >> f;

        vector<bool> isStop(d, false);
        for (int i = o; i < d; i += o)
            isStop[i] = true;
        for (int i = f; i < d; i += f)
            isStop[i] = true;

        int result = accumulate(isStop.begin(), isStop.end(), 0);
        cout << d << ' ' << o << ' ' << f << '\n';
        cout << result << '\n';
    }
}