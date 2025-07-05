#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool HasProblem(string& s)
{
    int n = s.size();
    for (int i = 0; i < n - 6; i++)
    {
        string p = s.substr(i, 7);
        for (char& c : p)
            c |= 32;
        if (p == "problem")
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (cin.eof())
            break;

        bool result = HasProblem(s);
        if (result == true)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}