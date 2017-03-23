// Autor: Jacek Papis 2017

#include "silnik.h"

int main() //0 - nic 1 - biale 2 - biała dama 3-czarne 4-czarna dama
{
  extern int *wskGlob;
  char kolumnaPier,kolumnaDoc;
  char wierszPier, wierszDoc;
  int plansza[10][10] = {
    {0,3,0,3,0,3,0,3,0,3},
    {3,0,3,0,3,0,3,0,3,0},
    {0,3,0,3,0,3,0,3,0,3},
    {3,0,3,0,3,0,3,0,3,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0}};

  int kLiczbowaPier = 0;
  int wLiczbowyPier = 0;
  int kLiczbowaDoc  = 0;
  int wLiczbowyDoc  = 0;

  system("clear");
  printf("\n\t\tAUTOR: JACEK PAPIS 2017\n");
  printf("--------------------------------------------------------------\n");
  printf("\t\t        WARCABY        \n");
  printf("--------------------------------------------------------------\n\n");
  printf("ZASADY:\n");
  printf("1) rozmiar planszy 10x10\n");
  printf("2) kiedy pionek dojdzie do końca planszy, zamienia się w damę\n");
  printf("3) dama może poruszać się o wiele miejsc(w górę jak i w dół), po przekątnych\n");
  printf("4) pionki poruszają się o 1 miejsce po przekątnych tylko do przodu\n");
  printf("5) zbijający pionek przeskakuje zbitego\n");
  printf("6) O-pionki gracza, X-pionki komputera, H-dama gracza, M-dama komputera\n");
  printf("7) gracz wybiera pionek(wybiera aktualną pozycję pionka) żeby poruszyć go poprzez wybór miejsca docelowego(np. A6 F0 G4)\n\n");
  printf("Wciśnij enter aby kontynuować...\n"); // Kiedy istnieje kilka możliwych bić, gracz musi wykonać maksymalne
  while( getchar() != '\n' );
  system("clear");
  NarysujPlansze(plansza,10);
  printf("Liczba pionków gracza: %d || Liczba pionków AI: %d\n\n\n\n", PodajIlePionkowGracza(*plansza),PodajIlePionkowAI(*plansza));
  while(true)
  {
    printf("Wybierz kolumnę i wiersz pionka/damy: ");
    scanf(" %c%c",&kolumnaPier,&wierszPier);
    while(kolumnaPier<65||kolumnaPier>74||wierszPier<48||wierszPier>57)
    {
      printf("BŁĄD!! - wprowadź poprawną kolumnę i wiersz pionka/damy: ");
      scanf(" %c%c",&kolumnaPier,&wierszPier);
    }

    printf("Wybierz kolumnę i wiersz miejsca do którego chcesz przestawić pionek/damę: ");
    scanf(" %c%c",&kolumnaDoc,&wierszDoc);
    while(kolumnaDoc<65||kolumnaDoc>74||wierszDoc<48||wierszDoc>57)
    {
      printf("BŁĄD!! - wprowadź poprawną kolumnę i wiersz miejsca do którego chcesz przestawić pionek/damę: ");
      scanf(" %c%c",&kolumnaDoc,&wierszDoc);
    }

    switch (kolumnaPier)
    {
      case 'A': kLiczbowaPier = 0;  break;
      case 'B': kLiczbowaPier = 1;  break;
      case 'C': kLiczbowaPier = 2;  break;
      case 'D': kLiczbowaPier = 3;  break;
      case 'E': kLiczbowaPier = 4;  break;
      case 'F': kLiczbowaPier = 5;  break;
      case 'G': kLiczbowaPier = 6;  break;
      case 'H': kLiczbowaPier = 7;  break;
      case 'I': kLiczbowaPier = 8;  break;
      case 'J': kLiczbowaPier = 9;  break;
    }

    switch (wierszPier)
    {
      case '0': wLiczbowyPier = 0;  break;
      case '1': wLiczbowyPier = 1;  break;
      case '2': wLiczbowyPier = 2;  break;
      case '3': wLiczbowyPier = 3;  break;
      case '4': wLiczbowyPier = 4;  break;
      case '5': wLiczbowyPier = 5;  break;
      case '6': wLiczbowyPier = 6;  break;
      case '7': wLiczbowyPier = 7;  break;
      case '8': wLiczbowyPier = 8;  break;
      case '9': wLiczbowyPier = 9;  break;
    }

    switch (kolumnaDoc)
    {
      case 'A': kLiczbowaDoc = 0;  break;
      case 'B': kLiczbowaDoc = 1;  break;
      case 'C': kLiczbowaDoc = 2;  break;
      case 'D': kLiczbowaDoc = 3;  break;
      case 'E': kLiczbowaDoc = 4;  break;
      case 'F': kLiczbowaDoc = 5;  break;
      case 'G': kLiczbowaDoc = 6;  break;
      case 'H': kLiczbowaDoc = 7;  break;
      case 'I': kLiczbowaDoc = 8;  break;
      case 'J': kLiczbowaDoc = 9;  break;
    }

    switch (wierszDoc)
    {
      case '0': wLiczbowyDoc = 0;  break;
      case '1': wLiczbowyDoc = 1;  break;
      case '2': wLiczbowyDoc = 2;  break;
      case '3': wLiczbowyDoc = 3;  break;
      case '4': wLiczbowyDoc = 4;  break;
      case '5': wLiczbowyDoc = 5;  break;
      case '6': wLiczbowyDoc = 6;  break;
      case '7': wLiczbowyDoc = 7;  break;
      case '8': wLiczbowyDoc = 8;  break;
      case '9': wLiczbowyDoc = 9;  break;
    }


    int *pionekPier = *plansza;
    int *pionekDoc = *plansza;

    pionekPier = pionekPier+(wLiczbowyPier*10+kLiczbowaPier);
    pionekDoc = pionekDoc+(wLiczbowyDoc*10+kLiczbowaDoc);

    if(CzyMozliwyRuch(pionekPier,pionekDoc,kLiczbowaPier)==true) // IICzyMozliweBicie==true
    {
      ZmienPozycje(*plansza,kLiczbowaPier,wLiczbowyPier,kLiczbowaDoc,wLiczbowyDoc);
      system("clear");
      NarysujPlansze(plansza,10);
      printf("Liczba pionków gracza: %d || Liczba pionków AI: %d\n\n", PodajIlePionkowGracza(*plansza),PodajIlePionkowAI(*plansza));
      printf("\nPrzesunięto pionek\n");
    }
    else
    {
      if(CzyMozliweBicie(pionekPier,pionekDoc,kLiczbowaPier)==true) // jak prawdziwy to wskazuje na pionka za pomocą wskaźnika globalnego wskGlob
      {
        ZmienPozycje(*plansza,kLiczbowaPier,wLiczbowyPier,kLiczbowaDoc,wLiczbowyDoc);
        Bij(wskGlob);
        system("clear");
        NarysujPlansze(plansza,10);
        printf("Liczba pionków gracza: %d || Liczba pionków AI: %d\n\n", PodajIlePionkowGracza(*plansza),PodajIlePionkowAI(*plansza));
        printf("\nZbito pionek\n");
      }
      else
      {
        system("clear");
        NarysujPlansze(plansza,10);
        printf("Liczba pionków gracza: %d || Liczba pionków AI: %d\n\n", PodajIlePionkowGracza(*plansza),PodajIlePionkowAI(*plansza));
        printf("\nRuch niedozwolony\n");
      }

    }

  }

}

// KOMPILACJA : gcc -Wall -std=c99 silnik.c warcaby.c -o warcaby
