#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<string> words(5);
    for (int i = 0; i < 5; i++)
        cin >> words[i];

    string result = "";
    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (j < words[i].size())
                result.push_back(words[i][j]);
        }
    }
    cout << result << '\n';
}