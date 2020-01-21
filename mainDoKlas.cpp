// cd C:\Users\USER\Documents\Programy_CPP\GreboszC++11
// code C:\Users\USER\Documents\Programy_CPP\
// .\GreboszC++11.exe
//ominalem Wektory wielowymiarowe 322 - 354
//opusciolem wskaznik o typu const

// skonczylem 442


#include <iostream>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>
//#include "C:\Users\USER\Documents\Programy_CPP\GreboszC++11\farma.h"
//#include "farma.h"

//#define tim_sek

using namespace std;

void funkcjaTestow(int zmienna);
auto funkcjaTestowa2(int k, double r) -> decltype(k); //Grebosz 181
void temperatura(float, int = 0); // danie = 0 w definicji nic nie dało, musi być w deklaracji
int kwadrat(int x) {return x * x;}
void czerwona();
void czerwona2();
void potrojenie (int ile, int t[ ]);
void strcpy(char cel, char zrodlo);
void hydraulik(int * wskaznikDoKranu);
void hydraulikTab(int wskaznikDoKranu[]);
void funkcja_wska(int *wsk, int rozmiar);
void funkcja_wsk2(int *wsk, int rozmiar);

void funkcja_tabl(int tab[ ], int rozmiar);

//tablica w c++ przesyłana jest bezposrednio do funcji, wiec nie trzeba wskaznika, ale przez wskasnik tez sie da
void fun_wsk(int * wsk, int rozmiar);
void fun_tab(int tab[], int rozmiar);
void fun_wsk_const(const int * wsk, int rozmiar); //tablica nie musi byc const, funkcja gwarantuje niezmiennosc
void fun_tab_const(const int tab[], int rozmiar);

void przedzielacz_tabl(const char tab[ ]);
void przedzielacz_wsk(const char *w);
char * strcpy(char *cel, const char *zrodlo);
char * strcat(char *cel, const char *zrodlo);

//typedef int napiecie;
using napiecie = int;
int zmienna123 = 7;
using nowa_nazwa_typu = decltype(zmienna123);
const int globalna = 8;

class Zwierze
{
public:
    Zwierze();
    virtual void dajGlos();
};

class Mucka : public Zwierze
{
public:
    Mucka();
    void dajGlos();
};

class Pies : public Zwierze
{
public:
    Pies();
    void dajGlos();
};

class Kogut : public Zwierze
{
public:
    Kogut();
    void dajGlos();
};



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
    temperatura(20);
    temperatura(20,1);
    //cout << "-------------------------------------------------------lvalue, rwalue---------------------------" << endl;
    // 50 = zmienna; // 50 is not a lvalue
        // wyrażenie które nie może stać po lewej stronie nazywamu rvalue
    // a + b = 10; // wyrażenie a + b nie jest lvalue
    //  a = (6 + a) * 3;//lvalue moze tez stać po prawej stronie
    // lvalue to miejsce w pamieci którego adres możemy poznać(może to być sam obiekt, obiekt przekazany jako referencja, obiekt przekazany wskaźnikiem)
    // inaczej, jeśli coś ma nazwę to jest lvalue.
    // !!!!!!!!!!! lvalue to zmienna, obiekt. rvalue to wartośc chwilowa, obiekt chwilowy lub napisana dosłownie liczba.
    // nie można przesłać liczby jako referencja prze lvalue(int funkcja(int & zmienna)[funkcja(9);], ale można jeśli prześlemy jako const (int funkcja(const int & zmienna))
