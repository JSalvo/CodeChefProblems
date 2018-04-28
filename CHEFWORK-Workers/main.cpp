#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main(void)
{
	int N; // Numero dei lavoratori

	long workers[4];

	// In questo array, verrà inserito il costo minimo per ciascuna tipologia di lavoratore
	workers[1] = LONG_MAX; // Traduttore
	workers[2] = LONG_MAX; // Autore
	workers[3] = LONG_MAX; // Traduttore-Autore

	cin >> N;

	// Vettore di coppie. Ciascuna coppia rappresenta un lavoratore e contiene il suo costo e // la tipologia di lavoratore
	std::vector< std::pair <long, int> > vec;

	// Leggo i dati di input e li inserisco nel vettore  di coppie
	for (int i=0; i<N; i++)
	{
		std::pair<long, int> p;

		cin >> p.first;

		vec.push_back(p);
	}

	for (int i=0; i<N; i++)
	{
		cin >> vec[i].second;
	}

	// Trovo il costo minimo per ciascuna tipologia di lavoratore
	for (int i=0; i<vec.size(); i++)
	{
		if (workers[vec[i].second] > vec[i].first)
			workers[vec[i].second] = vec[i].first;
	}

	// Se il costo del traduttore più economico, sommato al costo dell'autore più economico
	// è inferiore al costo del traduttore-autore più economico...
	if (workers[1] < workers[3] - workers[2]) 	// (La disequazione è stata scritta in questa forma, per evitare problemi di overflow)
		cout << (workers[1] + workers[2]); // Assumo traduttore + autore
	else
		cout << workers[3]; // ... altrimenti, assumo un traduttore-autore

	return(0);
}
