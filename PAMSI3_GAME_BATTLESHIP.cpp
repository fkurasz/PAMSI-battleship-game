// PAMSI3_GAME_BATTLESHIP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Ship.h"
using namespace std;

bool game = true;
bool movePlayer = true;
//s[0] 4 masztowy s[1,2] 3 masztowy s[3,4,5] 2 masztowy s[6,7,8,9] 1 masztowy
Ship s[20];

//==================================
char computerBoard[10][10] =
{
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
};
char playerBoard[10][10] =
{
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
};
char attackedBoardForPlayer[10][10] =
{
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O','O','O','O',
};

//==================================

bool rules()
{
	system("CLS");
	cout << "WITAJ W GRZE!" << endl;
	cout << "_____________" << endl << endl;
	cout << "1. USTAW SWOJA FLOTE" << endl;
	cout << "   Statki nie moga sie dotykac. Przerwa miedzy nimi musi wynosic przynajmniej 1 kratke." << endl;
	cout << "2. WYBIERZ POLE DO ATAKU" << endl;
	cout << "   a2" << endl;
	cout << "3. ZNISZCZ WSZYSTKIE STATKI WROGA ABY WYGRAC" << endl;
	cout << "_______________________________________________________________________________________" << endl;
	cout << "Rozumiem zasady (y/n): " << endl;
	char answer;
	cin >> answer;
	if (answer == 'y' || answer == 'Y' || answer == 't' || answer == 'T')
		return 1;
	else
		return 0;
}

