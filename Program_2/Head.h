#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*Funkcja odczytuj¹ca dane wejsciowe z pliku tekstowego*/
void odczyt_z_pliku(string file_name, int &k, int &w, int **tab_poczatek, int **tab_koniec);

/*Funkcja tworz¹ca tablic¹ dynamiczn¹ jednowymiarow¹ - zwraca wskaŸnik do jej pierwszego elemtnetu*/
int *stworzTablice_x1(int n);

/*Funkcja tworz¹ca listê incydencji grafu za pomoc¹ listy jednokierunkowej*/
int lista_incydencji(int k, int w, int *tab_poczatek, int *tab_koniec);

enum EXCEPTION_CODE
{
	openError

};

/*Funkcja wyœwietlaj¹ca informacjê o zaistnia³ym b³êdzie w programie*/
void seeExceptions(EXCEPTION_CODE error);


#endif