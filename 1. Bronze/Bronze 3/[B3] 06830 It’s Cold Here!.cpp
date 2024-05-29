#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct City
{
    string name;
    int temp;
};

string ColdestCity(vector<City>& cities)
{
    int n = cities.size();

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (cities[idx].temp > cities[i].temp)
            idx = i;
    }
    return cities[idx].name;
}

int main()
{
    FastIO;

    vector<City> cities;
    while (true)
    {
        string city;
        int temp;
        cin >> city >> temp;

        cities.push_back({ city,temp });

        if (city == "Waterloo")
            break;
    }

    string result = ColdestCity(cities);
    cout << result << '\n';
}