/*
Autor: Dominik Kaczmarek
Grupa: Pn/P 13:15
Temat: Laboratorium 3, zadania: 1, 2, 3
Data: 20.11.2023 r.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROZMIAR 5

// Zadanie 1
void wczytaj(float tab[]) {
    printf("Wprowadz kolejne elementy tablicy:\n");
    for (int i = 0; i < ROZMIAR; i++) {
        printf("Tab[%d] = ", i);
        scanf("%f", &tab[i]);
    }
    fflush(stdin);
    printf("Kliknij Enter aby kontynuowac...");
    getchar();
    system("cls");
}

void wypisz(float tab[]) {
    printf("Wprowadzone elementy tablicy:\n");
    printf("Tab = [");
    for (int i = 0; i < ROZMIAR; i++) {
        printf(" %.1f ", tab[i]);
    }
    printf("]\n");
    fflush(stdin);
    printf("Kliknij Enter aby kontynuowac...");
    getchar();
    system("cls");
}

void liczbaSumaSrednia(float tab[]) {
    int dodatnie = 0, ujemne = 0; // zmienne zliczajace liczbe dodatnich i ujemnych liczb
    float sumaDodatnich = 0, sumaUjemnych = 0; // zmienne przechowujace sume dodatnich i ujemnych liczb
    float sredniaDodatnich = 0, sredniaUjemnych = 0; // zmienne przechowujace srednia dodatnich i ujemnych liczb
    for (int i = 0; i < ROZMIAR; i++) {
        if (tab[i] > 0) {
            dodatnie++;
            sumaDodatnich += tab[i];
        }
        else if (tab[i] < 0) {
            ujemne++;
            sumaUjemnych += tab[i];
        }
    }
    printf("W tablicy jest %d liczb dodatnich i %d liczb ujemnych\n", dodatnie, ujemne);
    printf("Suma liczb dodatnich wynosi %f, a suma liczb ujemnych wynosi %f\n", sumaDodatnich, sumaUjemnych);
    if (dodatnie > 0) {
        sredniaDodatnich = sumaDodatnich / (float)dodatnie;
        printf("Srednia liczb dodatnich wynosi %f\n", sredniaDodatnich);
    }
    if (ujemne > 0) {
        sredniaUjemnych = sumaUjemnych / (float )ujemne;
        printf("Srednia liczb ujemnych wynosi %f\n", sredniaUjemnych);
    }
    fflush(stdin);
    printf("Kliknij Enter aby kontynuowac...");
    getchar();
    system("cls");
}

void uporzadkowanie(float tab[]) {
    // zmienne logiczne przechowujace informacje o uporzadkowaniu
    bool rosnaco = true, malejaco = true, stale = true, niemalejaco = true, nierosnaco = true;
    for (int i = 0; i < ROZMIAR-1; i++) {
        if (tab[i] > tab[i+1]) {
            rosnaco = false;
            niemalejaco = false;
        }
        if (tab[i] < tab[i+1]) {
            malejaco = false;
            nierosnaco = false;
        }
        if (tab[i] != tab[i+1]) {
            stale = false;
        }
        if (tab[i] == tab[i+1]) {
            rosnaco = false;
            malejaco = false;
        }
    }
    if (stale) printf("\nWszystkie elementy tablicy maja jednakowa wartosc");
    else if (rosnaco || niemalejaco || malejaco || nierosnaco) {
        printf("\nElementy w podanej tablicy uporzadkowane sa: ");
        if (rosnaco) printf("\n- rosnaco");
        if (niemalejaco) printf("\n- niemalejaco");
        if (malejaco) printf("\n- malejaco");
        if (nierosnaco) printf("\n- nierosnaco");
    }
    else printf("\nElementy podanej tablicy sa nieuporzadkowane");
    fflush(stdin);
    printf("\nKliknij Enter aby kontynuowac...");
    getchar();
    system("cls");
}

// Zadanie 2
void wypelnienieLiczbamiLosowymi(float tab[]) {
    printf("Tablica zostanie wypelniona liczbami losowymi z zadanego przedzialu\n");
    float zakres_min, zakres_max; // zmienne przechowujace zakres liczb losowych
    printf("Podaj minimalna wartosc liczby do wylosowania: ");
    scanf("%f", &zakres_min);
    printf("Podaj maksymalna wartosc liczby do wylosowania: ");
    scanf("%f", &zakres_max);
    for (int i = 0; i < ROZMIAR; i++) {
        tab[i] = zakres_min + (float)rand() / RAND_MAX * (zakres_max - zakres_min);
    }
}

// Zadanie 3
void sortowaniePrzezWstawianie(float tab[]) {
    float pomocnicza; // zmienna pomocnicza do przechowywania aktualnie sortowanej liczby
    for (int i = 0; i < ROZMIAR; i++) {
        pomocnicza = tab[i];
        for (int j = i - 1; j >= 0 && tab[j] > pomocnicza; j--) {
            // printf("tab[%d] = %f\n", i, tab[i]);
            // printf("tab[%d] = %f\n", j, tab[j]);
            tab[j + 1] = tab[j];
            tab[j] = pomocnicza;
        }
    }
    printf("Tablica zostala posortowana\n");
    fflush(stdin);
    printf("Kliknij Enter aby kontynuowac...");
    getchar();
    system("cls");
}

int main() {
    printf("Autor: Dominik Kaczmarek Pn/P\n");
    float Tablica[ROZMIAR]; // deklaracja tablicy liczb rzeczywistych o zdefiniowanym rozmiarze
    int wybranaOpcja; // zmienna przechowujaca funkcje wybrana do uruchomienia
    srand(time(NULL));
    do {
        printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("||                  Wybierz funkcje do uruchomienia                      ||\n");
        printf("|| *1* Wczytanie elementow tablicy                                       ||\n");
        printf("|| *2* Wypisanie elementow tablicy                                       ||\n");
        printf("|| *3* Wyliczenie ilosci, sumy i sredniej liczb dodatnich i ujemnych     ||\n");
        printf("|| *4* Sprawdzanie uporzadkowania tablicy                                ||\n");
        printf("|| *5* Wypelnienie tablicy liczbami losowymi z zadanego przedzialu       ||\n");
        printf("|| *6* Sortowanie tablicy                                                ||\n");
        printf("|| *7* Zakoncz dzialanie programu                                        ||\n");
        printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("Wprowadz numer wybranej opcji: ");
        scanf("%i", &wybranaOpcja);
        system("cls");
        switch (wybranaOpcja) {
            case 1:
                wczytaj(Tablica);
                break;
            case 2:
                wypisz(Tablica);
                break;
            case 3:
                liczbaSumaSrednia(Tablica);
                break;
            case 4:
                uporzadkowanie(Tablica);
                break;
            case 5:
                wypelnienieLiczbamiLosowymi(Tablica);
                wypisz(Tablica);
                break;
            case 6:
                sortowaniePrzezWstawianie(Tablica);
                break;
            case 7:
                break;
            default:
                printf("Wprowadzono nieprawidlowa cyfre.");
                break;
        }
    }
    while (wybranaOpcja != 7);
    return 0;
}
