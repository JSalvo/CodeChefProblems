#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool test(std::vector<long> *v)
{
	for (long i=2; i<v->size(); i++)
	{
		if ((*v)[i] != (*v)[i-1] + (*v)[i-2])
			return(false);
	}

	return(true);
}

int main(void)
{
	int T;
	cin >> T;

	for (int j=0; j<T; j++)
	{
		std::map <char, long> counter;
		std::vector<long> v;
		string line;

		cin >> line;

		for (long i=0; i<line.size(); i++)
		{

			if ( counter.find(line[i]) == counter.end() )
			{
				counter[line[i]] = 1;
			}
			else
				counter[line[i]] = counter[line[i]] + 1;
		}

		for (std::map<char, long>::iterator it = counter.begin(); it != counter.end(); it++)
			v.push_back(it->second);

		// Ordina l'array
		std::sort (v.begin(), v.end());

		if (test(&v))
			cout << "Dynamic" << endl;
		else
		{
			long tmp = v[1];
			v[1] = v[0];
			v[0] = tmp;

			if (test(&v))
				cout << "Dynamic" << endl;
			else
				cout << "Not" << endl;
		}			
	}

	return(0);
}
