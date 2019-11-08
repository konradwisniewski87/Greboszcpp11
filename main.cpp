// cd C:\Users\USER\Documents\Programy_CPP\GreboszC++11
// code C:\Users\USER\Documents\Programy_CPP\
// .\GreboszC++11.exe
// skonczylem 197
#include <iostream>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>

//#define tim_sek
void funkcjaTestow(int zmienna);
auto funkcjaTestowa2(int k, double r) -> decltype(k); //Grebosz 181

using namespace std;

//typedef int napiecie;
using napiecie = int;
int zmienna123 = 7;
using nowa_nazwa_typu = decltype(zmienna123);

napiecie funkcja(napiecie V){
    return V + 2;
}

int main()
{
    clock_t tStart = clock();           //ex2
#ifdef tim_sek
    time_t start, koniec;               //ex1
    time(&start);                       //ex1
#endif
    //system("cls"); //czysci konsole ale nie działa
    //--------------------------------------------------------------------
    /*time_t sekundy;
    sekundy = time( NULL );
    cout << sekundy / 3600 << " godzin uplynelo od 1 stycznia 1970r.";*/
    //--------------------------------------------------------//ex1------------
    /*cout << "-----------------Radwag-----------------" << endl;
    uint64_t dualdeviceserial = 1234567891234567;
    char tab[17] = {0};
    sprintf(tab, "%lli" , dualdeviceserial);   //int to string
    cout << "Liczba to: " << tab << endl;
    cout << "-----------------Radwag-----------------" << endl;*/

#ifdef tim_sek
    time(&koniec);                      //ex1
    cout << koniec-start << "sek";      //ex1
#endif

    int zmienna1 = 2;
    napiecie zmienna2 =2;
    cout << "----------------------------NAPIECIE--------------------------" << endl;
    cout << funkcja(zmienna1) << endl; // hyba bubel skoro do zmiennej napiecie wysyłam int bez zutowania i dziala
    cout << funkcja(zmienna2) << endl;

    enum typ_podwaliny : int {lol33, lol2 = 2, lol3 = lol2, lol23 = lol2 + lol3}; //dlaczego nie diala enum class
    enum typ_podwaliny2 : int {lol34, lol22 = 2};
    enum class typ_podwaliny3 : int {lol41, lol42 = lol41};
    //if(lol33 == lol34)//mozliwe jak jest enum a nie enum class
    if(static_cast<int>(typ_podwaliny::lol33) == static_cast<int>(typ_podwaliny2::lol34)) //dla enum class rzutujemy
    {
        cout << "Wartosci roznych enumow sa sobie rowne" << endl;
    }
    cout << typ_podwaliny::lol23 << endl;
    int zmienna = lol2;
    decltype(zmienna) zmienna3 = zmienna; //decltype(zmienna) -> typ zmiennej zmienna
    //cout << lol2 + 100 << endl; //mozliwe jak jest enum a nie enum class
    if((lol2 == lol23)? 1 : 0)//lol2 == lol3 lol2 == lol23
        cout << "Wartosci sa sobie rowne." << endl;
    else
        cout << "Rozne!" << endl;

    cout << "Rozmiar int x64: " << sizeof(int) << endl;
    //static_assert(bool_constexpr , tekst_informujacy );
    int f = 1, g = 5, k, l, o, p;
    f = k = l = o = p = g; //Przypisuje od prawej do lewej bo równasię jest operatorem prawostronnym
    cout << "---->" << f << endl;
    string tekst{"tekst "};
    string tekst2 = "tekst2 " + tekst;
    cout << tekst2 << endl;
    vector<int> va{5}; //vektor z jednym elementem o wartosci 5
    vector<int> vb(5); //vektor piecio elementowy
    vector<char> znak(3,'.'); //vektor trzyelementowy, każdy indeks inicjalizowany kropką
    vector<string> godnosc;
    godnosc.push_back("Konrad");
    godnosc.push_back("Kamil");
    godnosc.push_back("Monika");
    godnosc.push_back("Wiktoria");
    cout << "Ile elementow -> " << godnosc.size() << endl;
    for(int i = 0; i < godnosc.size(); i++)
    {
        cout << i << "-ta wartosc: " << godnosc[i] << endl;
    }
    godnosc.pop_back();
    cout << "Ile elementow2 -> " << godnosc.size() << endl;
    for(auto element: godnosc) //przkazywana kopia
    {
        cout << "Nazwa1 " << " " << " elementu to: " << element << endl;
        element += '1';
    }
    for(auto & element: godnosc) //Przekazywany oryginał(referencja)
    {
        cout << "Nazwa2 " << " " << " elementu to: " << element << endl;
        element += "2"; //pracuje na lokalnej wartosci, znak 2 bedzie zomniany poza ta finckj
    }
    for(auto & element: godnosc) //Przekazywany oryginał(referencja)
    {
        cout << "Nazwa3 " << " " << " elementu to: " << element << endl;
        element += "3"; //pracuje na lokalnej wartosci, znak 2 bedzie zomniany poza ta finckj
    }
    for(const auto & element: godnosc) //Gdy mamy duże tablice i chcemy pracować na oryginale ale boimy się, że coś zostanie zmienione
    {
        cout << "Nazwa4 " << " " << " elementu to: " << element << endl;
    }
    string napis{"Zrobmy amerykanom na zlosc i zatrudnijmy Tomtasa!"};
    //string napis = "Zrobmy amerykanom na zlosc i zatrudnijmy Tomtasa!";
    for(auto znak : napis)
    {
        cout << znak << "-";
    }
    cout << endl;
    cout << "-------------------------------------------------------FUNKCJE---------------------------" << endl;
    funkcjaTestow(5);
    cout << funkcjaTestowa2(101, 1.2) << endl;
    //cout << "-------------------------------------------------------lvalue, rwalue---------------------------" << endl;
    // 50 = zmienna; // 50 is not a lvalue 
        // wyrażenie które nie może stać po lewej stronie nazywamu rvalue
    // a + b = 10; // wyrażenie a + b nie jest lvalue
    //  a = (6 + a) * 3;//lvalue moze tez stać po prawej stronie
    // lvalue to miejsce w pamieci którego adres możemy poznać(może to być sam obiekt, obiekt przekazany jako referencja, obiekt przekazany wskaźnikiem)
    // inaczej, jeśli coś ma nazwę to jest lvalue.
    // !!!!!!!!!!! lvalue to zmienna, obiekt. rvalue to wartośc chwilowa, obiekt chwilowy lub napisana dosłownie liczba.
    // nie można przesłać liczby jako referencja prze lvalue(int funkcja(int & zmienna)[funkcja(9);], ale można jeśli prześlemy jako const (int funkcja(const int & zmienna))











    cout << "-------------------------------------------------------Koniec---------------------------" << endl;
    printf("Czas wykonania programu: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);//ex2
    getchar();
    return 0;
}
//------------------------------------------------------------------------------
auto funkcjaTestowa2(int k, double r) -> decltype(k)
{
    //int i = 2;
    return k;
}

void funkcjaTestow(int zmienna)
{
    if(zmienna == 5)
    {
        cout << "Zmienna rowna jest 5" << endl;
        return;
    }
    else
    {
        cout << "Zmienna jest rozna od 5" << endl;
    }
    cout << "A to sie nie wykona jesli jest rowna 5" << endl;
}