cout << "-------------------------------------------------------WARTOSC DOMNIEMANA FUNKCJI---------------------------" << endl;
void funkcja(int a = 0, int b = 2);
funkcja();
cout << "Powyzej a = 0 a b = 2 " << endl;
    {
        funkcja();
        cout << "Powyzej a = 0 a b = 2 " << endl;

       // void funkcja(int a = 0, int b); //wywali bład jesli zmieniamy jedno w zakresie ważności(wewnatrz funcki), to i drugie
       //dziala jak zaslanianie nazw, albo odwolujesz sie do wczesniejszej albo do tej deklaracji
       void funkcja(int a, int b = 5);
       //funkcja();  //wywali błąd bo powyzsza delkaracja nie pamieta domniemanego a
       funkcja(7);
       cout << "Powyzej a = 7 a b = 5 " << endl;

       int lokalan1 = 2;
       //void funkcja(int a, int b = lokalan1); //wartosc lokalna nie moze byc wartoscia domniemana
       //void funkcja(int a = kwadrat(lokalan1), int b = 5); // ponownie zmienna lokalna
        void funkcja(int a = kwadrat(globalna), int b); //b wziete z góry ale w ramach tego samego zakresu ważności, zmienna123 globalna
        //ciekawe czy może być wskaźnik na zmienną lokalną??
       funkcja();
       cout << "Powyzej a = 64 a b = 5 " << endl;
    }
    funkcja();
    cout << "Powyzej a = 0 a b = 2, poza zakresem lokalnym racamy do poczatku" << endl;

    cout << "-------------------------------------------------------FUNKCJE C.D.---------------------------" << endl;
    czerwona();
    czerwona2();
    cout << "Drugie wywołanie" << endl;
    czerwona();
    czerwona2();
    cout << "-------------------------------------------------------WARTOSC DOMNIEMANA FUNKCJI---------------------------" << endl;

    cout << "-------------------------------------------------------PREPROCESOR---------------------------" << endl;
    //#define PASAZER_NA_STEWARD (MAX_LICZBA_PASAZEROW/MAX_LICZBA_STEWARDOW) //musi byc za wykozystywanymi wartosciami
    #define MAX_LICZBA_PASAZEROW 250
    #define MAX_LICZBA_STEWARDOW 8
    #define PASAZER_NA_STEWARD (MAX_LICZBA_PASAZEROW/MAX_LICZBA_STEWARDOW)
