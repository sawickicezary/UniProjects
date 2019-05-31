//POP 2018-12-14 projekt 1 Sawicki Cezary  EIT 3 175723 Visual Studio 2017 15.9.3 Community Version Kompilator: Visual C++ 2017

#include <iostream>




#define ILOSC_POL 10
#define WIELKOSC_POLA 3
#define POLE (ILOSC_POL*WIELKOSC_POLA)
using namespace std;


void Pionek1()
{
	cout << "| OOO ";
}
void Pionek2()
{
	cout << "| ### ";
}
void PustePole() {
	cout << "|     ";
}
void ZestrzelonePole() {
	cout << "| ... ";

}
void Pion(int x)
{
	switch (x)
	{
	case 0: PustePole();
		break;
	case 1: Pionek1();
		break;
	case 2: Pionek2();
		break;
	case -1: ZestrzelonePole();
		break;
	default:
		break;
	}
}
void UstawPlansze(int pola[ILOSC_POL][ILOSC_POL])
{
	system("cls");
	int x = 10;
	for (int i = 0; i < ILOSC_POL; i++)//wiersze
	{
		cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
		cout << "  ";
		for (int j = 0; j < ILOSC_POL; j++)
		{
			Pion(pola[i][j]);
		}
		cout << "|" << endl;
		cout.width(2);
		cout << x;
		for (int j = 0; j < ILOSC_POL; j++)
		{
			Pion(pola[i][j]);
		}
		cout << "|" << endl;
		x--;

	}
	cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
	cout << "     A     B     C     D     E     F     G     H     I     J     " << endl;

}
void startPlansza(int pola[ILOSC_POL][ILOSC_POL]) {
	for (int i = 0; i < ILOSC_POL; i++) //tworzenie poczatkowego ulozenia
	{
		for (int j = 0; j < ILOSC_POL; j++)
		{
			if ((i == 0 && (j == 3 || j == 6)) || (i == 3 && (j == 0 || j == 9)))
				pola[i][j] = 2;
			else if ((i == 6 && (j == 0 || j == 9)) || (i == 9 && (j == 3 || j == 6)))
				pola[i][j] = 1;
			else pola[i][j] = 0;
		}
	}
}
//////////////////////////////////////////////////
bool dobreDane(int gracz, int x, int y, int pola[ILOSC_POL][ILOSC_POL])
{
	if (x < 0 || x>10 || y < 0 || y>10 || pola[y][x] != gracz)
		return false;
	else return true;
}

