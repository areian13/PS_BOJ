#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t;
    cin >> t;

    unordered_map<string, char> code;
    for (int i = 0; i < t; i++)
    {
        char c;
        string bin;
        cin >> c >> bin;

        code[bin] = c;
    }

    string n;
    cin >> n;

    string result = "";
    for (int i = 0; i < n.size(); i += 4)
        result += (code[n.substr(i, 4)] != '\0' ? code[n.substr(i, 4)] : '?');
    cout << result << '\n';
}