#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result;
    int maxB = 0;
    for (int i = 0; i < n; i++)
    {
        string a;
        int b;
        cin >> a >> b;

        if (b > maxB || b == maxB && a < result)
        {
            maxB = b;
            result = a;
        }
    }
    cout << result << '\n';
}