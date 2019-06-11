//
// EPITECH PROJECT, 2019
// Event
// File description:
// Indie Studio
//

#include <stdlib.h>
#include <stdio.h>

int generate_map(int argc, char *argv[])
{
    FILE* file = NULL;
    file = fopen("map.txt", "w");
    int i = 0;
    int j = 0;
    int n = 0;

    fputs("AAAAAAAAAAAAAAAAAAA\n", file);
    while (j < 17) {
        fputs("A", file);
        i = 0;
        while (i < 17) {
            n = rand();
            if (i == 0 && j == 0 || i == 0 && j == 16 || i == 16 && j == 0 || i == 16 && j == 16)
                fputs("x", file);
            else if (i % 2 != 0 && j % 2 != 0)
                fputs("A", file);
            else if (n % 2 == 0)
                fputs("T", file);
            else
                fputs("x", file);
            i++;
        }
        fputs("A\n", file);
        j++;
    }
    fputs("AAAAAAAAAAAAAAAAAAA", file);
    return 0;
}
