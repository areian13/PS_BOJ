#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsIn5(unordered_map<string, int>& fruitCount)
{
    return fruitCount["STRAWBERRY"] == 5 
        || fruitCount["BANANA"] == 5 
        || fruitCount["LIME"] == 5 
        || fruitCount["PLUM"] == 5;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<string, int> fruitCount;
    for (int i = 0; i < n; i++)
    {
        string fruit;
        int cnt;
        cin >> fruit >> cnt;

        fruitCount[fruit] += cnt;
    }

    string result = (IsIn5(fruitCount) ? "YES" : "NO");
    cout << result << '\n';
}