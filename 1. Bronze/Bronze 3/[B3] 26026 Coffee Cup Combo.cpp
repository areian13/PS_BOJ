#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    int coffee = 0;
    for (int i = 0; i < n; i++)
    {
        char bit;
        cin >> bit;

        if (bit == '1')
        {
            coffee = 2;
            result++;
        }
        else if (coffee > 0)
        {
            coffee--;
            result++;
        }
    }
    cout << result << '\n';
}