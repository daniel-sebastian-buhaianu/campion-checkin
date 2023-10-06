#include <fstream>
#include <algorithm>

#define NMAX 1000

using namespace std;

ifstream fin("checkin.in");
ofstream fout("checkin.out");

struct ghiseu { int tb, tt; };
/**
 * tb = timp procesare 1 bagaj (secunde)
 * tt = timp procesare N tichete (secunde)
**/

bool compar(ghiseu a, ghiseu b)
{
	if (a.tb+a.tt < b.tb+b.tt)
	{
		return 1;
	}

	if (a.tb+a.tt == b.tb+b.tt
		&& a.tb < b.tb)
	{
		return 1;
	}

	return 0;
}

int main()
{
	int N, i, K, P, nrg, st, dr, mij, nrb, sum;

	fin >> N;

	ghiseu g[N];

	for (i = 0 ; i < N; i++)
	{
		fin >> g[i].tb >> g[i].tt;
	}

	fin >> K >> P;

	fin.close();

	sort(g, g+N, compar);
	
	nrg = N < K ? N : K;

	int maxb[nrg];

	st = -1, dr = g[0].tb*P + g[0].tt + 1;

	while (dr-st > 1)
	{
		mij = st + (dr-st)/2;

		// verific daca pot livra P bagaje in mij secunde

		for (i = 0; i < nrg; i++)
		{
			nrb = (mij-g[i].tt)/g[i].tb;

			maxb[i] = nrb <= 0 ? -1 : nrb;
		}

		for (sum = i = 0; i < nrg; i++)
		{
			if (maxb[i] > 0)
			{
				sum += maxb[i];
			}
		}

		if (sum < P)
		{
			// nu pot livra P bagaje in mij secunde
			st = mij;	
		}
		else
		{
			// pot livra P bagaje in mij secunde
			dr = mij;	
		}
	}

	fout << dr;

	fout.close();

	return 0;
}
// scor 40
