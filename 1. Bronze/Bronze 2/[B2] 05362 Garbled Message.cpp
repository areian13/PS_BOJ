#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string str;
        getline(cin, str);

        if (!cin)
            break;

        int n = str.size();
        string result = "";
        for (int i = 0; i < n; i++)
        {
            if (str.substr(i, 5) != "iiing")
                result += str[i];
            else
            {
                result += "th";
                i += 4;
            }
        }
        cout << result << '\n';
    }
}