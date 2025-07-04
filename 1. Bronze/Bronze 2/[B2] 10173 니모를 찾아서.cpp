#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "EOI")
            break;

        bool result = false;
        int n = s.size();
        for (int i = 0; i < n - 3; i++)
        {
            string nemo = s.substr(i, 4);
            for (char& c : nemo)
                c |= 32;
            result |= (nemo == "nemo");
        }

        if (result == true)
            cout << "Found" << '\n';
        else
            cout << "Missing" << '\n';
    }
}