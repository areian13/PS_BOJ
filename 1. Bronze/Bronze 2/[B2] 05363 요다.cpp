#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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

        vector<string> words;
        string temp;
        stringstream ss(s);
        while (ss >> temp)
            words.push_back(temp);

        int n = words.size();
        for (int i = 0; i < n; i++)
            cout << words[(i + 2) % n] << ' ';
        cout << '\n';
    }
}