//przyjmuje tablice 10x10 i ja pokazuje
void showBoard(char board[10][10])
{
	cout << " _|_A_B_C_D_E_F_G_H_I_J_" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (i != 9)
		{
			cout << " " << i + 1 << "| ";
		}
		else
		{
			cout << i + 1 << "| ";
		}
		for (int j = 0; j < 10; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

//pokazuje widok dla gracza
void showGameBoard()
{
	system("CLS");
	cout << "ZAATAKOWANE POLA" << endl << endl;
	showBoard(attackedBoardForPlayer);
	cout << "________________________";
	cout << endl << endl;
	cout << "PLANSZA GRACZA" << endl << endl;
	showBoard(playerBoard);
	cout << endl << endl;
	cout << "_________________________________________" << endl;
}

//string to coord
int Xcoord(string x)
{
	if (x[0] == 'a')
		return 0;
	if (x[0] == 'b')
		return 1;
	if (x[0] == 'c')
		return 2;
	if (x[0] == 'd')
		return 3;
	if (x[0] == 'e')
		return 4;
	if (x[0] == 'f')
		return 5;
	if (x[0] == 'g')
		return 6;
	if (x[0] == 'h')
		return 7;
	if (x[0] == 'i')
		return 8;
	if (x[0] == 'j')
		return 9;
	return 0;
}
int Ycoord(string y)
{
	if (y[1] == '1' && y[2] == '0')
		return 9;
	if (y[1] == '1')
		return 0;
	if (y[1] == '2')
		return 1;
	if (y[1] == '3')
		return 2;
	if (y[1] == '4')
		return 3;
	if (y[1] == '5')
		return 4;
	if (y[1] == '6')
		return 5;
	if (y[1] == '7')
		return 6;
	if (y[1] == '8')
		return 7;
	if (y[1] == '9')
		return 8;
	return 0;
}
string coordToString(int x, int y)
{
	string temp ="";
	switch (x)
	{
		case 0: temp += 'a'; break;
		case 1: temp += 'b'; break;
		case 2: temp += 'c'; break;
		case 3: temp += 'd'; break;
		case 4: temp += 'e'; break;
		case 5: temp += 'f'; break;
		case 6: temp += 'g'; break;
		case 7: temp += 'h'; break;
		case 8: temp += 'i'; break;
		case 9: temp += 'j'; break;
	}
	switch (y)
	{
		case 0: temp += '1'; break;
		case 1: temp += '2'; break;
		case 2: temp += '3'; break;
		case 3: temp += '4'; break;
		case 4: temp += '5'; break;
		case 5: temp += '6'; break;
		case 6: temp += '7'; break;
		case 7: temp += '8'; break;
		case 8: temp += '9'; break;
		case 9: temp += "10"; break;
	}

	return temp;
}
//==================================
void showInstrInitPlayer()
{
	system("CLS");
	cout << "ROZMIESC SWOJE STATKI" << endl;
	cout << "1 x 4 Masztowy" << endl;
	cout << "2 x 3 Masztowy" << endl;
	cout << "3 x 2 Masztowy" << endl;
	cout << "4 x 1 Masztowy" << endl;
	cout << "PAMIETAJ ZE STATKI MUSZA LEZEC W JEDNEJ LINII (PIONOWO LUB POZIOMO)" << endl;
	cout << "I NIE MOGA SIE DOTYKAC W ODLEGLOSCI DO 1 KRATKI" << endl;
	cout << "___________________________________________________________________" << endl;
	cout << endl;
	showBoard(playerBoard);
	cout << "___________________________________________________________________" << endl;
}
void initPlayer(Ship *x)
{
	string p[20];
	string ship[4];

	int j = 0;

	if (x[j].getMast() == 4)
	{
		int i = 0;
		for (int index = 0; index < 4; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '4';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 4);
		x[j].setBlockedField();
		j++;
	}
	if (x[j].getMast() == 3)
	{
		int i = 0;
		for (int index = 4; index < 7; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '3';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 3);
		x[j].setBlockedField();
		j++;

		i = 0;
		for (int index = 7; index < 10; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '3';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 3);
		x[j].setBlockedField();
		j++;
	}
	if (x[j].getMast() == 2)
	{
		int i = 0;
		for (int index = 10; index < 12; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '2';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 2);
		x[j].setBlockedField();
		j++;

		i = 0;
		for (int index = 12; index < 14; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '2';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 2);
		x[j].setBlockedField();
		j++;

		i = 0;
		for (int index = 14; index < 16; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '2';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 2);
		x[j].setBlockedField();
		j++;
	}
	if (x[j].getMast() == 1)
	{
		int i = 0;
		for (int index = 16; index < 17; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '1';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 1);
		x[j].setBlockedField();
		j++;

		i = 0;
		for (int index = 17; index < 18; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '1';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 1);
		x[j].setBlockedField();
		j++;

		i = 0;
		for (int index = 18; index < 19; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '1';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 1);
		x[j].setBlockedField();
		j++;

		i = 0;
		for (int index = 19; index < 20; index++)
		{
			showInstrInitPlayer();
			cout << "PODAJ WSPOLRZEDNE STATKU " << x[j].getMast() << " MASZTOWEGO: ";
			cin >> p[index];

			playerBoard[Ycoord(p[index])][Xcoord(p[index])] = '1';
			ship[i] = p[index];
			i++;
		}
		x[j].setCoordShip(ship, 1);
		x[j].setBlockedField();
		j++;
	}
}
//inicjalizuje tablice komputera
void initComputer(Ship *x)
{
	string p[20];
	string ship[4];

	fstream file;
	file.open("computerBoard.txt",ios::in);
	for (int i = 0; i < 20; i++)
	{
		file >> p[i];
	}
	file.close();

	int j = 10;
	
		if (x[j].getMast() == 4)
		{
			int i = 0;
			for (int index = 0; index < 4; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '4';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 4);
			x[j].setBlockedField();
			j++;
		}
		if (x[j].getMast() == 3)
		{
			int i = 0;
			for (int index = 4; index < 7; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '3';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 3);
			x[j].setBlockedField();
			j++;

			i = 0;
			for (int index = 7; index < 10; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '3';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 3);
			x[j].setBlockedField();
			j++;
		}
		if (x[j].getMast() == 2)
		{
			int i = 0;
			for (int index = 10; index < 12; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '2';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 2);
			x[j].setBlockedField();
			j++;

			i = 0;
			for (int index = 12; index < 14; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '2';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 2);
			x[j].setBlockedField();
			j++;

			i = 0;
			for (int index = 14; index < 16; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '2';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 2);
			x[j].setBlockedField();
			j++;
		}
		if (x[j].getMast() == 1)
		{
			int i = 0;
			for (int index = 16; index < 17; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '1';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 1);
			x[j].setBlockedField();
			j++;

			i = 0;
			for (int index = 17; index < 18; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '1';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 1);
			x[j].setBlockedField();
			j++;

			i = 0;
			for (int index = 18; index < 19; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '1';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 1);
			x[j].setBlockedField();
			j++;

			i = 0;
			for (int index = 19; index < 20; index++)
			{
				computerBoard[Ycoord(p[index])][Xcoord(p[index])] = '1';
				ship[i] = p[index];
				i++;
			}
			x[j].setCoordShip(ship, 1);
			x[j].setBlockedField();
			j++;
		}
}
//==================================

void playerMove(string attack)
{
	int x, y;
	x = Ycoord(attack);
	y = Xcoord(attack);


			if (computerBoard[x][y] != 'O')
			{
				attackedBoardForPlayer[x][y] = 'H';
				movePlayer = true;
				cout << "TRAFIONO STATEK NA POLU " << attack << " KONTYNUUJ RUCH!" << endl;

				for (int i = 10; i < 20; i++) // ktory statek (i nr statku)
				{
					for (int j = 0; j < s[i].getMast(); j++) //ktory maszt (j nr masztu)
					{
						if (attack == s[i].getLocation(j))
						{
							s[i].setKilledMast(); //ustaw maszt jako trafiony
							if (s[i].getKilledMast() == s[i].getMast())//sprawdzenie czy wszystkie maszty zatopione
							{
								cout << endl << "ZATOPIONO STATEK " << s[i].getMast() << " MASZTOWY!" << endl;
								//jesli wszystkie zatopione to ustaw pole blokowane jako juz nie do bicia
								int n = 0;
								while (n < s[i].getCountBlockedField())
									{
										if (s[i].getBlockedField(n) != "")
										{
											int x, y;
											x = Xcoord(s[i].getBlockedField(n));
											y = Ycoord(s[i].getBlockedField(n));

											attackedBoardForPlayer[y][x] = 'X';
										}
										n++;
									}
									
							}
						}
					}
				}
				
			}
			else
			{
				attackedBoardForPlayer[x][y] = 'X';
				cout << "PUDLO!" << endl;
			}
}
void computerMove()
{
	int x, y;
	
	bool ifAttacked = false;
	do
	{
		ifAttacked = false;
		srand(time(NULL));
		x = rand() % 10;
		y = rand() % 10;

		if (playerBoard[y][x] == 'H' || playerBoard[y][x] == 'X')
		{
			ifAttacked = true;
		}

	} while (ifAttacked);
	cout << coordToString(x, y) << endl;

	string attack = coordToString(x, y);

	if (playerBoard[y][x] != 'O')
	{
		playerBoard[y][x] = 'H';
		movePlayer = false;
		cout << "TRAFIONO W TWOJ STATEK NA POLU " << coordToString(x,y) << " !" << endl;

		for (int i = 0; i < 10; i++) // ktory statek (i nr statku)
		{
			for (int j = 0; j < s[i].getMast(); j++) //ktory maszt (j nr masztu)
			{
				if (attack == s[i].getLocation(j))
				{
					s[i].setKilledMast(); //ustaw maszt jako trafiony
					if (s[i].getKilledMast() == s[i].getMast())//sprawdzenie czy wszystkie maszty zatopione
					{
						cout << endl << "ZATOPIONO TWOJ STATEK " << s[i].getMast() << " MASZTOWY!" << endl;
						//jesli wszystkie zatopione to ustaw pole blokowane jako juz nie do bicia
						int n = 0;
						while (n < s[i].getCountBlockedField())
						{
							if (s[i].getBlockedField(n) != "")
							{
							int x, y;
							x = Xcoord(s[i].getBlockedField(n));
							y = Ycoord(s[i].getBlockedField(n));

							playerBoard[y][x] = 'X';
							}
							n++;
						}

					}
				}
			}
		}

	}
	else
	{
		playerBoard[y][x] = 'X';
		cout << "PUDLO!" << endl;
	}
}

//=====sprawdzanie wygranej
bool win(Ship* x,bool side)
{
	int countKilled = 0;

	if (side == 1) // player
	{
		for (int i = 10; i < 20; i++)
		{
			if (s[i].getMast() == s[i].getKilledMast())
				countKilled++;

			if (countKilled == 10)
				return 1;
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (s[i].getMast() == s[i].getKilledMast())
				countKilled++;

			if (countKilled == 10)
				return 1;
		}
	}

	return 0;
}


int main()
{
	// wpisano w klasy strone statku oraz ilosc masztow (przygotowano miejsca w tablicach)
	for (int k = 0; k < 20; k++)
	{
		//od 0 do 9 statki gracza od 10 do 19 statki kompuetra
		int side = 1;
		if (k > 9)
			side = 0;

		switch (k)
		{
		case 0: s[k].setSideMast(side, 4); break;
		case 1: s[k].setSideMast(side, 3); break;
		case 2: s[k].setSideMast(side, 3); break;
		case 3: s[k].setSideMast(side, 2); break;
		case 4: s[k].setSideMast(side, 2); break;
		case 5: s[k].setSideMast(side, 2); break;
		case 6: s[k].setSideMast(side, 1); break;
		case 7: s[k].setSideMast(side, 1); break;
		case 8: s[k].setSideMast(side, 1); break;
		case 9: s[k].setSideMast(side, 1); break;

		case 10: s[k].setSideMast(side, 4); break;
		case 11: s[k].setSideMast(side, 3); break;
		case 12: s[k].setSideMast(side, 3); break;
		case 13: s[k].setSideMast(side, 2); break;
		case 14: s[k].setSideMast(side, 2); break;
		case 15: s[k].setSideMast(side, 2); break;
		case 16: s[k].setSideMast(side, 1); break;
		case 17: s[k].setSideMast(side, 1); break;
		case 18: s[k].setSideMast(side, 1); break;
		case 19: s[k].setSideMast(side, 1); break;
		}
	}

	while (!rules()) {};

	//inicjalizacja wspolrzednych i pol blokowanych dla kazdego ze statkow
	initComputer(s);
	initPlayer(s);

	while (game)
	{
		showGameBoard();
		//ruch gracza
		if (movePlayer)
		{
			string field;
			cout << "ATAK POLA: ";
			cin >> field;

			int x, y;
			x = Xcoord(field);
			y = Ycoord(field);

			if (attackedBoardForPlayer[y][x] == 'X' || attackedBoardForPlayer[y][x] == 'H')
			{
				cout << "JUZ ATAKOWANO TO POLE, WYBIERZ INNE!" << endl;
				Sleep(2000);
			}
			else
			{
				movePlayer = false;
				playerMove(field);
				Sleep(1500);
				if (win(s, 1))
				{
					system("CLS");
					cout << "==================================================" << endl;
					cout << "ZWYCIESTWO!       POKONANO CALA FLOTE PRZECIWNIKA!" << endl;
					cout << "==================================================" << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					game = false;
					cout << "Nacisnij dowolny klawisz aby wyjsc.";
					getchar();
					exit(0);
				}
			}
		}
		//ruch kompa
		else
		{
			cout << "RUCH PRZECIWNIKA" << endl;
			cout << "PRZECIWNIK ATAKUJE POLE: ";
			movePlayer = true;
			computerMove();
			Sleep(1500);
			if (win(s, 0))
			{
				system("CLS");
				cout << "==================================================" << endl;
				cout << "PORAZKA!         PRZECIWNIK ZNISZCZYL TWOJA FLOTE!" << endl;
				cout << "==================================================" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				game = false;
				cout << "Nacisnij dowolny klawisz aby wyjsc.";
				getchar();
				exit(0);
			}
		}
	}
}