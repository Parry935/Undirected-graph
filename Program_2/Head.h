#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*Funkcja odczytuj�ca dane wejsciowe z pliku tekstowego*/
void odczyt_z_pliku(string file_name, int &k, int &w, int **tab_poczatek, int **tab_koniec);

/*Funkcja tworz�ca tablic� dynamiczn� jednowymiarow� - zwraca wska�nik do jej pierwszego elemtnetu*/
int *stworzTablice_x1(int n);

/*Funkcja tworz�ca list� incydencji grafu za pomoc� listy jednokierunkowej*/
int lista_incydencji(int k, int w, int *tab_poczatek, int *tab_koniec);

enum EXCEPTION_CODE
{
	openError

};

/*Funkcja wy�wietlaj�ca informacj� o zaistnia�ym b��dzie w programie*/
void seeExceptions(EXCEPTION_CODE error);


#endif