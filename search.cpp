#include <iostream>
#include <cmath>
using namespace std;

int LinearSort(const int tab[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (tab[i] == key) {
            return i;
        }
    }
    return -1;
}

int wyszukiwanie_liniowe_z_wart(int tab[], int size, int key) {
    int last = tab[size - 1];
    tab[size - 1] = key;
    int i = 0;
    while (tab[i] != key) {
        ++i;
    }

    tab[size - 1] = last;
    if (i < size - 1 || key == last) {
        return i;
    } else {
        return -1;
    }
}

int wyszukiwanie_binarne(int tab[], int size, int key) {
    int lewy = 0;
    int prawy = size - 1;

    while (left <= prawy) {
        int srodek = lewy + (prawy - lewy) / 2;

        if (tab[srodek] == key) {
            return srodek;
        } else if (tab[srodek] < key) {
            lewy = srodek + 1;
        } else {
            prawy = srodek - 1;
        }
    }

    return -1;
}