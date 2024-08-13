#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, int> scolville;
    scolville["Poblano"] = 1'500;
    scolville["Mirasol"] = 6'000;
    scolville["Serrano"] = 15'500;
    scolville["Cayenne"] = 40'000;
    scolville["Thai"] = 75'000;
    scolville["Habanero"] = 125'000;

    int n;
    cin >> n;

    int result = 0;
    while (n--)
    {
        string pepper;
        cin >> pepper;

        result += scolville[pepper];
    }
    cout << result << '\n';
}