#include <iostream>
#include <string>

// pole, ve kterem jsou ulozeny hodnoty matice A, matice B a taky vysledne matice C
int maticeA[10][10];
int maticeB[10][10];
int maticeC[10][10];

// pomocne promenne pro matice
int a, b, c, d;

// dalsi pomocne promenne pro vypocet
int cislo = 0;
int vypocet = 0;

// ukazatel pro soubor s vysledky matice
FILE* soubor;

// deklarace funkce
int matVypocet(int cislo, int vypocet);

int main()
{
    while (cislo = 1) {
        // zadani typu operace, kterou chceme s matici provadet
        printf_s("Zadej operaci: \n 1 - scitani \n 2 - odecitani \n 3 - nasobeni \n 4 - matice transponovana\n\n");
        scanf_s("%d", &vypocet);

        // osetreni vystupu pro zadani operace
        if ((vypocet != 1) && (vypocet != 2) && (vypocet != 3) && (vypocet != 4)) {
            printf_s("Neplatny vstup operace!\n");
            break;
        }

        // zadani hodnot matice a jejich nacteni
        printf_s("\nZadej pocet radku a pocet sloupcu matice: \n");
        scanf_s("%d%d", &a, &b);

        // prirazeni promennych c, d a tim padem jejich naplneni hodnotami
        c = a;
        d = b;

        // cyklus, ktery naplni prvni matici 
        for (int i = 0; i < a; i++) {
            printf_s("\nZadej hodnoty pro %d. radek prvni matice: \n", i + 1); // i+1 slouzi k posunutiu na dalsi radek

            for (int j = 0; j < b; j++) {
                scanf_s("%d", &maticeA[j][i]);
            }
        }

        // podminka ktera akticuje cyklus na naplneni druhe matice - pouze scitani, odecitani a nasobeni
        if ((vypocet == 1) || (vypocet == 2) || (vypocet == 3)) {

            // cyklus, ktery naplni druhou matici
            for (int i = 0; i < c; i++) {
                printf("\nZadej hodnoty pro %d. radek druhe matice: \n", i + 1);

                for (int j = 0; j < d; j++) {
                    scanf_s("%d", &maticeB[j][i]);
                }
            }
        }

        // zavolani hlavni funkce pro vypocet matice
        matVypocet(cislo, vypocet);

        printf_s("Chcete vypocitat dalsi priklad? 1 - Ano 2 - Ne\n");
        scanf_s("%d", &cislo);

        // podminka pro opakovani programu
        if (cislo == 1) {
            printf_s("\n\n");
        }
        else {
            printf_s("\nKonec programu!\n");
            break;
        }
    }

    return 0;
}



//  funkce na vypocet a jeji vypsani matice
int matVypocet(int cislo, int vypocet) {

    // scitani a odecitani matic
    if (vypocet == 1 || vypocet == 2) {

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                if (vypocet == 1) {
                    maticeC[j][i] = maticeB[j][i] + maticeA[j][i]; // scitani jednotlivych prvku v matici
                }
                else {
                    maticeC[j][i] = maticeB[j][i] - maticeA[j][i]; // odecitani jednotlivych prvku v matici
                }
            }
        }
    }

    // nasobeni matic
    else if (vypocet == 3) {

        for (int i = 0; i < a; i++) { // posun na novy radek
            for (int j = 0; j < b; j++) { // posun na novy prvek v radku
                for (int k = 0; k < a; k++) { // konkretni pocitani hodnoty
                    maticeC[j][i] += maticeA[k][i] * maticeB[j][k];
                }
            }
        }
    }

    // matice transponovana
    else if (vypocet == 4) {

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                maticeC[j][i] = maticeA[i][j];
            }
        }
    }

    // otevreni souboru vysledky a vypis "vysledna matice"
    fopen_s(&soubor, "Vysledky.txt", "w+");
    fprintf_s(soubor, "Vysledna matice: \n\n");

    // vypsani do programu
    printf_s("\nVysledna matice:\n");

    // cyklus, ktery slouzi k vypsani hodnot vysledne matice do programu a do souboru s vysledky
    for (int i = 0; i < a; i++) {
        printf_s("[");

        for (int j = 0; j < b; j++) {
            printf_s("%d ", maticeC[j][i]);

            // vypis jednotlivych hodnot matice do souboru vysledky
            fprintf_s(soubor, "[%d ]", maticeC[j][i]);

        }
        printf_s("]\n");

        fprintf_s(soubor, "\n");
    }

    // zavreni souboru vysledky
    fclose(soubor);

    return 0;
}
