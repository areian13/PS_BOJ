#include <iostream>
#include <climits>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = "";
    int minL = INF;
    for (int i = 0; i < n; i++)
    {
        string s;
        int l;
        cin >> s >> l;

        if (l < minL)
        {
            minL = l;
            result = s;
        }
    }
    cout << result << '\n';
}