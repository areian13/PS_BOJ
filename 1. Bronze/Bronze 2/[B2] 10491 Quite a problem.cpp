#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool HasProblem(string& s)
{
    int n = s.size();
    for (int i = 0; i < n - 6; i++)
    {
        string problem = s.substr(i, 7);
        for (char& c : problem)
            c |= 32;

        if (problem == "problem")
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
        if (result)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}