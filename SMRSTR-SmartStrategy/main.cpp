#include <iostream>

using namespace std;


int main(void)
{
	int T;
	unsigned long long sumN=0, sumQ=0;

	cin >> T;

	for (int i=0; i<T; i++)
	{
		unsigned long long N, Q, D=1;
		//vector <int> D;


		cin >> N >> Q;

		for (unsigned long long j=0; j<N; j++)
		{
			int tmp;

			cin >> tmp;
			D *= tmp;
		}

		for (unsigned long long j=0; j<Q; j++)
		{
			int qi;

			cin >> qi;

			cout << qi / D << " ";
		}

		cout << endl;
	}

	return(0);
}
