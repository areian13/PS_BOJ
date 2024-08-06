#include <iostream>
#include <string>
#include <sstream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string str;
    getline(cin, str);

    stringstream ss(str);
    string temp;
    while (ss >> temp)
    {
        int n = stoi(temp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n * 2 - i; j++)
            {
                char result = (j == i || j == 2 * n - i - 2 ? '*' : ' ');
                cout << result;
            }
            cout << '\n';
        }
    }
}