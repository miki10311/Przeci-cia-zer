#include <stdio.h>
                                                  /* deklaracja stałych symbolicznych wynikających z treści zadania */
#define KONIEC 99                                 /* stała oznaczająca warunek stopu */
#define MAX_POPR 10                               /* stała oznaczająca maksymalną poprawną wartość pojedyńczej danej z pliku */
#define MIN_POPR -10                              /* stała oznaczająca minimalną poprawną wartość pojedyńczej danej z pliku */
#define MAX_CZ 14                                 /* stała oznaczająca maksymalną ilość przecięć zera, aby można było uznać wyniki za poprawne */
#define MIN_CZ 8                                  /* stała oznaczająca minimalną ilość przecięć zera, aby można było uznać wyniki za poprawne */
#define GRUPA 99                                  /* stała oznaczająca warunek końca grupy */


int main()
{
float poj_dana;                                    /* zmienna zmiennoprzecinkowa, która jest zmienną pomocniczą do spawdzania kolejnych danych z pliku, przechowuje ostatnio pobraną daną */
float dana_poprz=0;                                /* zmienna zmiennoprzecinkowa, która jest zmienną pomocniczą do spawdzania kolejnych danych z pliku, przechowuje poprzednio pobraną daną */
int przec=0;                                       /* zmienna zliczająca ilość przecięć */
int ilosc_przesc=0;                                /* zmienna zliczająca ilośc przejść */
                                                   /* na początku zmiennym przypisuję zero ze względu na pamięć śmieciową */

while(KONIEC!=poj_dana)                            /* pętla while, której warunkiem stopu jest znalezienie pojedyńczej danej równej stałej KONIEC */
{
    scanf("%f",&poj_dana);                         /* pobieranie danych i przypisywanie ich do zmiennej poj_dana */
    
    if(poj_dana<=MAX_POPR && poj_dana>=MIN_POPR)   /* instrukcja warunkowa, która ma za zadanie sprawdzić, czy pobrana dana jest zawarta w przedziale z treści zadania (od -10 do 10) */
    {
        if(poj_dana!=0)                            /* sprawdzenie czy dana jest różna od zera (jeżeli tak jest to zostaje pominięta w tej pętli, bo 0 i tak nie daje przecięcia) */
        {
         if(poj_dana*dana_poprz<0)                 /* jeżeli dana jest różna od zera to wykonujemy kolejnego mnożenie danej przez daną poprzednią */
         {                                         /* dla pierwszej danej dana_poprz=0 stąd zostanie to pominięte, aby uniknąć dodatkowego jednego przejcięcia */
            przec++;                               /* kiedy następuje zmiana znaku zmiennej pomocniczej to do zmiennej przec zostaje dodane 1 */
         } 
         dana_poprz=poj_dana;                      /* to przypisanie pozwala na bierząco sprawdzać kolejne dwie pary cyfr, bo poj_dana jest wprowadzana,*/ 
        }                                                   /* a dana_poprz jest zawsze zmienną wprowadzoną o jeden krok wcześniej */
    }
    ilosc_przesc++;                                /* po każdym przejściu zmienna ilosc_przejsc zostaje zwiększona o 1, tak aby móc skończyć grupę danych przy 99 przejściach */
    if (ilosc_przesc==GRUPA)                       /* po 99 danych wyniki pacjenta zostaną sprawdzone */
    {
        if(przec>=MIN_CZ && przec<=MAX_CZ)         /* sprawdzenie czy ilość przecięć zera jest w poprawnym przedziale */
        {
            printf("Puls %d - poprawny \n",przec);
        }
        else
        {
            printf("Puls %d - niepoprawny! \n",przec);
        }
        ilosc_przesc=0;                            /* zmienne tutaj są przygotowywane na rozpoczęcie pętli od nowa również po to, aby uniknąć błędów wynikających z danych śmieciowych */
        dana_poprz=0;                                       /* wynikających z wcześniejszego użytkowania danego fragmentu pamięci*/ 
        przec=0;
    }

}

return 0;
}



/*
w konsoli po uruchomieniu programu należy napisać: cut -d ' ' -f 2- przeciecia_zera1 | ./a.out
                                                                    przeciecia_zera2
-d separator, czyli u nas po spacji (' ')
-f ciągi znaków od drugiego do końca każdej linii (2-)
przeciecia_zera1/przeciecia_zera2 - nazwy plików z których bierzemy dane

jest to polecenie dla danych dołączonych do opisu ćwiczenia
*/
