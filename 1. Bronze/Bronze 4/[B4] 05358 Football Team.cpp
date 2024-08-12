#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string name;
        getline(cin, name);

        if (cin.eof())
            break;

        for (char& c : name)
        {
            if ((c | 32) == 'e')
                c += 4;
            else if ((c | 32) == 'i')
                c -= 4;
        }
        cout << name << '\n';
    }
}