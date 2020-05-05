#include "pch.h"
#include "Head.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct listj
{
	int var;
	listj *next;
};


int *stworzTablice_x1(int n)
{
	int *T = new int[n];
	return T;
}

//tworzenie listy incydencji za pomoc¹  listy jednokierunkowej

int lista_incydencji(int k, int w, int * tab_poczatek, int * tab_koniec)
{
	for (int j = 0; j < w; j++)
	{
		listj *head = nullptr;
		listj *newe = nullptr;

		for (int i = 0; i < k; i++)
		{
			//sprawdzanie dla ka¿dego wierzcho³ka czy istnieje inny wierzcho³ek z nim powi¹zany krawêdzi¹

			if (tab_poczatek[i] == j + 1)
			{
				newe = new listj;
				newe->var = tab_koniec[i];
				newe->next = head;
				head = newe;
			}

			if (tab_koniec[i] == j + 1)
			{
				newe = new listj;
				newe->var = tab_poczatek[i];
				newe->next = head;
				head = newe;
			}
		}

		listj * newtemp = head;
		int stopien = 0;
		cout << j + 1 << ":  ";

		//wypisywanie listy jenokiwrunkowej dla poszczególnych wierzcho³ków
		while (newtemp != nullptr)
		{
			cout << newtemp->var << " ";
			newtemp = newtemp->next;
			stopien++;
		}

		cout << "   Stopien: " << stopien << endl;
	}

	return 0;
}

void odczyt_z_pliku(string file_name, int &k, int &w, int **tab_poczatek, int **tab_koniec)
{
	fstream file;
	file.open(file_name.c_str(), ios::in);
	if (file.good() != true)
	{
		throw EXCEPTION_CODE::openError;

	}


	file >> k;
	*tab_poczatek = stworzTablice_x1(k);
	*tab_koniec = stworzTablice_x1(k);
	int help = 0;

	//odczyt danych z pliku i okreœlenie liczby wierzcho³ków grafu
	for (int i = 0; i < k; i++)
	{
		file >> help;
		if (help > w)
			w = help;

		(*tab_poczatek)[i] = help;

		file >> help;
		if (help > w)
			w = help;


		(*tab_koniec)[i] = help;
	}

	file.close();
}

//wyœwietlanie informacji o b³êdach
void seeExceptions(EXCEPTION_CODE error)
{
	switch (error)
	{
	case EXCEPTION_CODE::openError:
		cerr << "Blad otwarcia pliku odczytu";
		break;
	default:
		cerr << "Nieznany blad";
		break;
	}
}




