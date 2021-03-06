// Algorytm_NP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <conio.h>
#include <vector>


using namespace std;

struct Dane{
	int r; //termin dostepnosci
	int p; //czas obslugi
	int q; //czas dostarczenia zadania
};
int mini(vector<Dane> &a, int id) {
	int d = a[0].r;
	for (int i=1; i < id; ++i) {
		if (a[i].r < d) {
			d = a[i].r;
		}
	}
	return d;
};
int maxi(vector<Dane> &a, int id) {
	int d = a[0].r;
	for (int i = 1; i < id; ++i) {
		if (a[i].r > d) {
			d = a[i].r;
		}
	}
	return d;
};
int main()
{
	ifstream plik;
	string zmienna;
	int n = 0;
	
	cout << "Podaj nazwe pliku wejsciowego:  ";
	cin >> zmienna;
	cout << endl;

	/* otwieramy plik */
	plik.open(zmienna);

	/* sprawdzamy czy plik sie otworzyl */
	if (!plik.good() == true)
	{
		cout << "Nie mozna otworzyc pliku\n";
		return -1;
	}

	/* pobieramy liczbe zadan */
	plik >> n;
	
	/* unikamy bledu dla n<=0 */
	if (n <= 0)
	{
		cout << "Bledny plik z danymi\n";
		return -1;
	}
	
	vector<Dane> V(n);
	
	/* wczytuje dane  */
	for (int i = 0; i < n; i++)
	{
		/* koniec pliku gdy spodziewamy sie danych => blad */
		if (!plik.eof())
		{
			plik >> V[i].r;
			
			
		}
		else
		{
			cout << "bledny wymiar pliku\n";
			return -1;
		}
	
		/* koniec pliku gdy spodziewamy sie danych => blad */
		if (!plik.eof())
			plik >> V[i].p;
		else
		{
			cout << "bledny wymiar pliku\n";
			return -1;
		}
		/* koniec pliku gdy spodziewamy sie danych => blad */
		if (!plik.eof())
			plik >> V[i].q;
		else
		{
			cout << "bledny wymiar pliku\n";
			return -1;
		}
	}plik.close();
	
	
	cout << mini(V, n);
	cout << maxi(V, n);
	
	_getch();
	return 0;
}


