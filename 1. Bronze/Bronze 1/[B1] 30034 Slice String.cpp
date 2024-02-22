#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<char, bool> isSeparator;
    for (int i = 0; i < n; i++)
    {
        char separator;
        cin >> separator;

        isSeparator[separator] = true;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        char separator;
        cin >> separator;

        isSeparator[separator] = true;
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        char merger;
        cin >> merger;

        isSeparator[merger] = false;
    }
    isSeparator[' '] = true;

    int s;
    string x;
    cin >> s;

    cin.ignore();
    getline(cin, x);

    vector<string> result;
    for (int i = 0; i < s; i++)
    {
        string word = "";
        while (i < s && !isSeparator[x[i]])
        {
            word += x[i];
            i++;
        }

        if (word != "")
            result.push_back(word);
    }

    for (string& word : result)
        cout << word << '\n';
}