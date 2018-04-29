#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int T;

	cin >> T;

	for (int i=0; i<T; i++)
	{
		int N;
		long minX, maxX;
		long even=0, odd=0;
		bool invertEven, invertOdd;
		long spammer=0, noSpammer=0;

		cin >> N >> minX >> maxX;

		std::vector< std::pair<long, long> > net;
		for (int j=0; j<N; j++)
		{
			std::pair<long, long> neuron;

			cin >> neuron.first >> neuron.second;
			net.push_back(neuron);
		}

		/* Per come è strutturata, la semplice rete neurale da valori di input pari, determina
		SEMPRE o un output pari o un output dispari, e da valori di input disapri, determina SEMPRE o un output pari o un output disapri. Visto che siamo interessati alla parità o
		alla disparità dell'output, non è necessari processare tutti gli input; è sufficiente processare un input pari e uno dispari, per vedere se la parità e la disparita, vengono invertiti o no nell'output. */

		long x;
		// Processo un input pari, per vedere se il corrispondente output è pari o dispari
		x = 2;
		for (int k=0; k<net.size(); k++)
			x = net[k].first * x + net[k].second;

		// Se l'output rimane pari ...
		if (x%2 == 0)
			invertEven = false;
		else
			invertEven = true;

		x = 3;
		// Processo un input dispari, per vedere se il corrispondente output è pari o dispari
		for (int k=0; k<net.size(); k++)
			x = net[k].first * x + net[k].second;

		// Se l'output è dispari ...
		if (x%2 == 0)
			invertOdd = true;
		else
			invertOdd = false; //--

		// Tra gli input da testare, conto quanti sono pari e quanti sono dispari:

		// Se l'intervallo di input è limitato da due valori pari:
		if ((minX % 2 == 0) && (maxX % 2 == 0))
		{
			odd = (maxX - minX) / 2;
			even = odd + 1;
		}
		// ... altrimenti se l'intervallo di input è limitato da due valori dispari:
		else if ((minX % 2 != 0) && (maxX % 2 != 0))
		{
			even = (maxX - minX) / 2;
			odd = even + 1;
		}
		// ... altrimenti se l'intervallo di input è limitato da un valore pari e uno dispari:
		else
		{
			even = (maxX - minX) / 2 + 1;
			odd = even;
		}

		// Se la rete neurale da input pari produce output dispari...
		if (invertEven)
			spammer += even; // .. incremento il numero degli spammer
		else
			noSpammer += even; // ...altrimenti, incremento il numero dei non spammer

		// Se la rete neurlae da "dispari" produce output pari...
		if (invertOdd)
			noSpammer += odd; // ...incremento il numero dei non spammer
		else
			spammer += odd; // ...altrimenti incremento il numero negli spammer

		cout << noSpammer << " " << spammer << endl;
	}

	return(0);
}
