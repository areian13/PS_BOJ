#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        vector<string> word;
        string temp;
        while (ss >> temp)
            word.push_back(temp);

        int k = word.size();

        string result = "god";
        for (int i = 1; i < k; i++)
            result += word[i];

        cout << result << '\n';
    }
}