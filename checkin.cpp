#include <fstream>
#include <algorithm>

#define NMAX 1000
#define TMAX 15000000

using namespace std;

ifstream fin("checkin.in");
ofstream fout("checkin.out");

bool compar(int x, int y)
{
	return x > y;
}

int main()
{
	int N, i, K, P, tmin, nrg, st, dr, mij;
	long long sum;

	fin >> N;
	
	int a[N], b[N], maxbg[N];

	for (i = 0 ; i < N; i++)
	{
		fin >> a[i] >> b[i];
	}

	fin >> K >> P;

	fin.close();

	tmin = TMAX;

	for (i = 0; i < N; i++)
	{
		if (a[i]*P + b[i] < tmin)
		{
			tmin = a[i]*P + b[i];
		}
	}

	nrg = N < K ? N : K;

	st = -1, dr = tmin+1;

	while (dr-st > 1)
	{
		mij = st + (dr-st)/2;

		// verific daca pot livra P bagaje in mij secunde
	
		for (i = 0; i < N; i++)
		{
			maxbg[i] = (mij-b[i])/a[i];

			if (maxbg[i] <= 0)
			{
				maxbg[i] = -1;
			}
		}

		sort(maxbg, maxbg+N, compar);

		for (sum = i = 0; i < nrg; i++)
		{
			if (maxbg[i] > 0)
			{
				sum += maxbg[i];
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
// scor 90