int wystrzelPocisk(int gracz, char xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	char x = 0;
	int y = 0;
	cout << "Wpisz kolumne docelowa strzalu(od A do J): ";
	while (!(cin >> x)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Zle wartosci." << endl;
		return -1;
	}
	x = x - 'A';

	cout << "Wpisz wiersz docelowy strzalu(od 1 do 10): ";
	while (!(cin >> y)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Zle wartosci." << endl;
		return -1;
	}

	y = 10 - y;

	if (x < 0 || x>10 || y < 0 || y>10 || pola[y][x] != 0)
	{
		cout << "W tym polu cos stoi badz jest bledne." << endl;
		return -1;
	}
	int xvector, yvector;
	int powxvector, powyvector; //pozbywamy sie znaku, ulatwi to sprawdzenie czy ruch bedzie sie odbywal ukosnie
	yvector = y - ystart;
	xvector = x - xstart;
	powxvector = xvector * xvector;
	powyvector = yvector * yvector;
	char i = xstart, j = ystart;
	if (powxvector == powyvector)//warunek ruchu na ukos
	{
		if (yvector < 0 && xvector > 0)//prawo w gore
		{
			i++;
			j--;
			while (i <= x)
			{
				if (pola[j][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
				i++;
				j--;
			}
			pola[y][x] = -1;
		}
		else if (yvector > 0 && xvector > 0)//prawo w dol
		{
			i++;
			j++;
			while (i <= x)
			{
				if (pola[j][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
				i++;
				j++;
			}
			pola[y][x] = -1;
		}
		else if (yvector < 0 && xvector < 0)//lewo w gore
		{
			i--;
			j--;
			while (i >= x)
			{
				if (pola[j][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
				i--;
				j--;
			}
			pola[y][x] = -1;
		}
		else if (yvector > 0 && xvector < 0)//lewo w dol
		{
			i--;
			j++;
			while (i >= x)
			{
				if (pola[j][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
				i--;
				j++;
			}
			pola[y][x] = -1;
		}
		else
		{
			cout << "Ruch niedozwolony.";
			return -1;
		}
	}
	else if (powxvector != powyvector)
	{
		if (yvector == 0 && xvector > 0) //ruch w prawo
		{
			i++;
			for (i; i <= x; i++)
			{
				if (pola[y][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
			}
			pola[y][x] = -1;
		}
		else if (yvector == 0 && xvector < 0) //ruch w lewo
		{
			i--;
			for (i; i >= x; i--)
			{
				if (pola[y][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
			}
			pola[y][x] = -1;
		}
		else if (yvector < 0 && xvector == 0) //ruch w gore
		{
			j--;
			for (j; j >= y; j--)
			{
				if (pola[j][x] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
			}
			pola[y][x] = -1;
		}
		else if (yvector > 0 && xvector == 0) //ruch w dol
		{
			j++;
			for (j; j <= y; j++)
			{
				if (pola[j][x] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
			}
			pola[y][x] = -1;
		}
		else
		{
			cout << "Ruch niedozwolony.";
			return -1;
		}
	}
	return 0;
}

int przesunPionek(int gracz, char xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])//ruch w docelowe miejsce przez gracza
{
	//xstart ystart to poczatkowe wartosci wspolrzednych pionka
	char x = 0;
	int y = 0;
	cout << "Wpisz kolumne docelowa (od A do J): ";
	while (!(cin >> x)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Zle wartosci." << endl;
		return -1;
	}
	x = x - 'A';

	cout << "Wpisz wiersz docelowy (od 1 do 10): ";
	while (!(cin >> y)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Zle wartosci." << endl;
		return -1;
	}
	y = 10 - y;

	if (x < 0 || x>10 || y < 0 || y>10 || pola[y][x] != 0) //warunek na poprawne pole
	{
		cout << "W tym polu cos stoi badz jest bledne." << endl;
		return -1;
	}
	int xvector, yvector;
	int powxvector, powyvector; //pozbywamy sie znaku, ulatwi to sprawdzenie czy ruch bedzie sie odbywal ukosnie
	yvector = y - ystart;
	xvector = x - xstart;
	powxvector = xvector * xvector;
	powyvector = yvector * yvector;
	char i = xstart;
	int j = ystart;
	if (powxvector == powyvector)//warunek ruchu na ukos
	{
		if (yvector < 0 && xvector > 0)//prawo w gore
		{
			i++;
			j--;
			while (i <= x)
			{
				if (pola[j][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
				i++;
				j--;
			}
			pola[ystart][xstart] = 0;
			pola[y][x] = gracz;
			UstawPlansze(pola);
			if (wystrzelPocisk(gracz, x, y, pola) == -1)
			{
				pola[y][x] = 0;
				pola[ystart][xstart] = gracz;
				return -1;
			}
		}
		else if (yvector > 0 && xvector > 0)//prawo w dol
		{
			i++;
			j++;
			while (i <= x)
			{
				if (pola[j][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
				i++;
				j++;
			}
			pola[ystart][xstart] = 0;
			pola[y][x] = gracz;
			UstawPlansze(pola);
			if (wystrzelPocisk(gracz, x, y, pola) == -1)
			{
				pola[y][x] = 0;
				pola[ystart][xstart] = gracz;
				return -1;
			}
		}
		else if (yvector < 0 && xvector < 0)//lewo w gore
		{
			i--;
			j--;
			while (i >= x)
			{
				if (pola[j][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
				i--;
				j--;
			}
			pola[ystart][xstart] = 0;
			pola[y][x] = gracz;
			UstawPlansze(pola);
			if (wystrzelPocisk(gracz, x, y, pola) == -1)
			{
				pola[y][x] = 0;
				pola[ystart][xstart] = gracz;
				return -1;
			}
		}
		else if (yvector > 0 && xvector < 0)//lewo w dol
		{
			i--;
			j++;
			while (i >= x)
			{
				if (pola[j][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
				i--;
				j++;
			}
			pola[ystart][xstart] = 0;
			pola[y][x] = gracz;
			UstawPlansze(pola);
			if (wystrzelPocisk(gracz, x, y, pola) == -1)
			{
				pola[y][x] = 0;
				pola[ystart][xstart] = gracz;
				return -1;
			}
		}
		else
		{
			cout << "Ruch niedozwolony.";
			return -1;
		}
	}
	else if (powxvector != powyvector)
	{
		if (yvector == 0 && xvector > 0) //ruch w prawo
		{
			i++;
			for (i; i <= x; i++)
			{
				if (pola[y][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
			}
			pola[ystart][xstart] = 0;
			pola[y][x] = gracz;
			UstawPlansze(pola);
			if (wystrzelPocisk(gracz, x, y, pola) == -1)
			{
				pola[y][x] = 0;
				pola[ystart][xstart] = gracz;
				return -1;
			}
		}
		else if (yvector == 0 && xvector < 0) //ruch w lewo
		{
			i--;
			for (i; i >= x; i--)
			{
				if (pola[y][i] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
			}
			pola[ystart][xstart] = 0;
			pola[y][x] = gracz;
			UstawPlansze(pola);
			if (wystrzelPocisk(gracz, x, y, pola) == -1)
			{
				pola[y][x] = 0;
				pola[ystart][xstart] = gracz;
				return -1;
			}
		}
		else if (yvector < 0 && xvector == 0) //ruch w gore
		{
			j--;
			for (j; j >= y; j--)
			{
				if (pola[j][x] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
			}
			pola[ystart][xstart] = 0;
			pola[y][x] = gracz;
			UstawPlansze(pola);
			if (wystrzelPocisk(gracz, x, y, pola) == -1)
			{
				pola[y][x] = 0;
				pola[ystart][xstart] = gracz;
				return -1;
			}
		}
		else if (yvector > 0 && xvector == 0) //ruch w dol
		{
			j++;
			for (j; j <= y; j++)
			{
				if (pola[j][x] != 0)
				{
					cout << "Cos stoi na drodze!";
					return -1;
				}
			}
			pola[ystart][xstart] = 0;
			pola[y][x] = gracz;
			UstawPlansze(pola);
			if (wystrzelPocisk(gracz, x, y, pola) == -1)
			{
				pola[y][x] = 0;
				pola[ystart][xstart] = gracz;
				return -1;
			}
		}
		else
		{
			cout << "Ruch niedozwolony.";
			return -1;
		}
	}
	return 0;
}
bool ruchwgore(int xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	if (ystart - 1 >= 0) {
		if (pola[ystart - 1][xstart] != 0) //pole nie jest puste
			return false;	//nie mozna zrobic ruchu
		else
			return true;
	}
	else
		return false;
}
bool ruchwprawo(int xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	if (xstart + 1 <= 9) {

		if (pola[ystart][xstart + 1] != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
bool ruchwlewo(int xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	if (xstart - 1 >= 0) {
		if (pola[ystart][xstart - 1] != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
bool ruchwdol(int xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	if (ystart + 1 <= 9) {
		if (pola[ystart + 1][xstart] != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
bool ruchwprawogore(int xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	if (ystart - 1 >= 0 && xstart + 1 <= 9) {
		if (pola[ystart - 1][xstart + 1] != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
bool ruchwlewogore(int xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	if (ystart - 1 >= 0 && xstart - 1 >= 0) {
		if (pola[ystart - 1][xstart - 1] != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
bool ruchwdolprawo(int xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	if (ystart + 1 <= 9 && xstart + 1 <= 9) {
		if (pola[ystart + 1][xstart + 1] != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
bool ruchwdollewo(int xstart, int ystart, int pola[ILOSC_POL][ILOSC_POL])
{
	if (ystart + 1 <= 9 && xstart - 1 >= 0) {
		if (pola[ystart + 1][xstart - 1] != 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
int koniecGry(int gracz, int pola[ILOSC_POL][ILOSC_POL])
{
	int liczbapiongracz = 4;
	int liczbapionprzeciwnik = 4;
	int przeciwnik = 0;
	if (gracz == 1)
		przeciwnik = 2;
	if (gracz == 2)
		przeciwnik = 1;
	for (int i = 0; i < ILOSC_POL; i++)
	{
		for (int j = 0; j < ILOSC_POL; j++)
		{
			if (pola[i][j] == gracz)
			{
				bool mozliwyruch = (ruchwdol(j, i, pola) || ruchwgore(j, i, pola) || ruchwlewo(j, i, pola) || ruchwprawo(j, i, pola) || ruchwprawogore(j, i, pola) || ruchwdolprawo(j, i, pola) || ruchwlewogore(j, i, pola) || ruchwdollewo(j, i, pola));
				if (!mozliwyruch)
					liczbapiongracz--;
			}
			if (pola[i][j] == przeciwnik)
			{
				bool mozliwyruch = (ruchwdol(j, i, pola) || ruchwgore(j, i, pola) || ruchwlewo(j, i, pola) || ruchwprawo(j, i, pola) || ruchwprawogore(j, i, pola) || ruchwdolprawo(j, i, pola) || ruchwlewogore(j, i, pola) || ruchwdollewo(j, i, pola));
				if (!mozliwyruch)
					liczbapionprzeciwnik--;
			}
		}
	}
	if (liczbapionprzeciwnik == 0)
	{
		cout << "Koniec Gry! Wygrywa gracz nr: " << gracz;
		return 1;
	}
	if (liczbapiongracz == 0)
	{
		cout << "Koniec Gry! Wygrywa gracz nr: " << przeciwnik;
		return 1;
	}
	return 0;
}


int ruchGracza(int gracz, int pola[ILOSC_POL][ILOSC_POL]) //wejscie do wybrania pionka i sprawdzenie czy poprawny
{
	cout << "Gracz: " << gracz << endl;
	char x = 0; //gracz podaje litere kolumny
	int y = 0; //gracz podaje liczbe wierwsza (int zeby zmiescic liczbe 10 w zmiennej)
	cout << "Wpisz kolumne pionka (od A do J): " << endl;
	while (!(cin >> x/* >> x*/)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Zle wartosci." << endl;
		return -1;
	}
	x = x - 'A'; //uzyskanie liczbowej wartosci z przedialu od 0 do 9
	cout << "Wpisz wiersz pionka (od 1 do 10): " << endl;
	while (!(cin >> y)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Zle wartosci." << endl;
		return -1;
	}
	y = 10 - y; //odwrocenie wierszy
	if (!dobreDane(gracz, x, y, pola)) {
		cout << "Bledne wspolrzedne pionka" << endl;
		return -1;//gracz nie traci kolejki
	}
	if (-1 == przesunPionek(gracz, x, y, pola)) //przesuniecie pionka we wskazane miejsce
		return -1;
	return 0;
}
int main() {
	int plansza[ILOSC_POL][ILOSC_POL];
	startPlansza(plansza);
//	UstawPlansze(plansza);
	int gracz = 0;

	while (true)
	{
		gracz = gracz % 2 + 1;


		if (koniecGry(gracz, plansza) == 1)
			break;
		//system("cls");
		UstawPlansze(plansza);
		if (ruchGracza(gracz, plansza) == -1) {
			gracz--;
			system("pause");

		}
		//system("pause");
	}


	system("pause");
	return 0;
}
