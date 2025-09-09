#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool HasIn(string& s, vector<string>& howls)
{
    for (string& howl : howls)
    {
        if (s == howl)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    cin.ignore();
    for (int tc = 1; tc <= TC; tc++)
    {
        string sen;
        getline(cin, sen);

        vector<string> howls;
        while (true)
        {
            string howl;
            getline(cin, howl);

            if (howl == "what does the fox say?")
                break;

            stringstream ss(howl);
            ss >> howl >> howl >> howl;
            howls.push_back(howl);
        }

        stringstream ss(sen);
        string result;
        while (ss >> result)
        {
            if (!HasIn(result, howls))
                cout << result << ' ';
        }
        cout << '\n';
    }
}