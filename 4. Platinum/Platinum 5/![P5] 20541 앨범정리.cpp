#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <random>
#include <type_traits>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

struct Element
{
	int cntAlbum = 0;
	int cntPhoto = 0;

	Element operator+(Element& cnt)
	{
		return { cntAlbum + cnt.cntAlbum, cntPhoto + cnt.cntPhoto };
	}
	void operator+=(Element& cnt)
	{
		cntAlbum += cnt.cntAlbum;
		cntPhoto += cnt.cntPhoto;
	}
};
struct Album
{
	
	string name;
	Element cnt;
	Album* parent;

	unordered_map<string, Album*> subAlbum;
	unordered_map<string, bool> photos;

	friend Element Rmalb(Album* album)
	{
		Element result = album->cnt;
		for (auto it = album->subAlbum.begin(); it != album->subAlbum.end(); it++)
		{
			result += Rmalb(album->subAlbum[it->first]);
			delete album->subAlbum[it->first];
		}
		album->subAlbum.clear();
		album->photos.clear();
		return result;
	}
};

int main()
{
	FastIO;

	Album* album = new Album();
	Album* curAlbum = album;

	int n;
	Cin n;

	while (n--)
	{
		string cmd, name;
		Cin cmd >> name;

		if (cmd == "mkalb")
		{
			if (curAlbum->subAlbum[name] == nullptr)
			{
				curAlbum->subAlbum[name] = new Album();
				curAlbum->subAlbum[name]->parent = curAlbum;
				curAlbum->cnt.cntAlbum++;
			}
			else
				Cout "duplicated album name" Endl;
		}

		if (cmd == "rmalb")
		{
			Element elem = Rmalb(curAlbum);
			Cout elem.cntAlbum spc elem.cntPhoto Endl;
		}
	}
}