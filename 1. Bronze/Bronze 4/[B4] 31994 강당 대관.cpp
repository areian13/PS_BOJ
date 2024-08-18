#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 7

int main()
{
    FastIO;

    string result = "";
    int maxPeople = 0;
    for (int i = 0; i < MAX; i++)
    {
        string name;
        int people;
        cin >> name >> people;

        if (people > maxPeople)
        {
            result = name;
            maxPeople = people;
        }
    }
    cout << result << '\n';
}