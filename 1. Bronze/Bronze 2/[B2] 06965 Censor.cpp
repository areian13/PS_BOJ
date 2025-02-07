#include <iostream>
#include <string>
#include <sstream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    cin.ignore();
    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string result = "";
        while (ss >> result)
        {
            if (result.size() == 4)
                result = "****";
            cout << result << ' ';
        }
        cout << "\n\n";
    }
}