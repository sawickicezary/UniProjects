//POP_2019_01_25_projekt_2_Sawicki_Cezary_EIT_3_175723.cpp Visual Studio 2017 Community Version, Visual C++ 2017
#include <iostream>
#include <fstream>
using namespace std;
struct Bytes {
	unsigned char prev = 0xAA, buf, encrypt;
	int key;
};
int encryption()
{
	Bytes Byte;
	ifstream file;
	file.open("unencrypted.bin", std::ios::binary);
	cout << "Podaj klucz do szyfrowania w hex: ";
	cin >> hex >> Byte.key; //Klucz w hexdecymalnym
	if (!file) {
		cout << "Brak pliku.";
		return 1;
	}

	while (file.read((char*)&Byte.buf, 1))
	{
		Byte.encrypt = Byte.prev^Byte.key;
		Byte.buf ^= Byte.encrypt;
		cout<<hex<<(int)Byte.buf<<endl;
		Byte.prev = Byte.buf;
	}
	file.close();

}
int decryption()
{
	Bytes Byte;
	ifstream file;
	file.open("encrypted.bin", std::ios::binary);
	cout << "Podaj klucz do deszyfrowania w hex: ";
	cin >> hex >> Byte.key; //Klucz w hexdecymalnym
	if (!file) {
		cout << "Brak pliku.";
		return 1;
	}
	while (file.read((char*)&Byte.buf, 1))
	{
		Byte.encrypt = Byte.prev^Byte.key;
		Byte.prev = Byte.buf;
		Byte.buf ^= Byte.encrypt;
		cout << hex << (int)Byte.buf << endl;
	}
	file.close();
}
void pomoc() {
	system("cls");
	cout << "Aby zaszyfrowac plik nalezy umiescic go w tym samym folderze co program, nadac mu nazwe unencrypted oraz dac rozszerzenie .bin" << endl;
	cout << "Aby deszyfrowac plik nalezy umiescic go w tym samym folderze co program, nadac mu nazwe encrypted oraz dac rozszerzenie .bin" << endl;
}
int main() {
	int choice;
	cout << "Wpisz 1 aby szyfrowac, 2 aby deszyfrowac, 3 aby uzyskac pomoc: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		encryption();
		break;
	case 2:
		decryption();
		break;
	case 3:
		pomoc();
		break;
	default:
		break;
	}
	system("pause");
}
