// cd C:\Users\USER\Documents\Programy_CPP\GreboszC++11
// code C:\Users\USER\Documents\Programy_CPP\
// .\GreboszC++11.exe

// skonczylem 504

#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

using napiecie = int;

int main()
{
    clock_t tStart = clock();           //ex2


    //--------------------------------------------------------------------------------

    cout << "-------------------------------------------------------Koniec---------------------------" << endl;
    printf("Czas wykonania programu: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);//ex2
    getchar();
    return 0;
}
//*****************************************************************************************************************
