#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

multimap<int, string> album = {
    {1967,"DavidBowie"},
    {1969,"SpaceOddity"},
    {1970,"TheManWhoSoldTheWorld"},
    {1971,"HunkyDory"},
    {1972,"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
    {1973,"AladdinSane"},
    {1973,"PinUps"},
    {1974,"DiamondDogs"},
    {1975,"YoungAmericans"},
    {1976,"StationToStation"},
    {1977,"Low"},
    {1977,"Heroes"},
    {1979,"Lodger"},
    {1980,"ScaryMonstersAndSuperCreeps"},
    {1983,"LetsDance"},
    {1984,"Tonight"},
    {1987,"NeverLetMeDown"},
    {1993,"BlackTieWhiteNoise"},
    {1995,"1.Outside"},
    {1997,"Earthling"},
    {1999,"Hours"},
    {2002,"Heathen"},
    {2003,"Reality"},
    {2013,"TheNextDay"},
    {2016,"BlackStar"},
};

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int s, e;
        cin >> s >> e;

        auto i = album.lower_bound(s);
        auto j = album.upper_bound(e);
        vector<pair<int, string>> result;
        for (auto it = i; it != j; it++)
            result.push_back(*it);

        cout << result.size() << '\n';
        for (auto& v : result)
            cout << v.first << ' ' << v.second << '\n';
    }
}