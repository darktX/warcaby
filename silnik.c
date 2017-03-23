// Autor: Jacek Papis 2017

#include "silnik.h"

int *wskGlob;

void NarysujPlansze(int tab[][10], int N)
{
  printf("  /___/___/---------WARCABY-------/___/___/\n");
  int i, j;

  for (i=0; i<N; i++)
  {
    printf("%d ",i);
    for (j=0; j<10; j++)
    {
      switch (tab[i][j])
      {
        case 0: printf("|   "); break;
        case 1: printf("|  O"); break; // białe
        case 2: printf("|  H"); break; // biała dama
        case 3: printf("|  X"); break; // czarne
        case 4: printf("|  M"); break; // czarna dama
      }

    }
    printf("|\n");
    printf("  |___|___|___|___|___|___|___|___|___|___|\n");

  }
  printf("    A   B   C   D   E   F   G   H   I   J\n");
}

void ZmienPozycje(int *tab, int kLiczbowaPier, int wLiczbowyPier, int kLiczbowaDoc, int wLiczbowyDoc)
{
  int *wsk1 = tab;
  int *wsk2 = tab;

  wsk1 = wsk1+(wLiczbowyPier*10+kLiczbowaPier);
  wsk2 = wsk2+(wLiczbowyDoc*10+kLiczbowaDoc);
  *wsk2 = *wsk1; // już nie default białe
  *wsk1 = 0;
}

void Bij(int *pionekDoBicia)
{
  *pionekDoBicia=0;
}

bool CzyMozliweBicie(int *dowPionekPier, int *dowPionekDoc, int kolumna)
{
  if(*dowPionekPier == 0||*dowPionekDoc >=1) // puste pole lub naskakuje na stojący pionek
  {
    return false;
  }
  switch (*dowPionekPier)
  {
    case 1: // pionek biały
      if(kolumna==0)
      {
          if((*(dowPionekPier-9)>=3)&&(dowPionekPier-18)==(dowPionekDoc))
          {
            wskGlob = (dowPionekPier - 9);
            printf("HALO1\n");
            return true; // kiedy pionek po skosie prawym jest wrogi i celujemy na kolejne puste pole po skosie prawym
          }
          else
          {
            return false;
          }
      }
      else if(kolumna==9)
      {
        if(*(dowPionekPier-11)>=3&&(dowPionekPier-22)==(dowPionekDoc))
        {
          wskGlob = (dowPionekPier - 11);
          return true; // kiedy pionek po skosie lewym jest wrogi i celujemy na kolejne puste pole po skosie lewym
        }
        else
        {
          return false;
        }
      }
      else
      {
        if(((*(dowPionekPier-9)>=3)&&(dowPionekPier-18)==(dowPionekDoc))||((*(dowPionekPier-11)>=3)&&(dowPionekPier-22)==(dowPionekDoc)))
        {
          if((*(dowPionekPier-9)>=3)&&(dowPionekPier-18)==(dowPionekDoc))
          {
            wskGlob = (dowPionekPier - 9);

          }
          else if ((*(dowPionekPier-11)>=3)&&(dowPionekPier-22)==(dowPionekDoc))
          {
            wskGlob = (dowPionekPier - 11);
          }

          return true; // musi się poruszyć o pozycję wskaźnikową -11 albo -9
        }
        else
        {
          return false;
        }
      }
    break;
    case 2: break; // biała dama
    case 3: // pionek czarny
      if(kolumna==0)
      {
        if((*(dowPionekPier+11)<=2)&&(dowPionekPier+22)==(dowPionekDoc))
        {
          wskGlob = (dowPionekPier + 11);
          printf("HALO1\n");
          return true; // kiedy jest w pierwszej kolumnie i jest wolne miejsce do poruszenia po skosie prawym
        }
        else
        {
          return false;
          printf("FAIL1\n");
        }
      }
      else if(kolumna==9)
      {
        if(*(dowPionekPier+9)<=2&&(dowPionekPier+18)==(dowPionekDoc))
        {
          wskGlob = (dowPionekPier + 9);
          printf("HALO2\n");
          return true; // kiedy jest w ostatniej kolumnie i jest wolne miejsce do poruszenia po skosie lewym
        }
        else
        {
          return false;
          printf("FAIL2\n");
        }
      }
      else
      {
        if(((*(dowPionekPier+11)<=2)&&(dowPionekPier+22)==(dowPionekDoc))||((*(dowPionekPier+9)<=2)&&(dowPionekPier+18)==(dowPionekDoc)))
        {
           // musi się poruszyć o pozycję wskaźnikową +11 albo +9
          if((*(dowPionekPier+11)<=2)&&(dowPionekPier+22)==(dowPionekDoc))
          {
            printf("HALO3\n");
            wskGlob = (dowPionekPier + 11);
            return true;

          }
          else if ((*(dowPionekPier+9)<=2)&&(dowPionekPier+18)==(dowPionekDoc))
          {
            printf("HALO4\n");
            wskGlob = (dowPionekPier + 9);
            return true;
          }
        }
        else
        {
          printf("FAIL3\n");
          return false;
        }
    } break;

  case 4: break; // czarna dama
  }
  return false;

}

