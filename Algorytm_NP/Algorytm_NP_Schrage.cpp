// Algorytm_NP.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <conio.h>
#include <vector>


using namespace std;

struct Dane {
	int r; //termin dostepnosci
	int p; //czas obslugi
	int q; //czas dostarczenia zadania
};
int mini(vector<Dane> &a, int id) {
	int d = a[0].r, index = 0;
	for (int i = 1; i < id; ++i) {
		if (a[i].r < d) {
			d = a[i].r;
			index = i;
		}
	}
	return index;
};
int maxi(vector<Dane> &a, int id) {
	int d = a[0].q, index = 0;
	for (int i = 1; i < id; ++i) {
		if (a[i].q > d) {
			d = a[i].q;
			index = i;
		}
	}
	return index;
};
int main()
{
	ifstream plik;
	string zmienna;
	int n = 0;
	int t = 0, k = 0, Cmax = 0;
	Dane e;

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

	vector<Dane> N;
	vector<Dane> G;
	vector<Dane> pi;


	/* wczytuje dane  */
	for (int i = 0; i < n; i++)
	{
		N.push_back(e);
		/* koniec pliku gdy spodziewamy sie danych => blad */
		if (!plik.eof())
		{
			plik >> N[i].r;
		}
		else
		{
			cout << "bledny wymiar pliku\n";
			return -1;
		}

		/* koniec pliku gdy spodziewamy sie danych => blad */
		if (!plik.eof())
			plik >> N[i].p;
		else
		{
			cout << "bledny wymiar pliku\n";
			return -1;
		}
		/* koniec pliku gdy spodziewamy sie danych => blad */
		if (!plik.eof())
			plik >> N[i].q;
		else
		{
			cout << "bledny wymiar pliku\n";
			return -1;
		}
	}plik.close();


	while (!N.empty() || !G.empty())
	{

		while (!N.empty() && N[mini(N, N.size())].r <= t) // dopoki N!= empty i sa zadania z ri <t -> przekladamy je z N do G
		{

			e = N[mini(N, N.size())];
			G.push_back(e);
			N.erase(N.begin() + mini(N, N.size()));
			n -= 1;

		}
		if (G.empty())               // jezeli G jest empty przesuwamy sie w czasie do pierwszego dostepnego zadania
		{
			t = N[mini(N, N.size())].r;
		}
		else
		{
			e = G[maxi(G, G.size())];
			k += 1;
			pi.push_back(e);      // aktualna wartosc t to czas rozpoczecia zadania e
			G.erase(G.begin() + maxi(G, G.size()));
			t += e.p;               // t+ czas trwania zadania e to czas zakonczenia zadania e
			Cmax = max(Cmax, t + e.q);
		}

	}

	cout << Cmax << endl;


	_getch();
	return 0;
}
