#include <iostream>
using namespace std;

void Bubble_Sort(int tab[], int n)
{
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++) 
		if(tab[j-1]>tab[j])
			swap(tab[j-1], tab[j]);
}


void sort_przez_wstawianie(int tab[], int n)
{
     int pom, j;
     for(int i=1; i<n; i++)
     {
             pom = tab[i]; 
             j = i-1;
             while(j>=0 && tab[j]>pom) 
             {
                        tab[j+1] = tab[j]; 
                        --j;
             }
             tab[j+1] = pom; 
     }     
}

void quickSort(int tab[], int lewy, int prawy)
{
	if(prawy <= lewy) return;
	int i = lewy - 1, j = prawy + 1, 
	pivot = tab[(lewy+prawy)/2]; 
	while(true)
	{
		while(pivot>tab[++i]);
		while(pivot<tab[--j]);
		if( i <= j)
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > lewy)
        quickSort(tab, lewy, j);
	if(i < prawy)
        quickSort(tab, i, prawy);
}

void Merge(int tab[], int lewy, int srodek, int prawy)
{
	int i = lewy, j = srodek + 1;
    int *pom;
 
  for(int i = lewy;i<=prawy; i++) 
    pom[i] = tab[i];  
  

  for(int k=lewy;k<=prawy;k++) 
  if(i<=srodek)
    if(j <= prawy)
         if(pom[j]<pom[i])
             tab[k] = pom[j++];
         else
             tab[k] = pom[i++];
    else
        tab[k] = pom[i++];
  else
      tab[k] = pom[j++];
}

void MergeSort(int tab[],int lewy, int prawy)
{
	if(prawy<=lewy) return; 
	int srodek = (prawy+lewy)/2;
    MergeSort(tab, lewy, srodek);
    MergeSort(tab, srodek+1, prawy);
    Merge(tab, lewy, srodek, prawy);
}

void CoctailSort(int tab[], int n)
{
  int lewy = 0, prawy = n - 1;
  bool zamiana = true;
  while (zamiana) {
    zamiana = false;
    for (int i = lewy; i < prawy; i++) {
      if (tab[i] > tab[i + 1]) {
        swap(tab[i], tab[i + 1]);
        zamiana = true;
      }
    }
    prawy = prawy - 1;
    for (int i = prawy; i > lewy; i--) {
      if (tab[i] < tab[i - 1]) {
        swap(tab[i], tab[i - 1]);
        zamiana = true;
      }
    }
    lewy = lewy + 1;
  }
}

