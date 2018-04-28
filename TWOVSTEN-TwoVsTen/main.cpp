#include <iostream>

using namespace std;

int main(void)
{
	int T;

	cin >> T;

	for (int i=0; i<T; i++)
	{
		long X;

		cin >> X;

		if (X % 5 == 0)
		{
			if (X % 10 == 0)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
		else
			cout << -1 << endl;
	}
}
