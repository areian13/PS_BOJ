#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, k;
        cin >> n >> k;

        if (cin.eof())
            break;

        int result = 0;
        int cnt = 0;
        while (n > 0)
        {
            result += n;
            
            cnt += n;
            n = cnt / k;
            cnt %= k;
        }
        cout << result << '\n';
    }
}