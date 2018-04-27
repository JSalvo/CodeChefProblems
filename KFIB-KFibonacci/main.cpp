#include <iostream>
using namespace std;

unsigned long long fib(unsigned long long n, unsigned long long k)
{
	unsigned long long serie[200001];

	for (unsigned long long i=1; i <= n; i++)
	{
		if (i <= k)
			serie[i] = 1;
		else
		{
			unsigned long long acc=0;

			for (unsigned long long j=i-1; j >= i-k; j--)
				acc += serie[j];

			serie[i] = acc % 1000000007;
		}
	}

	return(serie[n]);
}


int main(void)
{
	unsigned long long n, k;

	cin >> n >> k;

	cout << fib(n, k);

	return(0);
}
