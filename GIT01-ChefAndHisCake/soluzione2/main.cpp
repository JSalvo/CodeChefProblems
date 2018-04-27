#include <iostream>
using namespace std;

int main(void)
{
	int T, N, M;
	char alternate[2]={'R', 'G'};

	cin >> T;
	for (int k=0; k<T; k++)
	{
		int s1=0, s2=0;
		cin >> N >> M;

		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++)
			{
				char cherryColor;
				int av1, av2;

				cin >> cherryColor;

				av1 = alternate[(i%2+j)%2];
				av2 = alternate[(i%2+j+1)%2];
				if (cherryColor == 'R')
				{
					if (av1 == 'G') s1 += 5;
					if (av2 == 'G') s2 += 5;
				}
				else
				{
					if (av1 == 'R') s1 += 3;
					if (av2 == 'R') s2 += 3;
				}
			}
		}

		if (s2 < s1)
			s1 = s2;

		cout << s1 << endl;
	}

	return(0);
}
