// cd C:\Users\USER\Documents\Programy_CPP\GreboszC++11
// code C:\Users\USER\Documents\Programy_CPP
// .\GreboszC++11.exe

// skonczylem 526

#include <iostream>
#include <time.h>

using namespace std;

class naterzenie
{   
    public:
    //Dla checy zmienna A zadeklarowalem na koncu klasy, zeby pokazac ze sie da :D
    naterzenie(int A)
    {
        this->A = A;
    }
    int get()
    {
        return this->A;
    }
    int oblicz()
    {
        return A*A;
    }
    int A = 0; //od c++11 można inicjalizować zmienne w klasie
};

int oblicz(naterzenie A)
{
    int tmp = A.get() + 2; //ooo dodało się 
    return(tmp * tmp);
}

int main()
{
    clock_t tStart = clock();
    //--------------------------------------------------------------------------------
    naterzenie a(2);

    cout << "Wartosc parametru zmiennej A w obiekcie natzerzenie: " << a.A << endl;
    cout << "Wartosc wyniku funkcji oblicz nie bedaca metoda: " << oblicz(a) << endl;
    cout << "Wartosc wyniku funkcji oblicz bedaca metoda: " << a.oblicz() << endl;


    cout << "-------------------------------------------------------Koniec---------------------------" << endl;
    printf("Czas wykonania programu: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);//ex2
    getchar();
    return 0;
}
//*****************************************************************************************************************
