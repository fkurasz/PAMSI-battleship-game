#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <time.h>

using namespace std;

int Xcoord(string x);
int Ycoord(string y);
string coordToString(int x, int y);

class Ship
{
public:
	Ship();
	~Ship();

	//wygrana
	friend bool win(Ship *x,bool side);

	//ruch gracza
	friend void playerMove(string attack);



	//zwraca numer rzedu tablicy z coordow w postaci a1
	friend int Xcoord(string x);
	friend int Ycoord(string x);
	//zwraca coordy w postaci a1 z rzedow tablicy
	friend string coordToString(int x, int y);

	//USTAWIENIE STATKOW I ICH PARAMETROW ===================================================
	//ustawia strone statku oraz ilosc masztow, przygotowuje wielkosci tablic dla lokacji
	void setSideMast(int _side, int _mast);
	//ustawia wspolrzedne dla danego statku
	void setCoordShip(string* xy, int n);
	//ustawia blokowane pola dla danego statku (dla wszystkich masztow)
	void setBlockedField();
	//=======================================================================================
	
	//TRAFIENIA STATKOW======================================================================
	void setKilledMast() { killedMast++; }
	int getKilledMast() { return killedMast; }


	//zwraca ilosc masztow
	int getMast() { return mast; }
	//zwraca zablokowane pola danego statku
	string getBlockedField(int i) { return blockedField[i]; }
	int getCountBlockedField() { return countBlockedField; }
	//zwraca pozycje masztow
	string* getLocation() { return location; }
	//zwraca pozycje masztow konkretnych
	string getLocation(int n) { return location[n]; }

	

private:
	//1 to gracz 0 to komputer
	int side;
	//ilosc masztow
	int mast;
	//ilosc zabitych masztow
	int killedMast;
	//pola dla masztow
	string* location; //4 maszty //a1 a2 a3 a4
	//pola blokowane po zbiciu
	string* blockedField;
	//ilosc pol blokowanych
	int countBlockedField;
};



#endif // SHIP_H

