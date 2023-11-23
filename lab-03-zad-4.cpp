/*
 Autor: Dominik Kaczmarek
 Grupa: Pn/P 13:15
 Temat: Laboratorium 3 - zadanie 4
 Data: 20.11.2023 r.
 */

#include <stdio.h>
#include <conio.h>

int main() {
    printf("Autor: Dominik Kaczmarek Pn/P\n");
    int tablica_alfabet[26] = {0}, licznik_znakow = 0;
    printf("\nWpisuj litery: ");
    int znak; // zmienna przechowujaca kod ascii znaku
    while (true) {
        znak = getch();
        printf("%c", znak);
        licznik_znakow++;
        if (znak >= 65 && znak <= 90) { // sprawdzenie czy znak jest duza litera
            tablica_alfabet[znak - 65]++;
        }
        else if (znak >= 97 && znak <= 122) { // sprawdzenie czy znak jest mala litera
            tablica_alfabet[znak - 97]++;
        }
        if (znak == 27) { // sprawdzenie czy wcisnieto ESC
            break;
        }
    }
    printf("\nWpisano ogolem %d znakow, w tym:", licznik_znakow);
    for (int i = 0; i < 26; i++) {
        printf("\nlitera %c %d ", i + 65, tablica_alfabet[i]);
        for (int j = 0; j < tablica_alfabet[i]; j++) {
            printf("#");
        }
    }
    fflush(stdin);
    printf("\nKliknij Enter aby kontynuowac...");
    getchar();
    return 0;
}
