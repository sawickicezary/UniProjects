#include <iostream> 
using namespace std; 

unsigned long algorytm(unsigned long long n, unsigned long long k) 
{
    if (k == 0) 
		return 0; //rozwiazanie dla k-tej osoby
    if (n == 1) 
		return 1; 
    
	else
		return (algorytm(n - 1, k-1) + 1) % n + 1; //wzór rekurencyjny
}

int main() 
{
	int l; //ilosc linii
	cin >> l;
	
    for (int i =0; i < l; i++)
    {
        unsigned long long n; // liczba ludzi
    	long long k; // k-ta z kolei zabita osoba
    
        cin >> n >> k; //wejscie

        
        if (k < 0)	
            k = n + k + 1; //odwrocenie ujemnej liczby k 
    
    	 cout << algorytm(n, k)<<endl; //wyjscie

    }
    
		return 0; 
}
