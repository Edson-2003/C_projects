#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* notas_file = fopen("notas.txt", "r");
    float nota, soma = 0;
    int n_notas = 0;
    while (fscanf(notas_file, "%f", &nota) == 1) {
        soma += nota;
        n_notas++;
    }

    fclose(notas_file);


    float media = soma / n_notas;
    FILE* media_file = fopen("media.txt", "w");

    fprintf(media_file, "%.2f", media);
    fclose(media_file);

    return 0;
}
