// Autor: Jacek Papis 2017

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void NarysujPlansze(int tab[][10], int N);
void ZmienPozycje(int *tab, int kLiczbowaPier, int wLiczbowyPier, int kLiczbowaDoc, int wLiczbowyDoc);
void Bij();
bool CzyMozliweBicie(int *dowPionekPier, int *dowPionekDoc, int kolumna);
bool CzyMozliwyRuch(int *dowPionekPier, int *dowPionekDoc, int kolumna);
int PodajIlePionkowGracza(int *tab);
int PodajIlePionkowAI(int *tab);