bool CzyMozliwyRuch(int *dowPionekPier, int *dowPionekDoc, int kolumna) // + strona po której jesteśmy
{
  if(*dowPionekPier == 0||*dowPionekDoc >=1) // puste pole lub naskakuje na stojący pionek
  {
    return false;
  }
  switch (*dowPionekPier)
  {
    case 1: // pionek biały
      if(kolumna==0)
      {
          if((*(dowPionekPier-9)==0)&&(dowPionekPier-9)==(dowPionekDoc))
          {
            return true; // kiedy jest w pierwszej kolumnie i jest wolne miejsce do poruszenia po skosie prawym
          }
          else
          {
            return false;
          }
      }
      else if(kolumna==9)
      {
        if(*(dowPionekPier-11)==0&&(dowPionekPier-11)==(dowPionekDoc))
        {
          return true; // kiedy jest w ostatniej kolumnie i jest wolne miejsce do poruszenia po skosie lewym
        }
        else
        {
          return false;
        }
      }
      else
      {
        if(((*(dowPionekPier-11)==0)&&(dowPionekPier-11)==(dowPionekDoc))||((*(dowPionekPier-9)==0)&&(dowPionekPier-9)==(dowPionekDoc)))
        {
          return true; // musi się poruszyć o pozycję wskaźnikową -11 albo -9
        }
        else
        {
          return false;
        }
      }
    break;
    case 2: break; // biała dama
    case 3: // pionek czarny
      if(kolumna==0)
      {
        if((*(dowPionekPier+11)==0)&&(dowPionekPier+11)==(dowPionekDoc))
        {
          return true; // kiedy jest w pierwszej kolumnie i jest wolne miejsce do poruszenia po skosie prawym
        }
        else
        {
          return false;
        }
      }
      else if(kolumna==9)
      {
        if(*(dowPionekPier+9)==0&&(dowPionekPier+9)==(dowPionekDoc))
        {
          return true; // kiedy jest w ostatniej kolumnie i jest wolne miejsce do poruszenia po skosie lewym
        }
        else
        {
          return false;
        }
      }
      else
      {
        if(((*(dowPionekPier+9)==0)&&(dowPionekPier+9)==(dowPionekDoc))||((*(dowPionekPier+11)==0)&&(dowPionekPier+11)==(dowPionekDoc)))
        {
          return true; // musi się poruszyć o pozycję wskaźnikową +11 albo +9
        }
        else
        {
          return false;
        }
    } break;

  case 4: break; // czarna dama
  }
  return false;
}

int PodajIlePionkowGracza(int *tab)
{
  int licznik = 0;
  for(int i=0;i<100;i++)
  {
    if(*tab<=2&&*tab!=0)
    {
      licznik++;
    }
    tab = tab + 1 ;
  }
  return licznik;
}

int PodajIlePionkowAI(int *tab)
{
  int licznik = 0;
  for(int i=0;i<100;i++)
  {
    if(*tab>=3)
    {
      licznik++;
    }
    tab = tab + 1 ;
  }
  return licznik;
}
