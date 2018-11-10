#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main(void)
{
	long T, X, Y;
	long rest = 0;

	cin >> T;

	for (long i=0; i<T; i++)
	{
		cin >> X >> Y;

		while (X != 0 && Y != 0 && X != Y)
		{
			if (X > Y)
			{
				if ( (X - Y) % Y != 0)
				{
					X -= (((X - Y) / Y + 1) * Y);

					if (X < 0)
						X = 0;
				}
				else
					X = Y;
			}
			else if (Y > X)
			{
				if ( (Y - X) % X != 0)
				{
					Y -= (((Y - X) / X  + 1) * X);

					if (Y < 0)
						Y = 0;
				}
				else
					Y = X;
			}

		}

		cout << X + Y << endl;
	}

	return(0);
}
