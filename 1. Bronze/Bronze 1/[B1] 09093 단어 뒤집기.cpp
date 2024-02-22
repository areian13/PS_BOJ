#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    cin.ignore();
    while (tc--)
    {
        string str;
        getline(cin, str);

        stringstream ss(str);
        string result;

        while (ss >> result)
        {
            reverse(result.begin(), result.end());
            cout << result << ' ';
        }
        cout << '\n';
    }
}