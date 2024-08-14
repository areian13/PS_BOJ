#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int m = s.size();
        for (int j = 0; j < m - 1; j++)
        {
            string sub = s.substr(j, 2);
            if (sub == "01" || sub == "OI")
            {
                result++;
                break;
            }
        }
    }
    cout << result << '\n';
}