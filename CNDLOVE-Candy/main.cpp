#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
	int T;

	cin >> T;

	for (int i=0; i<T; i++)
	{
		int N;
		long tot=0;

		cin >> N;
		for (int j=0; j<N; j++)
		{
			int v;

			cin >> v;
			tot += v;
		}

		if ( tot % 2 == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return(0);
}
