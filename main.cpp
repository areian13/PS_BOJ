#include <iostream>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    map<string, int> myMap = { pair<string, int>{"banana",1 },{"apple",2 }};
    cout << myMap["banana"];
}