#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int maxY = 0;
    string result = "";
    for (int i = 0; i < n; i++)
    {
        string s;
        int y;
        cin >> s >> y;

        if (y > maxY)
        {
            maxY = y;
            result = s;
        }
    }
    cout << result << '\n';
}