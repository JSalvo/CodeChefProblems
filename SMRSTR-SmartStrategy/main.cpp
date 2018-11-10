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
		unsigned long long sumN=0, sumQ=0;
		unsigned long long N, Q, D=1;
		std::vector<unsigned long long> v;

		cin >> N >> Q; //3 2

		unsigned long long counter = ULLONG_MAX;
		for (unsigned long long j=0; j<N; j++)
		{
			unsigned long long tmp;

			cin >> tmp;

			if (counter >= tmp)
			{
				D *= tmp;
				counter /= tmp;
			}
			else
			{
				v.push_back(D);
				counter = ULLONG_MAX / tmp;
				D = tmp;
			}
		}
		v.push_back(D);

/*
		cout << "[";
		for (int s=0; s<v.size(); s++)
		{
			cout << v[s];


		}
		cout << "]";*/



		for (unsigned long long j=0; j<Q; j++)
		{
			unsigned long long qi;

			cin >> qi;

			for (int k=0; k<v.size(); k++)
			{
				if (qi < v[k])
				{
					qi = 0;
					break;
				}
				else
					qi = qi / v[k];

			}

			cout << qi  << " ";
		}

		cout << endl;
	}

	return(0);
}
