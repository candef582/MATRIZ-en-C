//Mostrar diagonal de 4x4 que no se repita

#include <stdio.h>
#include <stdlib.h>
#define tam 4

int main()
{
    char matriz[tam][tam];
    srand(time(NULL));
    cargarMatriz(matriz);
    mostrarMatriz (matriz);
    mostrarDiagonalSecundaria(matriz);

return 0;
}

char aleatorio()
{
    char letra[26] = {"qwertyuiopasdfghjklzxcvbnm"};
    int n = rand() %26;

    return letra[n];
}


void mostrarMatriz(char muestra [][tam])
{
    for (int i=0; i < tam ; i++)
    {
        for (int j=0; j < tam ; j++)
        {
            printf ("%c ", muestra[i][j]);
        }

         printf("\n");
    }
}


int noRepetir(char muestra[][tam],int n)
{
    int val = 0;
    int contador = 0;

    for(int i = 0 ; i < tam ; i++)
    {
        for(int j = 0 ; j < tam ; j++)
        {
            if (muestra[i][j] == n)
            {
                contador++;
            }
        }
    }

    if(contador == 1)
    {
        val = 1;
    }
    return val;
}

void cargarMatriz(char muestra[][tam])
{
    int n;
    for (int i = 0 ; i < tam ; i++)
    {
        for(int j = 0 ; j < tam ; j++)
        {
            n = aleatorio();
            muestra[i][j] = n;
            while (1 != noRepetir(muestra, n))
            {
                n = aleatorio();
                muestra[i][j] = n;
            }
        }
    }
}


void mostrarDiagonalSecundaria(char matriz[][tam])
{
    int j = tam;
    for(int i = 0 ; i < tam; i++)
    {
        j--;
        printf("----%c  ",matriz[i][j]);
    }
}

