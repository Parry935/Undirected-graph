

#include "pch.h"
#include "Head.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	int return_number = 0;
	string file_name;
	int k = 0;
	int *tab_poczatek = nullptr;
	int *tab_koniec = nullptr;
	int w = 0;

	try
	{
		cout << "Podaj nazwe pliku z ktorego chcesz odczytac: " << endl;
		cin >> file_name;
		odczyt_z_pliku(file_name, k, w, &tab_poczatek, &tab_koniec);
	}
	catch (EXCEPTION_CODE error)
	{
		seeExceptions(error);
		return_number = 1;
	}

	lista_incydencji(k, w, tab_poczatek, tab_koniec);

	cout << endl;
	

	getchar();
	return return_number;
}


