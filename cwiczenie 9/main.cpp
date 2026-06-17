#include <stdio.h>
#include <stdlib.h>
FILE * fptr;
int main()
{
    fptr = fopen("plik.txt", "a");
    if (fptr == 0)
    {
        printf("Blad otwierania pliku!\n");
        exit(1);
    }
    fprintf(fptr, "\nNapis dodawany na koncu pliku.\n");
    fclose(fptr);
    return(0);
}


// FILE * fptr;
// int main()
// {
//     char fileLine[100];
//     fptr = fopen("plik.txt", "r");
//     if (fptr != 0)
//     {
//         while (!feof(fptr))
//         {
//             fgets(fileLine, 100, fptr);
//             if (!feof(fptr))
//             {
//                 puts(fileLine);
//             }
//         }
//     }
//     else
//     {
//         printf("\nBlad otwierania pliku!\n");
//     }
//     fclose(fptr);
//     return(0);
// }