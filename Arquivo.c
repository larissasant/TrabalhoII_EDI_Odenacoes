#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca que contem os acentos
#include <time.h>
#include <windows.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int x=0;
    int i;
    int vet100[100], vet1000[1000], vet10000[10000], vet100000[100000];
    srand(time(NULL));

    do{
        system("cls");
        printf(" \t\tORDENAÇÃO\n");
        printf("\n 1 - Gerar Arquivo\n 2 - Ordenar Arquivo\n 0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &x);

        switch (x){
            //arquivo 1
        case 1:{

            system("cls");//limpar tela
            printf("1 - Gerar Arquivo\n\n");
            FILE *arquivo100;
            arquivo100 = fopen("arquivo100.txt", "w"); //abre o arquivo de texto pra gravar
            //fclose(arquivo100);//fecha o arquivo, mais garante a transferencia
            //arquivo100 = fopen("arquivo100.txt","a"); //ler o final do arquivo
            for(i=0; i<100; i++){
                //y =  1 + ( rand() % 999 );//gerar numeros aleatorios ate 100
                fprintf (arquivo100, "%d ", ( rand() % 101 ));// saida do arquivo
            }
            fclose(arquivo100);//fecha o arquivo
            printf("Tamanho do Arquivo: 100\n");

            arquivo100 = fopen("arquivo100.txt", "r");
            for (i=0; i<100; i++){
                fscanf(arquivo100, "%d", &vet100[i]);
            }
            fclose(arquivo100);

            //aquivo 2
            FILE *arquivo1000;
            arquivo1000 = fopen("arquivo1000.txt", "w");//abrir o arquivo e gravar
            //fclose(arquivo1000); //fechar o arquivo2
            //arquivo1000 = fopen("arquivo1000.txt", "a"); //ler ate o final
            for(i=0; i<1000; i++){ //percorrer o arquivo
                //y = 1 + (rand()%999); //gerar numeros aleatorios
                fprintf(arquivo1000, "%d ",( rand() % 101 ));
            }
            fclose(arquivo1000);//fechar arquivo2
            printf("Tamanho do Arquivo: 1000\n");

            arquivo1000 = fopen("arquivo1000.txt", "r");
            for (i=0; i<1000; i++){
                fscanf(arquivo1000, "%d", &vet1000[i]);
            }
            fclose(arquivo1000);

            //arquivo 3
            FILE *arquivo10000;
            arquivo10000 = fopen("arquivo10000.txt", "w");
            //fclose(arquivo10000);
            //arquivo10000 = fopen("arquivo10000.txt", "a");
            for(i=0; i< 10000; i++){
                //y= 1 +(rand()%999);
                fprintf(arquivo10000,"%d ", ( rand() % 101 ));
            }
            fclose(arquivo10000);
            printf("Tamanho do Arquivo: 10000\n");

            arquivo10000 = fopen("arquivo10000.txt", "r");
            for (i=0; i<10000; i++){
                fscanf(arquivo10000, "%d", &vet10000[i]);
            }
            fclose(arquivo10000);

            //arquivo 4
            FILE *arquivo100000;
            arquivo100000 = fopen("arquivo100000.txt", "w");
            //fclose(arquivo100000);
            //arquivo100000 = fopen("arquivo100000.txt", "a");
            for(i=0; i<100000; i++){
               // y= 1 + (rand()%999);
                fprintf(arquivo100000,"%d ", ( rand() % 101 ));
            }
            fclose(arquivo100000);
            printf("Tamanho do Arquivo: 100000\n");

            arquivo100000 = fopen("arquivo100000.txt", "r");
            for (i=0; i<100000; i++){
                fscanf(arquivo100000, "%d", &vet100000[i]);
            }
            fclose(arquivo100000);

            printf("\nAperte <Enter> para continuar...\n");
            getch();
            break;
        }
        case 2:{
            system("cls");//limpar
            printf("\t\t\t\tOrdenar Arquivo\n");
            int opMenu2;
            printf ("\nEscolha um algoritmo para ordenar e saber detalhadamente: \n\n\t->Tempo de execução\n\t->Trocas Realizadas\n\t->Comparações realizadas\nOpção:");
            do{
                printf("\n\n\t\t1 - Insertion Sort\n\t\t2 - Selection Sort\n\t\t3 - Bubble Sort \n\t\t4 - Radix Sort\n\t\t5 - Quick Sort\n\t\t6 - Merge Sort\n\t\t0 - Voltar\n");
                printf("Opção: ");
                setbuf(stdin,NULL);
                scanf("%d",&opMenu2);

                switch(opMenu2){

                    case 1:{
                        int * insertionSort(int original[], int length, int *cont) {
                            int j, atual;

                            for (i = 1; i < length; i++) {
                                atual = original[i];
                                j = i - 1;

                                while ((j >= 0) && (atual < original[j])) {
                                    original[j + 1] = original[j];
                                    j = j - 1;
                                }

                                original[j + 1] = atual;

                                *cont+=1;
                            }



                            return (int * )original;
                        }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100 */
                        printf("\t\t\tVetor de 100 Desordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d ", vet100[i]); //imprime o vetor desorganizado
                        }
                        int cont = 0;
                        insertionSort(vet100, 99+1, &cont);

                        printf("\n\n\n\t\t\tVetor de 100 Ordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d", vet100[i]); //imprime o vetor reorganizado
                        }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 1000 */
                        printf("\t\t\tVetor de 1000 Desordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        insertionSort(vet1000, 999+1,  &cont);

                        printf("\n\n\n\t\t\tVetor de 1000 Ordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 10000 */
                        printf("\t\t\tVetor de 10000 Desordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        insertionSort(vet10000, 9999+1, &cont);

                        printf("\n\n\n\t\t\tVetor de 10000 Ordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100000 */
                        printf("\t\t\tVetor de 100000 Desordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        insertionSort(vet100000, 99999+1,  &cont);

                        printf("\n\n\n\t\t\tVetor de 100000 Ordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        printf("CONT %d\n",  cont);

                        Sleep(2000);
                        //system("cls");


                        //ARQUIVO100
                        FILE *arquivo100_Ordenado;
                        arquivo100_Ordenado = fopen("arquivo100_Ordenado.txt", "w");

                        for (i = 0; i < 100; i++){
                            fprintf(arquivo100_Ordenado, "%d ", vet100[i]);
                        }

                        fclose(arquivo100_Ordenado);

                        //ARQUIVO1000
                        FILE *arquivo1000_Ordenado;
                        arquivo1000_Ordenado = fopen("arquivo1000_Ordenado.txt", "w");

                        for (i = 0; i < 1000; i++){
                            fprintf(arquivo1000_Ordenado, "%d ", vet1000[i]);
                        }

                        fclose(arquivo1000_Ordenado);

                        //ARQUIVO10000
                        FILE *arquivo10000_Ordenado;
                        arquivo10000_Ordenado = fopen("arquivo10000_Ordenado.txt", "w");

                        for (i = 0; i < 10000; i++){
                            fprintf(arquivo10000_Ordenado, "%d ", vet10000[i]);
                        }

                        fclose(arquivo10000_Ordenado);

                         //ARQUIVO100000
                        FILE *arquivo100000_Ordenado;
                        arquivo100000_Ordenado = fopen("arquivo100000_Ordenado.txt", "w");

                        for (i = 0; i < 100000; i++){
                            fprintf(arquivo100000_Ordenado, "%d ", vet100000[i]);
                        }

                        fclose(arquivo100000_Ordenado);

                        break;
                    }

                    case 2:{
                        void selection_sort(int num[], int tam){
                              int j, min, aux;
                              for (i = 0; i < (tam-1); i++){
                                 min = i;
                                 for (j = (i+1); j < tam; j++) {
                                   if(num[j] < num[min])
                                     min = j;
                                 }
                                 if (i != min) {
                                   aux = num[i];
                                   num[i] = num[min];
                                   num[min] = aux;
                                 }
                              }
                            }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100 */
                        printf("\t\t\tVetor de 100 Desordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d ", vet100[i]); //imprime o vetor desorganizado
                        }

                        selection_sort(vet100, 99+1);

                        printf("\n\n\n\t\t\tVetor de 100 Ordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d", vet100[i]); //imprime o vetor reorganizado
                        }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 1000 */
                        printf("\t\t\tVetor de 1000 Desordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        selection_sort(vet1000, 999+1);

                        printf("\n\n\n\t\t\tVetor de 1000 Ordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 10000 */
                        printf("\t\t\tVetor de 10000 Desordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        selection_sort(vet10000, 9999+1);

                        printf("\n\n\n\t\t\tVetor de 10000 Ordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100000 */
                        printf("\t\t\tVetor de 100000 Desordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        selection_sort(vet100000, 99999+1);

                        printf("\n\n\n\t\t\tVetor de 100000 Ordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        Sleep(2000);
                        //system("cls");


                        //ARQUIVO100
                        FILE *arquivo100_Ordenado;
                        arquivo100_Ordenado = fopen("arquivo100_Ordenado.txt", "w");

                        for (i = 0; i < 100; i++){
                            fprintf(arquivo100_Ordenado, "%d ", vet100[i]);
                        }

                        fclose(arquivo100_Ordenado);

                        //ARQUIVO1000
                        FILE *arquivo1000_Ordenado;
                        arquivo1000_Ordenado = fopen("arquivo1000_Ordenado.txt", "w");

                        for (i = 0; i < 1000; i++){
                            fprintf(arquivo1000_Ordenado, "%d ", vet1000[i]);
                        }

                        fclose(arquivo1000_Ordenado);

                        //ARQUIVO10000
                        FILE *arquivo10000_Ordenado;
                        arquivo10000_Ordenado = fopen("arquivo10000_Ordenado.txt", "w");

                        for (i = 0; i < 10000; i++){
                            fprintf(arquivo10000_Ordenado, "%d ", vet10000[i]);
                        }

                        fclose(arquivo10000_Ordenado);

                         //ARQUIVO100000
                        FILE *arquivo100000_Ordenado;
                        arquivo100000_Ordenado = fopen("arquivo100000_Ordenado.txt", "w");

                        for (i = 0; i < 100000; i++){
                            fprintf(arquivo100000_Ordenado, "%d ", vet100000[i]);
                        }

                        fclose(arquivo100000_Ordenado);

                        break;
                    }

                    case 3:{

                        void bubble_sort(int list[], int n){
                              int j, t;

                              for (i = 0 ; i < ( n - 1 ); i++){
                                for (j = 0 ; j < n - i - 1; j++){
                                  if (list[j] > list[j+1]){
                                    /* Swapping */
                                    t         = list[j];
                                    list[j]   = list[j+1];
                                    list[j+1] = t;
                                  }
                                }
                              }
                            }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100 */
                        printf("\t\t\tVetor de 100 Desordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d ", vet100[i]); //imprime o vetor desorganizado
                        }

                        bubble_sort(vet100, 99+1);

                        printf("\n\n\n\t\t\tVetor de 100 Ordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d", vet100[i]); //imprime o vetor reorganizado
                        }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 1000 */
                        printf("\t\t\tVetor de 1000 Desordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        bubble_sort(vet1000, 999+1);

                        printf("\n\n\n\t\t\tVetor de 1000 Ordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 10000 */
                        printf("\t\t\tVetor de 10000 Desordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        bubble_sort(vet10000, 9999+1);

                        printf("\n\n\n\t\t\tVetor de 10000 Ordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100000 */
                        printf("\t\t\tVetor de 100000 Desordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        bubble_sort(vet100000, 99999+1);

                        printf("\n\n\n\t\t\tVetor de 100000 Ordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        Sleep(2000);
                        //system("cls");


                        //ARQUIVO100
                        FILE *arquivo100_Ordenado;
                        arquivo100_Ordenado = fopen("arquivo100_Ordenado.txt", "w");

                        for (i = 0; i < 100; i++){
                            fprintf(arquivo100_Ordenado, "%d ", vet100[i]);
                        }

                        fclose(arquivo100_Ordenado);

                        //ARQUIVO1000
                        FILE *arquivo1000_Ordenado;
                        arquivo1000_Ordenado = fopen("arquivo1000_Ordenado.txt", "w");

                        for (i = 0; i < 1000; i++){
                            fprintf(arquivo1000_Ordenado, "%d ", vet1000[i]);
                        }

                        fclose(arquivo1000_Ordenado);

                        //ARQUIVO10000
                        FILE *arquivo10000_Ordenado;
                        arquivo10000_Ordenado = fopen("arquivo10000_Ordenado.txt", "w");

                        for (i = 0; i < 10000; i++){
                            fprintf(arquivo10000_Ordenado, "%d ", vet10000[i]);
                        }

                        fclose(arquivo10000_Ordenado);

                         //ARQUIVO100000
                        FILE *arquivo100000_Ordenado;
                        arquivo100000_Ordenado = fopen("arquivo100000_Ordenado.txt", "w");

                        for (i = 0; i < 100000; i++){
                            fprintf(arquivo100000_Ordenado, "%d ", vet100000[i]);
                        }

                        fclose(arquivo100000_Ordenado);

                        break;
                    }

                    case 4:{
                        void radixsort(int vetor[], int tamanho) {
                            int *b;
                            int maior = vetor[0];
                            int exp = 1;

                            b = (int *)calloc(tamanho, sizeof(int));

                            for (i = 0; i < tamanho; i++) {
                                if (vetor[i] > maior)
                                    maior = vetor[i];
                            }

                            while (maior/exp > 0) {
                                int bucket[10] = { 0 };
                                for (i = 0; i < tamanho; i++)
                                    bucket[(vetor[i] / exp) % 10]++;
                                for (i = 1; i < 10; i++)
                                    bucket[i] += bucket[i - 1];
                                for (i = tamanho - 1; i >= 0; i--)
                                    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
                                for (i = 0; i < tamanho; i++)
                                    vetor[i] = b[i];
                                exp *= 10;
                            }

                            free(b);
                        }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100 */
                        printf("\t\t\tVetor de 100 Desordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d ", vet100[i]); //imprime o vetor desorganizado
                        }

                        radixsort(vet100, 99+1);

                        printf("\n\n\n\t\t\tVetor de 100 Ordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d", vet100[i]); //imprime o vetor reorganizado
                        }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 1000 */
                        printf("\t\t\tVetor de 1000 Desordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        radixsort(vet1000, 999+1);

                        printf("\n\n\n\t\t\tVetor de 1000 Ordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 10000 */
                        printf("\t\t\tVetor de 10000 Desordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        radixsort(vet10000, 9999+1);

                        printf("\n\n\n\t\t\tVetor de 10000 Ordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100000 */
                        printf("\t\t\tVetor de 100000 Desordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        radixsort(vet100000, 99999+1);

                        printf("\n\n\n\t\t\tVetor de 100000 Ordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        Sleep(2000);
                        //system("cls");


                        //ARQUIVO100
                        FILE *arquivo100_Ordenado;
                        arquivo100_Ordenado = fopen("arquivo100_Ordenado.txt", "w");

                        for (i = 0; i < 100; i++){
                            fprintf(arquivo100_Ordenado, "%d ", vet100[i]);
                        }

                        fclose(arquivo100_Ordenado);

                        //ARQUIVO1000
                        FILE *arquivo1000_Ordenado;
                        arquivo1000_Ordenado = fopen("arquivo1000_Ordenado.txt", "w");

                        for (i = 0; i < 1000; i++){
                            fprintf(arquivo1000_Ordenado, "%d ", vet1000[i]);
                        }

                        fclose(arquivo1000_Ordenado);

                        //ARQUIVO10000
                        FILE *arquivo10000_Ordenado;
                        arquivo10000_Ordenado = fopen("arquivo10000_Ordenado.txt", "w");

                        for (i = 0; i < 10000; i++){
                            fprintf(arquivo10000_Ordenado, "%d ", vet10000[i]);
                        }

                        fclose(arquivo10000_Ordenado);

                         //ARQUIVO100000
                        FILE *arquivo100000_Ordenado;
                        arquivo100000_Ordenado = fopen("arquivo100000_Ordenado.txt", "w");

                        for (i = 0; i < 100000; i++){
                            fprintf(arquivo100000_Ordenado, "%d ", vet100000[i]);
                        }

                        fclose(arquivo100000_Ordenado);

                        break;
                    }
                    case 5:{
                        void quick(int vet[], int esq, int dir){
                            int pivo = esq, ch,j;         //Declaração das variavés e inicialização do pivo com o primeiro algarismo da sequencia
                            for(i=esq+1;i<=dir;i++){        //Percorre todos os espaços do vetor
                                j = i;                      //atribuição de valor
                                if(vet[j] < vet[pivo]){     //verifica se o vetor da posição pivo é maior que de outra posição
                                 ch = vet[j];               //ch recebe o valor que é menor
                                 while(j > pivo){           //repete enquanto o j que é a posição do algarismo menor que o pivo ficar na posição 0
                                    vet[j] = vet[j-1];      //reorganiza a posição de vetores
                                    j--;                    //decremento para a organização
                                 }
                                 vet[j] = ch;               // atribuição da variavel menor que o pivo na posição inicial
                                 pivo++;                    // aumenta a posição do pivo em uma unidade
                                }
                            }
                            if(pivo-1 >= esq){              // verifica se o valor do pivo é maior que o final do vetor.
                                quick(vet,esq,pivo-1);      //final da execursão da função
                            }
                            if(pivo+1 <= dir){              //verifica se o valor do pivo é menor, indicando que ainda estar dentro das limitações do vetor
                                quick(vet,pivo+1,dir);      //chama a função para eecutar novamente
                            }
                         }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100 */
                        printf("\t\t\tVetor de 100 Desordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d ", vet100[i]); //imprime o vetor desorganizado
                        }

                        quick(vet100, 0, 99); //Chama a função quick com os tres parametros: o vetor, 0 o inicio do vetor e o fim.

                        printf("\n\n\n\t\t\tVetor de 100 Ordenado\n\n");

                        for (i = 0; i < 100; i++){ //percorre o vetor
                            printf("%d", vet100[i]); //imprime o vetor reorganizado
                        }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 1000 */
                        printf("\t\t\tVetor de 1000 Desordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        quick(vet1000, 0, 999);

                        printf("\n\n\n\t\t\tVetor de 1000 Ordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 10000 */
                        printf("\t\t\tVetor de 10000 Desordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        quick(vet10000, 0, 9999);

                        printf("\n\n\n\t\t\tVetor de 10000 Ordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100000 */
                        printf("\t\t\tVetor de 100000 Desordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        quick(vet100000, 0, 99999);

                        printf("\n\n\n\t\t\tVetor de 100000 Ordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        Sleep(2000);
                        //system("cls");


                        //ARQUIVO100
                        FILE *arquivo100_Ordenado;
                        arquivo100_Ordenado = fopen("arquivo100_Ordenado.txt", "w");

                        for (i = 0; i < 100; i++){
                            fprintf(arquivo100_Ordenado, "%d ", vet100[i]);
                        }

                        fclose(arquivo100_Ordenado);

                        //ARQUIVO1000
                        FILE *arquivo1000_Ordenado;
                        arquivo1000_Ordenado = fopen("arquivo1000_Ordenado.txt", "w");

                        for (i = 0; i < 1000; i++){
                            fprintf(arquivo1000_Ordenado, "%d ", vet1000[i]);
                        }

                        fclose(arquivo1000_Ordenado);

                        //ARQUIVO10000
                        FILE *arquivo10000_Ordenado;
                        arquivo10000_Ordenado = fopen("arquivo10000_Ordenado.txt", "w");

                        for (i = 0; i < 10000; i++){
                            fprintf(arquivo10000_Ordenado, "%d ", vet10000[i]);
                        }

                        fclose(arquivo10000_Ordenado);

                         //ARQUIVO100000
                        FILE *arquivo100000_Ordenado;
                        arquivo100000_Ordenado = fopen("arquivo100000_Ordenado.txt", "w");

                        for (i = 0; i < 100000; i++){
                            fprintf(arquivo100000_Ordenado, "%d ", vet100000[i]);
                        }

                        fclose(arquivo100000_Ordenado);

                        break;
                    }
                    case 6:{
                        void merge(int *vet, int inicio, int meio, int fim){
                            int *aux, p1, p2, tam, i, j, k;
                            int fim1 = 1, fim2 = 1;
                            tam = fim-inicio+1;
                            p1 = inicio;
                            p2 = meio +1;

                            aux = (int *) malloc(tam*sizeof(int));

                                for (i = 0; i < tam; i++){
                                    if(fim1 && fim2){
                                        if(vet[p1] < vet[p2])
                                            aux[i] = vet[p1++];
                                        else
                                            aux[i] = vet[p2++];
                                        if(p1 > meio)
                                            fim1 = 0;
                                        if(p2 > fim)
                                            fim2 = 0;
                                    }
                                    else{
                                        if(fim1)
                                            aux[i] = vet[p1++];
                                        else
                                            aux[i] = vet[p2++];
                                    }
                                }
                                for(j = 0, k = inicio; j < tam; j++, k++){
                                    vet[k] = aux[j];
                                }
                            free(aux);
                        }

                        void mergeSort (int *vet, int inicio, int fim){
                            int meio;
                            if (inicio < fim){
                                meio = (inicio + fim)/2;
                                mergeSort(vet, inicio, meio);
                                mergeSort(vet, meio+1, fim);
                                merge(vet, inicio, meio, fim);
                            }
                        }

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100 */
                        printf("\t\t\tVetor de 100 Desordenado\n\n");

                        for (i = 0; i < 100; i++){
                            printf("%d ", vet100[i]);
                        }

                        mergeSort(vet100, 0, 99);

                        printf("\n\n\n\t\t\tVetor de 100 Ordenado\n\n");

                        for (i = 0; i < 100; i++){
                            printf("%d ", vet100[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 1000 */
                        printf("\t\t\tVetor de 1000 Desordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        mergeSort(vet1000, 0, 999);

                        printf("\n\n\n\t\t\tVetor de 1000 Ordenado\n\n");

                        for (i = 0; i < 1000; i++){
                            printf("%d ", vet1000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 10000 */
                        printf("\t\t\tVetor de 10000 Desordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        mergeSort(vet10000, 0, 9999);

                        printf("\n\n\n\t\t\tVetor de 10000 Ordenado\n\n");

                        for (i = 0; i < 10000; i++){
                            printf("%d ", vet10000[i]);
                        }

                        Sleep(2000);
                        system("cls");

                        /* MOSTRA VETOR DESORDENADO E ORDENADO DE 100000 */
                        printf("\t\t\tVetor de 100000 Desordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        mergeSort(vet100000, 0, 99999);

                        printf("\n\n\n\t\t\tVetor de 100000 Ordenado\n\n");

                        for (i = 0; i < 100000; i++){
                            printf("%d ", vet100000[i]);
                        }

                        Sleep(2000);
                        //system("cls");


                        //ARQUIVO100
                        FILE *arquivo100_Ordenado;
                        arquivo100_Ordenado = fopen("arquivo100_Ordenado.txt", "w");

                        for (i = 0; i < 100; i++){
                            fprintf(arquivo100_Ordenado, "%d ", vet100[i]);
                        }

                        fclose(arquivo100_Ordenado);

                        //ARQUIVO1000
                        FILE *arquivo1000_Ordenado;
                        arquivo1000_Ordenado = fopen("arquivo1000_Ordenado.txt", "w");

                        for (i = 0; i < 1000; i++){
                            fprintf(arquivo1000_Ordenado, "%d ", vet1000[i]);
                        }

                        fclose(arquivo1000_Ordenado);

                        //ARQUIVO10000
                        FILE *arquivo10000_Ordenado;
                        arquivo10000_Ordenado = fopen("arquivo10000_Ordenado.txt", "w");

                        for (i = 0; i < 10000; i++){
                            fprintf(arquivo10000_Ordenado, "%d ", vet10000[i]);
                        }

                        fclose(arquivo10000_Ordenado);

                         //ARQUIVO100000
                        FILE *arquivo100000_Ordenado;
                        arquivo100000_Ordenado = fopen("arquivo100000_Ordenado.txt", "w");

                        for (i = 0; i < 100000; i++){
                            fprintf(arquivo100000_Ordenado, "%d ", vet100000[i]);
                        }

                        fclose(arquivo100000_Ordenado);

                        break;
                    }

                }

                Sleep(2000);
                system("cls");
                if(opMenu2 != 0 && opMenu2 <= 6){
                    printf("Escolha Outra opção\n");
                }

                if(opMenu2 > 6){
                    system("cls");
                    printf("\nopção invalida, tente novamente.\n");
                    Sleep(2000);
                    system("cls");
                    continue;
                }
                //menu2(opMenu2);
            }
            while (opMenu2 != 0);
            break;
        }
        case 0:{
            system("cls");
            printf("FIM");
            exit(1);
            }
        }
    }
    while (x != 0);

    return 0;
}
