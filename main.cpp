

//          Konrad Król 243176    Projekt - Totolotek



#include <iostream>
//#include <conio.h>
//#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <fstream>

using namespace std;

void MENU()
{
    cout << "\n Wybierz jedna z poni¿szych opcji : " << endl;
    cout << " (1) Wprowadz swoje liczby i podaj ilosc losowan \n (2) Uruchom losowanie liczb " << endl;
    cout << " (3) Kwoty do wygrania " << endl;
    cout << " (4) Zapisz swoje liczby i losowanie w pliku LOTTO \n (5) Wczytaj swoje poprzednie liczby i poprzednie losowanie z pliku LOTTO " << endl;
    cout << " (0) KONIEC " << endl;
}

class totolotek
{
public:

    int N = 6;
    int t[6];
    int m[6];
    int i = 0;
    int j, k, z, y, b, c;
    int ilosc, wygrana;
    int x = 0;
    int a = 0;
    int trafione = 0;
    int traf[100];
    int wyg[100];
    int bb[1];
    int ii[100];
    string wiersz;

    void twojeliczby()
    {
        cout << " Podaj swoje 6 liczb z zakresu od 1 do 20 : " << endl;
        for(i = 0; i < 6 ; i++)
        {
            cin >> m[i];
            if(m[i] > 20 || m[i] < 1)
            {
                cout << " Podales bledna wartosc ! Sprobuj ponownie : ";
                i--;
            }
        }
        cout << " Podaj liczbe losowan : " << endl;
        cin >> ilosc;
    }

    void losowanie()
    {
    a = 0;
    x = 0;
    b = 0;
    i = 0;
    for(j = 1; j <= ilosc; j++)
    {
        srand(time(NULL));
        Sleep(1000);
        trafione = 0;
        a = 0;
        cout << "\n Losowanie : " << j << endl;
        cout << " Wylosowane liczby to : " ;
        for(i = 0; i < N; i++)
        {
            t[i] = rand() % (20)+1;
            if(i == 0)
            {
                ii[i+x] = t[i];
                Sleep(1000);
                cout << " " << setw(2) << t[i];
            }
            else
            {
                y = i;
                for(k = 0; k<i; k++)
                {
                if(t[k]==t[i])
                {
                    i--;
                }
                }
                if(i==y)
                {
                    ii[i+x] = t[i];
                    Sleep(1000);
                    cout << " " << setw(2) << t[i];
                }
            }
        }
        for(c = 0; c<N; c++)
        {
            for(z = 0; z<N; z++)
            {
            if(t[c]==m[z])
            {
                trafione++;
            }
            }
        }
        if(trafione==0 || trafione==1 || trafione==2)
        {
            a = 0;
        }
        if(trafione==3)
        {
            a = 30;
        }
        if(trafione==4)
        {
            a = 400;
        }
        if(trafione==5)
        {
            a = 5000;
        }
        if(trafione==6)
        {
            a = 60000;
        }
        traf[j] = trafione;
        wyg[j] = a;
        b = b+a;
        x = x+6;

    cout << "\n W losowaniu : " << j << " trafiles : " << traf[j] << " liczb! Wygrales : " << wyg[j] << " zlotych! " << endl;
    }
    bb[0] = b;
    cout << "\n Lacznie wygrales : " << b << " zlotych ! " << endl;
    }

    void kwotydowygrania()
    {
        cout << " Kwoty do wygrania : \n (1) Za trafienie 0, 1, 2 liczb otrzymasz 0 zlotych ; " << endl;
        cout << " (2) Za trafienie 3 liczb otrzymasz 30 zlotych ; \n (3) Za trafienie 4 liczb otrzymasz 400 zlotych ; " << endl;
        cout << " (4) Za trafienie 5 liczb otrzymasz 5 000 zlotych ; \n (5) Za trafienie 6 liczb otrzymasz 60 000 zlotych ; " << endl;
    }

      void zapisz()
    {
        ofstream zapisz("LOTTO.txt" , ios::trunc);
              zapisz << " Twoje liczby to : ";
              for(j = 0; j<N; j++)
              {
                  zapisz << " " << m[j];
              }
              zapisz << " " << endl;
              x = 0;
              for(j = 1; j<=ilosc; j++)
              {
                zapisz << "\n Wyosowane liczby w losowaniu : " << j << " to : ";
              for(i = 0; i<N; i++)
              {
                  zapisz << " " << ii[i+x] ;
              }
              zapisz << "\n W losowaniu : " << j << " trafiles : " << traf[j] << " liczb! Wygrales : " << wyg[j] << " zlotych! " << endl;
              x = x+6;
              }
              zapisz << "\n Lacznie wygrales : " << bb[0] << " zlotych ! " << endl;
        zapisz.close();
    }

    void pobierz()
    {
        ifstream pobierz("LOTTO.txt" , ios::in);
        if(pobierz.good()==false)
        {
            cout << " Plik nie istnieje !! " << endl;
        }
        while(!pobierz.eof())
        {
            getline(pobierz , wiersz);
            cout << wiersz << endl;
        };
        pobierz.close();
    }

};

int main()
{
    int q;
    totolotek t;
    cout << " Witaj w TOTOLOTKU! " << endl;
    do
    {
    MENU();
    cin >> q;

    if(q==1)
    {
        t.twojeliczby();
    }
    if(q==2)
    {
        t.losowanie();
    }
    if(q==3)
    {
        t.kwotydowygrania();
    }
    if(q==4)
    {
        t.zapisz();
    }
    if(q==5)
    {
        t.pobierz();
    }
    }while(q!=0);

    cout << " KONIEC " << endl;

    return 0;
}
