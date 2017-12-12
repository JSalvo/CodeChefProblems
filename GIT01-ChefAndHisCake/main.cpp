#include <iostream>
using namespace std;

// Se topCherry è = 'r' verrà calcolata la soluzione che prevede che la ciliegia
// in alto a sinistria sia di colore rosso, altrimenti se topCherry è = 'g', verrà
// calcolata la soluzione che prevede che la ciliegia in alto a sinistra sia di
// colore rosso
int _costSolution(char topCherry, bool cake[][100], int N, int M)
{
	int costSolution = 0;
	char leftCherry;

	for (int i=0; i<N; i++)
	{
		leftCherry = 'n';

		for (int j=0; j<M; j++)
		{
			if (cake[i][j]) // Red
			{
				if (leftCherry == 'n')
				{
					if (topCherry == 'r')
					{
						topCherry = 'g';
						leftCherry = 'g';
						costSolution += 5;
					}
					else // topCherry = 'g'
					{
						topCherry = 'r';
						leftCherry = 'r';
					}
				}
				else if (leftCherry == 'g')
				{
					leftCherry = 'r';
				}
				else // leftCherry = 'r'
				{
					costSolution += 5;
					leftCherry = 'g';
				}
			}
			else // cake[i][j] == false Green
			{
				if (leftCherry == 'n')
				{
					if (topCherry == 'r')
					{
						topCherry = 'g';
						leftCherry = 'g';
					}
					else // topCherry = 'g'
					{
						topCherry = 'r';
						leftCherry = 'r';
						costSolution += 3;
					}
				}
				else if (leftCherry == 'g')
				{
					leftCherry = 'r';
					costSolution += 3;
				}
				else // leftCherry = 'r'
				{
					leftCherry = 'g';
				}
			}
		}
	}

	return(costSolution);
}

// Produce la miglior soluzione
int costSolution(bool cake[][100], int N, int M)
{
	int s1, s2;

	// Calcolo la soluzione che prevede che la ciliegia in alto a sinistra sia di
	// colore verde
	s1 = _costSolution('r', cake, N, M);

	// Calcolo la soluzione che prevede che la ciliegia in alto a sinistra sia di
	// colore rosso
	s2 = _costSolution('g', cake, N, M);

	// Produco la miglior soluzione
	if (s1 < s2)
		return(s1);
	else
		return(s2);
}

int main(void)
{
	int T, N, M;
	bool cake[100][100];

	cin >> T;

	for (int k=0; k<T; k++)
	{
		cin >> N >> M;

		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++)
			{
				char cherryColor;

				cin >> cherryColor;

				if (cherryColor == 'R')
					cake[i][j] = true;
				else
					cake[i][j] = false;
			}
		}

		cout << costSolution(cake, N, M) << endl;
	}

	return(0);
}
