#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool better(int *v2, int *v1)
{
	int v[3];

	for (int i=0; i<3; i++)
		v[i] = v2[i] - v1[i];

	if (v[0] == 0 && v[1] == 0 && v[2] == 0)
		return(false);

	for (int i=0; i<3; i++)
	{
		if (v[i] < 0)
			return(false);
	}

	return(true);
}

int main(void)
{
	int T;
	cin >> T;

	for (int i=0; i<T; i++)
	{
		int v1[3], v2[3], v3[3];

		cin >> v1[0] >> v1[1] >> v1[2];
		cin >> v2[0] >> v2[1] >> v2[2];
		cin >> v3[0] >> v3[1] >> v3[2];

		if (better(v2, v1) && better(v3, v2))
			cout << "yes" << endl;
		else if (better(v3, v1) && better(v2, v3))
			cout << "yes" << endl;
		else if (better(v1, v2) && better(v3, v1))
			cout << "yes" << endl;
		else if (better(v3, v2) && better(v1, v3))
			cout << "yes" << endl;
		else if (better(v1, v3) && better(v2, v1))
			cout << "yes" << endl;
		else if (better(v2, v3) && better(v1, v2))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return(0);
}
