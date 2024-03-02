#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<char, int> notes;
    notes['W'] = 64;
    notes['H'] = 32;
    notes['Q'] = 16;
    notes['E'] = 8;
    notes['S'] = 4;
    notes['T'] = 2;
    notes['X'] = 1;

    while (true)
    {
        string str;
        cin >> str;

        if (str == "*")
            break;

        int n = str.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int beat = 0;
            while (str[i] != '/')
            {
                beat += notes[str[i]];
                i++;
            }
            result += (beat == 64);
        }
        cout << result << '\n';
    }
}