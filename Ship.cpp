#include "Ship.h"

Ship::Ship()
{
	side = 0;
	mast = 0;
	killedMast = 0;
	location = nullptr;
	blockedField = nullptr;
	countBlockedField = 0;
}
Ship::~Ship() {}

void Ship::setSideMast(int _side,int _mast)
{
	side = _side;
	mast = _mast;
	location = new string[mast];
	switch (mast)
	{
	case 1:	countBlockedField = 8; break;
	case 2:	countBlockedField = 10; break;
	case 3:	countBlockedField = 12; break;
	case 4:	countBlockedField = 14; break;
	}
	blockedField = new string[countBlockedField];
	for (int i = 0; i < countBlockedField; i++)
	{
		blockedField[i] = "";
	}
}

void Ship::setBlockedField()
{
	int index = 0;
	int x, y;
	string temp;


	for (int i = 0; i < mast; i++)
	{
		bool correct = true;
		x = Xcoord(this->location[i]); // a -> 0
		y = Ycoord(this->location[i]); // 1 -> 0

		//1 do gory
		//jesli takie pole istnieje
		if (y - 1 >= 0)
		{
			//zapisanie do temp tej pozycji
			temp = coordToString(x, y - 1);
			//jesli inny maszt tam sie nie znajduje
			for (int k = 0; k < mast; k++)
			{
				//jesli ta pozycja rowna sie pozycji jakiegos masztu
				if (location[k] == temp)
				{
					correct = false;
					break;
				}
			}
			for (int k = 0; k < index; k++)
			{
				if (blockedField[k] == temp)
				{
					correct = false;
					break;
				}
			}
			if (int(temp[0]) < 97 || int(temp[0]) > 106)
				correct = false;
			//jesli nie bylo takiego masztu to zapisz
			if (correct)
			{
				blockedField[index] = temp;
				index++;
				temp = "";
			}
		}
		correct = true;
		//1 w dol
		if (y + 1 <= 9)
		{
			//zapisanie do temp tej pozycji
			temp = coordToString(x, y + 1);
			//jesli inny maszt tam sie nie znajduje
			for (int k = 0; k < mast; k++)
			{
				//jesli ta pozycja rowna sie pozycji jakiegos masztu
				if (location[k] == temp)
				{
					correct = false;
					break;
				}
			}
			for (int k = 0; k < index; k++)
			{
				if (blockedField[k] == temp)
				{
					correct = false;
					break;
				}
			}
			if (int(temp[0]) < 97 || int(temp[0]) > 106)
				correct = false;
			//jesli nie bylo takiego masztu to zapisz
			if (correct)
			{
				blockedField[index] = temp;
				index++;
				temp = "";
			}
		}
		correct = true;
		//1 w lewo
		if (x - 1 >= 0)
		{
			//zapisanie do temp tej pozycji
			temp = coordToString(x - 1, y);
			//jesli inny maszt tam sie nie znajduje
			for (int k = 0; k < mast; k++)
			{
				//jesli ta pozycja rowna sie pozycji jakiegos masztu
				if (location[k] == temp)
				{
					correct = false;
					break;
				}
			}
			for (int k = 0; k < index; k++)
			{
				if (blockedField[k] == temp)
				{
					correct = false;
					break;
				}
			}
			if (int(temp[0]) < 97 || int(temp[0]) > 106)
				correct = false;
			//jesli nie bylo takiego masztu to zapisz
			if (correct)
			{
				blockedField[index] = temp;
				index++;
				temp = "";
			}
		}
		correct = true;
		//1 w prawo
		if (x + 1 <= 9)
		{
			//zapisanie do temp tej pozycji
			temp = coordToString(x + 1, y);
			//jesli inny maszt tam sie nie znajduje
			for (int k = 0; k < mast; k++)
			{
				//jesli ta pozycja rowna sie pozycji jakiegos masztu
				if (location[k] == temp)
				{
					correct = false;
					break;
				}
			}
			for (int k = 0; k < index; k++)
			{
				if (blockedField[k] == temp)
				{
					correct = false;
					break;
				}
			}
			if (int(temp[0]) < 97 || int(temp[0]) > 106)
				correct = false;
			//jesli nie bylo takiego masztu to zapisz
			if (correct)
			{
				blockedField[index] = temp;
				index++;
				temp = "";
			}
		}
		correct = true;
		//prawy gory rog
		if (y - 1 >= 0 && x + 1 <= 9)
		{
			//zapisanie do temp tej pozycji
			temp = coordToString(x + 1, y - 1);
			//jesli inny maszt tam sie nie znajduje
			for (int k = 0; k < mast; k++)
			{
				//jesli ta pozycja rowna sie pozycji jakiegos masztu
				if (location[k] == temp)
				{
					correct = false;
					break;
				}
			}
			for (int k = 0; k < index; k++)
			{
				if (blockedField[k] == temp)
				{
					correct = false;
					break;
				}
			}
			if (int(temp[0]) < 97 || int(temp[0]) > 106)
				correct = false;
			//jesli nie bylo takiego masztu to zapisz
			if (correct)
			{
				blockedField[index] = temp;
				index++;
				temp = "";
			}
		}
		correct = true;
		//lewy gorny rog
		if (y - 1 >= 0 && x - 1 <= 9)
		{
			//zapisanie do temp tej pozycji
			temp = coordToString(x - 1, y - 1);
			//jesli inny maszt tam sie nie znajduje
			for (int k = 0; k < mast; k++)
			{
				//jesli ta pozycja rowna sie pozycji jakiegos masztu
				if (location[k] == temp)
				{
					correct = false;
					break;
				}
			}
			for (int k = 0; k < index; k++)
			{
				if (blockedField[k] == temp)
				{
					correct = false;
					break;
				}
			}
			if (int(temp[0]) < 97 || int(temp[0]) > 106)
				correct = false;

			//jesli nie bylo takiego masztu to zapisz
			if (correct)
			{
				blockedField[index] = temp;
				index++;
				temp = "";
			}
		}
		correct = true;
		//lewy dolny rog
		if (y + 1 <= 9 && x - 1 >= 0)
		{
			//zapisanie do temp tej pozycji
			temp = coordToString(x - 1, y + 1);
			//jesli inny maszt tam sie nie znajduje
			for (int k = 0; k < mast; k++)
			{
				//jesli ta pozycja rowna sie pozycji jakiegos masztu
				if (location[k] == temp)
				{
					correct = false;
					break;
				}
			}
			for (int k = 0; k < index; k++)
			{
				if (blockedField[k] == temp)
				{
					correct = false;
					break;
				}
			}
			if (int(temp[0]) < 97 || int(temp[0]) > 106)
				correct = false;
			//jesli nie bylo takiego masztu to zapisz
			if (correct)
			{
				blockedField[index] = temp;
				index++;
				temp = "";
			}
		}
		correct = true;
		//prway dolny rog
		if (y + 1 <= 9 && x + 1 <= 9)
		{
			//zapisanie do temp tej pozycji
			temp = coordToString(x + 1, y + 1);
			//jesli inny maszt tam sie nie znajduje
			for (int k = 0; k < mast; k++)
			{
				//jesli ta pozycja rowna sie pozycji jakiegos masztu
				if (location[k] == temp)
				{
					correct = false;
					break;
				}
			}
			for (int k = 0; k < index; k++)
			{
				if (blockedField[k] == temp)
				{
					correct = false;
					break;
				}
			}
			if (int(temp[0]) < 97 || int(temp[0]) > 106)
				correct = false;
			//jesli nie bylo takiego masztu to zapisz
			if (correct)
			{
				blockedField[index] = temp;
				index++;
				temp = "";
			}
		}
		correct = true;
	}
}

void Ship::setCoordShip(string* xy, int n)
{
	for (int i = 0; i < n; i++)
	{
		location[i] = xy[i];
	}
}