/*
    #define PASAZ_NA_STEWD \
            (MAX_LICZBA_PASAZEROW/ LICZBA_STE\
            WARDOW)*/ //ponoc dziala dla wielu linijek

    cout << "Maksymalnie pasażerow: " << MAX_LICZBA_PASAZEROW << endl;
    cout << "Maksymalnie stewardow: " << MAX_LICZBA_STEWARDOW << endl;
    cout << "Pasazerow na stewarda: " << PASAZER_NA_STEWARD << endl;
    cout << "Pasazerow na stewarda: PASAZER_NA_STEWARD" << endl; //nie podmieni bo string

    //stary sposób
        #define ROZDZIELCZOSC 8192
        long int widmo[ROZDZIELCZOSC];
    //nowy sposób
        constexpr int rozdzielczosc2 = 8192; // definicja stalej
        long int widmo2[rozdzielczosc2]; // skorzystanie z niej
    #undef MAX_LICZBA_PASAZEROW //kasuje deniniowanie przydatne zwłaszcza jak robimy #include do pliku hedera w którym jest taka pełno #define i chcemy się ich pozbyć lub jes zastąpić
    #undef MAX_LICZBA_STEWARDOW
    #undef PASAZER_NA_STEWARD


    #define KWADR(a) ((a)*(a))
    cout << "Kwadrat 5 to: " << KWADR(5) << endl; //Wyświetli --> Kwadrat 5 to: 25
    // muka przy makrodefinicjach --> KWADR(x++); --> ((x++) * (x++)); dwukrotnie zinkrementuje x zamiast 4++=5 teraz jest 6
    //jednak inne od inline

    string konrad = "Konrad";
    cout << "Rozmiar stringu: " << konrad.size() << endl;

    #define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )
        //Mozemy z niej korzystac niezaleznie, czy porównujemy ze sobe dwie liczby, czy dwa adresy, czy tez znaki.
    cout << "Co jest wieksze?: " << MAX(3,4) << endl;
        //Chcac napisac to samo jako funkcje typu inline, nalezaloby dokladnie okreslic typ argumentów

    #define WYR(a,b,c) a * b + c
    //y = WYR(2, 1 + 6.5, 0) * 1000;
    //:-( dostaniemy muke
    //y = 2 * 1 + 6.5 + 0 * 1000;
    //Czyli zamiast obliczyæ (2 * (1 + 6.5) + 0 ) * 1000), obliczymy ((2 * 1) + 6.5 + (0 * 1000)).
    //żeby nie było muki robimy tak #define WYR(a,b,c) ( (a) * (b) + (c) )

    #define ST(co,jaki) co ## jaki
    //int ST(statecznik,Poziomy);
    //int statecznikPoziomy;
    //string tmp = ST(konrad, wisniewski); //potraktuje konrad wisniewski jako nazwe zmiennej
    //string tmp = "ST(konrad, wisniewski)"; //potraktuje jeko stringa i nie podmieni
    //cout << tmp << endl;
    //jak kiedyś próbowałem posklejać nazwy w STM32 PIN_ ## 3 to nie zadziałało

    #define WYPISZ(par) cout << #par << " = " << par << endl; //#par zamienione zostanie na napis
    int y = 6; double pi = 3.14;
    WYPISZ(y); // czyli to samo co: cout << "k" << " = " << k << endl;
    WYPISZ(2 * pi); // czyli to samo co: cout << "2*pi" << " = " << 2*pi << endl;

    #define zmienna123456 6
    #if zmienna123456 > 5
    cout << "y > 5, y = " << zmienna123456 << endl;
    #endif

    #if zmienna123456 < 5
    cout << "y <= 5, y = " << zmienna123456 << endl;
    #endif
    #if zmienna123456 > 99
        #error "Blad, bo WERSJA nie może być trzycyfrowa" //Wywali błąd kompilatora
    #endif



    /*
        · #if NAZWA == NAZWA2
        · #if NAZWA > 2
        · #if (NAZWA_A == 2 || NAZWA_B > 10)
        · #if NAZWA == 6 && defined(WERSJA_ROBOCZA)
    */
   //#define Kompilacja_warunkowa //defined z "d" na koncu, nie istnieje
   #ifdef Kompilacja_warunkowa
    cout << "#ifdef" << endl;
   #else
    cout << "#ifdef" << endl;
   #endif

   #ifndef Kompilacja_warunkowa
    cout << "#ifndef" << endl;
   #endif

    //Zamianst #include stosujemy:
    #ifndef PLIK_X
    #define PLIK_X
    //zwykla tresc pliku
    #endif

    // W wagach został,o to zrobione tak, że: w pliku na frame.h jest jak poniżej
    //#ifndef _FRAME_H_
    //#define _FRAME_H_
    //nazwa obojetne jaka ale zeby była oryginalna w projekcie i z DUZYCH LITER !!!!! bo znowu bede sie pierdzielił dzien dlaczego głupoty wychodzą
    //ile razy by nie był inkludowany ten plik, każda istancja sprawdza najpier czy już nie był inkludowany, i tak w każdym hederze np:
    //#ifndef _SYSTEM_H_
    //#define _SYSTEM_H_

    cout << "-------------------------------------------------------TABLICE---------------------------" << endl;

    {    //lokalne wywołanie bo tablice mi sie klocily
        static int tab[9];  //tablice globalne i static mają zerowane wartości elementów, lokalne mają smieci
        for(int zmienna : tab)
        {
            cout << "Zmienna: " << zmienna << endl;
        }
    }

    //Jesli mamy zdefiniowac tablice obiektów stalych (const lub constexpr), to inicjalizacja
    //zbiorcza jest jedyna szansa umieszczenia w niej wartosci.
    const int dni_w_miesiacach[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int tab[8] = {1,2,3,4,5};
    cout << "tab[1] = " << tab[1] << endl;
    cout << "tab + 1 = " << tab + 1 << endl; //adres
    cout << "&tab[1] = " << &tab[1] << endl; //adres

    cout << "*(tab + 1) = " << *(tab + 1) << endl; //adres

    cout << "Tablica ma " << sizeof(tab)/sizeof(decltype(tab)) << " elementow." << endl;
    cout << "Element tab[2] jeste rowny: " << tab[2] << endl;
    // jesli rozmiar tablicy bedzie wartoscia constexpr to moge wstawis w wywolanie funkcji
    // np: constexpr int rozmiar = 8123;
    //potrojenie (rozmiar, tab);
    potrojenie (sizeof(tab)/sizeof(decltype(tab)), tab);
    cout << "A teraz tab[2] jeste rowny: " << tab[2] << endl;

    /*int zmienna91234 = 3;
    cin >> zmienna91234;
    int tab123[zmienna91234] = {0}; //to chyba nie powinno się skompilować
    cout << "A teraz zmienna91234 jeste rowny: " << tab123[2] << endl;*/
    //Ciekawostka! wpisanie zwraca wartość liczby przypisywanej albo zaku ascii czyli, patrz cialo ponizszej funkcji:
    char tab2[14] {0};
    char tab3[14] = "Zuzanna:D";
    strcpy(tab2, tab3);
    cout << tab2 << endl;
    cout << tab3 << endl;
    /*int nr_rzedu=3;
    int nr_kolumny=6;
    int tab232[nr_rzedu][nr_kolumny];
    for(int nr_rzedu = 0 ; nr_rzedu < 3 ; ++nr_rzedu)
    {
        for(int nr_kolumny = 0 ; nr_kolumny < 6 ; ++nr_kolumny)
        {
            tab232[nr_rzedu][nr_kolumny] = (nr_kolumny + 1) * (nr_rzedu + 1);
            cout << tab232[nr_rzedu][nr_kolumny] << " | ";
        }
        cout << endl; // po kazdym rzedzie – przejoecie do nowej linii
    }

    int tab2324[3][6] = { 1, 2, 3,  4,  5,  6, 7, 8, 9, 10, 11, 12, 1, 1, 1, 11, 11, 11 };
    int tab2323[3][6] = { 1, 2, 3,  4,  5,  6,
                          7, 8, 9, 10, 11, 12,
                          1, 1, 1, 11, 11, 11 };
    int tab114[4][2] = { { 10, 20 }, { 30 }, { 60, 70 }, { 80 } };*/

    /*
    Dla wtajemniczonych: w przypadku tablicy elementów typu zdefiniowanego
    przez uzytkownika, {0} zamiast wstawiania zera – dla danego elementu tablicy, niemajacego inicjalizatora – zostanie uruchomiony jego konstruktor domniemany.
    */
   int * wsk7 {}; // to to samo co int * wsk7 = nullptr; przecież klamry {} inicjalizują wartoscia defoltowa dla danego rodzaju wartości, czyli 0, 0.0, nullptr

   int cena_1 = 10, cena_2 = 100;

   //int *wskaznik_cena;
    //wskaznik_cena = &cena_1; //lub
    int *wskaznik_cena = &cena_1;

    cout << "Wartosc zmiennej cena_1 = " << cena_1 << endl;
    cout << "Adres komorki zmiennej cena_1 = " << &cena_1 << endl;
    cout << "Wartosc wskaznika = " << *wskaznik_cena << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Adres komorki wskaznik_cena = " << wskaznik_cena << endl;
    cout << "Moj test = " << &wskaznik_cena << endl;  //moj test, adres wskaznika a nie na który pokazuje wskaznik
    cout << "------------------------------------------------" << endl;
    cout << "Wartosc zmiennej cena_2 = " << cena_2 << endl;
    cout << "Adres komorki zmiennej cena_2 = " << &cena_2 << endl << endl;

    cena_1 = 22;

    cout << "Wartosc zmiennej cena_1 = " << cena_1 << endl;
    cout << "Adres komorki zmiennej cena_1 = " << &cena_1 << endl;
    cout << "Wartosc wskaznika = " << *wskaznik_cena << endl;
    cout << "Adres komorki wskaznik_cena = " << wskaznik_cena << endl << endl;

    *wskaznik_cena = 33;

    cout << "Wartosc zmiennej cena_1 = " << cena_1 << endl;
    cout << "Adres komorki zmiennej cena_1 = " << &cena_1 << endl;
    cout << "Wartosc wskaznika = " << *wskaznik_cena << endl;
    cout << "Adres komorki wskaznik_cena = " << wskaznik_cena << endl << endl;

    wskaznik_cena = &cena_2;

    cout << "Wartosc zmiennej cena_2 = " << cena_2 << endl;
    cout << "Adres komorki zmiennej cena_2 = " << &cena_2 << endl;
    cout << "Wartosc wskaznika = " << *wskaznik_cena << endl;
    cout << "Adres komorki wskaznik_cena = " << wskaznik_cena << endl;

    cout << "----------------------------Na tablicy----------------------" << endl;
    int size = strlen(tab3);
    for(int i = 0; i < size; i++)
    {
        cout << tab3 + i << " gdzie i to: " << i << endl;  //wypisze tablicę od i-tej komórki
    }

    cout << endl << endl;

    for(int i = 0; i < size; i++)
    {
        cout << tab3[i] << " gdzie i to: " << i << endl;  //wypisze konkretna komorke tablicy
    }

    cout << endl << endl;
    cout << "----------------------------Na wskazniku----------------------" << endl;
    char *wsk3 = tab3;

    for(int i = 0; i < size; i++)
    {
        cout << wsk3 + i << " gdzie i to: " << i << endl;  //wypisze tablicę od i-tej komórki
    }

    cout << endl << endl << "cout << wsk3[i] <<  gdzie i to:  << i" << endl;

    for(int i = 0; i < size; i++)
    {
        cout << wsk3[i] << " gdzie i to: " << i << endl;  //wypisze konkretna komorke tablicy
    }

    cout << endl << endl;

    cout << "Adres wskaznika = " << &wsk3 << endl; //wyłuskał adres wskaznika a nie tego na co pokazuje
    printf("%i\n", wsk3);   //wyluskał adres na który pokazuje wskaznik
    for(int i = 0; i < size; i++)
    {
        cout << wsk3++ << " gdzie i to: " << i << endl;  //wypisze konkretna komorke tablicy
    }
    cout << "Adres wskaznika = " << &wsk3 << endl; //wyłuskał adres wskaznika a nie tego na co pokazuje
    printf("%i\n", wsk3);                         //wyluskał adres na który pokazuje wskaznik
    cout << "Nie wiedziałem jak wyswietlic adres coutem a to takie proste: " << reinterpret_cast<unsigned long long>(wsk3) << endl;
    int kran = 1;
    int *wskaznikDoKranu = &kran;
    hydraulik(wskaznikDoKranu); //Przesyłam hydraulikowi adres zmiennej, wskaznik, bo wskaznik to adres
    cout << "Przeslane wskaznikiem: " << kran << endl;

    hydraulik(&kran); //Przesyłam adres zmiennej
    cout << "Przeslane zmiennej adresem: " << kran << endl;

    int tab84[2] {3,4};
    cout << tab84[0] << endl;
    cout << tab84[1] << endl;
    hydraulikTab(tab84);
    cout << tab84[0] << endl;
    cout << tab84[1] << endl;
    int tablica_testowa[5] {};//inicjalizuje defoltową wartoscia 0
    hydraulik(&tablica_testowa[1]); //Przesyłam adres zmiennej
    cout << "Tablica testowa, wyslono jeden element: " << tablica_testowa[1] << endl;
    for(int i = 2 ; i <= 5 ; ++i)
    {
        hydraulik(&tablica_testowa[i]);
    }
    for(int i = 2; i <= 5; ++i)
    {
        cout << "Wartosc tablicy o indeksie: " << i << " jest rowna: " << tablica_testowa[i] << endl;
    }

    int tafla[4] = { 5,10,15,20};
    funkcja_tabl(tafla, 4);
    funkcja_wska(tafla, 4);
    funkcja_wsk2(tafla, 4);
    cout << endl << endl;
    fun_wsk(tab84, 2);
    fun_tab(tab84, 2);
    fun_wsk_const(tab84, 2);
    fun_tab_const(tab84, 2);
    const int tablica_S[4] = { 10,20,30,40};
    //fun_wsk(tablica_S, 4); // blad, nie mozna wyslac tablicy typu const to funkcji bez const
    fun_wsk_const(tablica_S, 4);

/*
W mikrokontrolerach jak mamy adres komorki pamieci o adresie 93952 to robimy tak
    int *wsk_temperatury;
    wsk_temperatury = reinterpret_cast<int *>(93952);
*/
    cout << "----------------------------Udemy C++ Polimorfizm----------------------" << endl;
    Zwierze animal; //jesli virtual i =0 to nie tworzymy
    Mucka cow;
    Pies dog;
    Kogut rooster;

    //animal.dajGlos(); //jesli virtual i =0 to nie tworzymy
    cow.dajGlos();
    dog.dajGlos();
    rooster.dajGlos();

    Zwierze * wsk_anim = &animal;  //jesli virtual i =0 to nie tworzymy
    //Zwierze * wsk_anim = &cow; 
    cout << "----------------- Wskaznik na klase -----------------" << endl;
    wsk_anim -> dajGlos();
    wsk_anim = &cow;    // wskaznik do kalsy bazowej moze wskazywac na klasy bazowe
    wsk_anim -> dajGlos();
    wsk_anim = &dog;
    wsk_anim -> dajGlos();
    wsk_anim = reinterpret_cast<Zwierze *>(&rooster);
    wsk_anim -> dajGlos();
    /*
    Bez virtual
    class Zwierze
    {
    public:
        Zwierze();
        void dajGlos();
    };
    pokaze sie:
    Nie wiem co mam powiedziec:D
    Nie wiem co mam powiedziec:D
    Nie wiem co mam powiedziec:D
    Nie wiem co mam powiedziec:D

    A z Virtual
    Nie wiem co mam powiedziec:D
    Muuuuuuuu
    How how how
    Kukuryku
    */

    cout << "------------------------------------------------------- Stale wskazniki str 419---------------------------" << endl;
    //Sam obiekt, na który pokazuje, nie musi byc rzeczywioecie staly. Wazne jest to, ze wskaznik tak go traktuje.
    //staly wskaznik to wskaznik nieruchomy. Zamrozony zostaje adres, który w nim jest zapisany. Ustawć go można tylko raz.
        //int * const wskaz = &zoo; int * const st_wsk = &a; 
        //const blizej gwiazdki (czyli to drugie) okreoela stalosc, nieruchomosc samego wskaznika.
    //Wskaznik do stalego obiektu to taki wskaznik, który pokazywany obiekt uznaje za staly. Nie moze go wiec modyfikowac.
        //const int * wskaz = &zoo;
        //const int * wsk_do _st; // WskaŸnik do obiektu sta³ego. Nie musi on byæ
                                // od razu ustawiany. Mo¿na nim nawet potem poruszaæ
    //Staly wskaznik do stalego obiektu
        //const double * const p;
    int zoo;
    int * const wskaz = &zoo;
    //int * const wskaz;
    //wskaz = &zoo;         //Nie da się, definiujemy od razu przy deklaracji, nie można deklarować a poxniej definiowac

    //do const można wpisać C-stringa
    const char *wsk;
    wsk = "taki napis";
    //zezwala na starszych wersjach c++ ale nie robi się:
    //char *wsk2 = "napis"; // <- przestarzale!Wywali ostrzeżenie lub blad
    //int *wskint = { 1,2,3,4 }; // blad!!!
    
    //Parada klamców, czyli o rzutowaniu const_cast fajna tabela str 429
    //Kompilator pozwoli tylko na takie przypisanie, które nie nada nowemu wskaznikowi wiekszych uprawnien w stosunku do pokazywanego obiektu.
    //(Wiekszych niz mial ten wskaznik dotychczasowy).
    //Kompilator nie pozwoli na takie oszustwo, by za pomoca nowego wskaznka mozna bylo modyfikowac obiekt, którego nie wolno bylo modyfi kowac
    //za pomoca wskaznika dotychczasowego. Czyli:
    const int * wsk_int = nullptr;
    //int wsk_int2 = wsk_int; nie przejdzie
    int *wsk_int2 = const_cast<int*>(wsk_int); //przejdzie bo const_cast pokazuje, że jesteśmy świafomi tego co się dzieje

    cout << "------------------------------------------------------- Tablica wskaznikow str 433---------------------------" << endl;
    double *tabwsk[5]; //mozna zapisac tez tak double *(tabwsk[5]);
    //taka tablica moze pokazywac na cstringi
    const char *stacja[6] = { "Krakow", 
                             "Berlin", 
                             "Paryz", 
                             "Oslo", 
                             "Los Angeles", 
                             "Lenakel"
                            };

    const char *w = {"abcde"};
    cout << stacja[1] << endl;
    cout << stacja << endl;
    cout << endl;
    for(string stacja : stacja)
    {
        cout << "Stacja: " << stacja << endl;
    }
    cout << endl;

    const char * www[3];
    www[0] = stacja[2];
    www[1] = stacja[5];
    www[2] = "Taki tekst";
    
    char ostrzezenie[80] = { "Alarm trzeciego stopnia " };
    cout << "\nWersja tablicowa \n";
    przedzielacz_tabl(ostrzezenie); 
    cout << "\nWersja wskaznikowa \n";
    przedzielacz_wsk(ostrzezenie);
    cout << endl;
    //--------------------------------------------------------------------------------
    char poziom[ ] = { "Poziom szumu w normie" };
    char komunikat[80];
    strcpy(komunikat, poziom);
    cout << poziom << endl;
    cout << komunikat << endl;
    //--------------------------------------------------------------------------------
    char co[ ] = { "urzadzen sterowych" };
    char komunikatt[80] = { "Alarm: " };
    strcat(komunikatt, co);
    cout << "po dopisaniu = " << komunikatt << endl;
    cout << (strcat(komunikatt, ", o godz 17:12") );
    strcat(komunikat, "abc"); //dozwolone C-stringi ujete w cudzyslowy traktowane sa tak, jakby byly: static const char[n]
    //strcat("Uwaga:", "abc"); // straszny blad! str 441

    //char *wsk5556 = "Uwaga: "; //nie da sie
    const char *wsk5557 = "Uwaga: ";
    //--------------------------------------------------------------------------------


    //--------------------------------------------------------------------------------
    cout << endl;
    cout << "-------------------------------------------------------Koniec---------------------------" << endl;
    printf("Czas wykonania programu: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);//ex2
    getchar();
    return 0;
}
//*****************************************************************************************************************
auto funkcjaTestowa2(int k, double r) -> decltype(k)
{
    //int i = 2;
    return k;
}
//*****************************************************************************************************************
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
//*****************************************************************************************************************
void temperatura(float temperatura, int skala)
{
    cout << "Temperatura komory wynosi: ";
    switch(skala)
    {
        case 0:
            cout << temperatura << " C" << endl;
        break;
        case 1:
            cout << temperatura + 273 << " K" << endl;
        break;
    }
}
//*****************************************************************************************************************
void funkcja(int a, int b)
{
    cout << "Wypisuje a = " << a << " i b = " << b << endl;
}
//*****************************************************************************************************************
void czerwona()
{
    static int zmienna = 100; //inicjalizowana tylko przy pierwszym wywołaniu, zmienna tatyczna ale lokalna przechowywana w normalnej pamięci a nie na stosie tak jak wiekszość lokalnych
    zmienna ++;
    cout << "Zmienna czerwona: "<< zmienna << endl;
}
//*****************************************************************************************************************
void czerwona2()
{
    static int zmienna = 100; //inicjalizowana tylko przy pierwszym wywołaniu, zmienna tatyczna ale lokalna przechowywana w normalnej pamięci a nie na stosie tak jak wiekszość lokalnych
    zmienna +=100;
    cout << "Zmienna czerwona2: "<< zmienna << endl;
}
//*****************************************************************************************************************
void potrojenie (int ile, int t[ ])
{
    for(int i = 0 ; i < ile ; ++i)
    {
        t[i] *= 3;
    }
}
//*****************************************************************************************************************
void strcpy(char cel[], char zrodlo[])
    {
        int i = 0;
        while((cel[i] = zrodlo[i])){ //podwojny nawias żeby kompilator był peny że to jest przypisanie a nie porównanie == Grebosz str 304
            i++;
        }
    }
//*****************************************************************************************************************
void hydraulik(int * wskaznikDoKranu)
{
    *wskaznikDoKranu += 100;
}
//*****************************************************************************************************************
void hydraulikTab(int wskaznikDoKranu[])
{
    wskaznikDoKranu[0] += 10;
    wskaznikDoKranu[1] += 10;
}
//*****************************************************************************************************************
void funkcja_wska(int *wsk, int rozmiar)
{
    cout << "\nWewnatrz funkcji funkcja_wska \n";
    for (int i = 0 ; i < rozmiar ; ++i)
        cout << *(wsk++) << "\t";
}
//*****************************************************************************************************************
void funkcja_wsk2(int *wsk, int rozmiar)
{
    cout << "\nWewnatrz funkcji funkcja_wsk2 \n";
    for (int i = 0 ; i < rozmiar ; ++i)
        cout << wsk[i] << "\t";
}
//*****************************************************************************************************************
void funkcja_tabl(int tab[ ], int rozmiar) //(tab)
{
    cout << "\nWewnatrz funkcji funkcja_tabl \n";
    for (int i = 0 ; i < rozmiar ; ++i)
        cout << tab[i] << "\t";
}
//*****************************************************************************************************************
void fun_wsk(int * wsk, int rozmiar) // przekazuje wskaznik albo przez adres zmiennej (wsk);(&zmienna);
{
    cout << "Tablica przekazywana przez wskaznik: " << endl;
    for(int j = 0; j < rozmiar; j++)
        cout << *(wsk++) << endl;
}
//*****************************************************************************************************************
void fun_tab(int tab[], int rozmiar)
{
    cout << "Tablica przekazywana przez adres: " << endl;
    for(int j = 0; j < rozmiar; j++)
        cout << tab[j] << endl;
}
//*****************************************************************************************************************
void fun_wsk_const(const int * wsk, int rozmiar)
{
    cout << "Tablica przekazywana przez wskaznik const: " << endl;
    for(int j = 0; j < rozmiar; j++)
        cout << *(wsk++) << endl;
}
//*****************************************************************************************************************
void fun_tab_const(const int tab[], int rozmiar)
{
    cout << "Tablica przekazywana przez adres const: " << endl;
    for(int j = 0; j < rozmiar; j++)
        cout << tab[j] << endl;
}
//*****************************************************************************************************************
void Zwierze::dajGlos()
{
    cout << "Nie wiem co mam powiedziec:D" << endl;
}
Zwierze::Zwierze()
{
    cout << "Konstruktor superklasy" << endl;
}

void Mucka::dajGlos()
{
    cout << "Muuuuuuuu" << endl;
}
Mucka::Mucka()
{
    cout << "Konstruktor Mucka" << endl;
}
Pies::Pies()
{
    cout << "Konstruktor Pies" << endl;
}
void Pies::dajGlos()
{
    cout << "How how how" << endl;
}

Kogut::Kogut()
{
    cout << "Konstruktor Kogut" << endl;
}
void Kogut::dajGlos()
{
    cout << "Kukuryku" << endl;
}
//*****************************************************************************************************************
void przedzielacz_tabl(const char tab[ ])
{
int n = 0;
while(tab[n]) {
cout << tab[n++] << "-";
}
}
//*****************************************************************************************************************
void przedzielacz_wsk(const char *w)
{
while(*w) {
cout << *(w++) << "-";
}
}
//*****************************************************************************************************************
char * strcpy(char *cel, const char *zrodlo)
{
    char *poczatek = cel;
    while(*(cel++) = *(zrodlo++)); 
    return poczatek;
}
//*****************************************************************************************************************
char * strcat(char *cel, const char *zrodlo)
{
    char *poczatek = cel;
    while(*(cel++) ); // przesuniêcie wskaŸnika na koniec C-stringu 
    cel--; // teraz pokazuje o 1 znak za null, zatem cofamy na znak null
    while( (*(cel++) = *(zrodlo++)) ); // kopiowanie, to ju¿ bralioemy przy strcpy 
    return poczatek;
}