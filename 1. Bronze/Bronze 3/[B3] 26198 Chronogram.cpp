#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<char, int> chrono;
    chrono['I'] = 1;
    chrono['V'] = 5;
    chrono['X'] = 10;
    chrono['L'] = 50;
    chrono['C'] = 100;
    chrono['D'] = 500;
    chrono['M'] = 1'000;

    int tc;
    cin >> tc;

    cin.ignore();
    while (tc--)
    {
        string line;
        getline(cin, line);

        int result = 0;
        for (char c : line)
            result += chrono[c];
        cout << result << '\n';
    }
}