/*
	Name: 
	Author: Fabio.Fonts 
	Date: 17/11/25 08:50
	Description: 
*/
 #include<windows.h>
 #include<stdio.h>
 #include<locale.h>
 
 
    	
 void swap(int *, int *);
 int partition(int *, int, int);
 void quickSort(int*, int, int);
 
 main()
 {
    setlocale(LC_ALL,"portuguese");
    //sessão de cores
   
 	
 	int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
 	
 	int i;
 	int tam= sizeof(vet)/sizeof(int);
 	
 	puts("vetor original");
 	for(int i = 0; i < tam; i++)
	 printf("[%d]", vet[i]);
	 
 	quickSort(vet, 0, tam -1);
	
 	puts("\nvetor arrumado");
 	for(int i = 0; i < tam; i++)
	 printf("[%d]", vet[i]);
 } //fim do progama
 
 //função que realiza a partição do conjunto de dados;
 int partition(int *V, int inicio, int fim)
 {
	 int pivot = V[inicio];//primeiro elemento como pivot
	 int i = (fim+1);
		 for(int j = fim; j>= inicio +1; j--){
		 	
		 	if(V[j] >= pivot){
		 		i--;
				swap(&V[i],&V[j]); 
			
	 			}
	}
	swap(&V[i-1], &V[inicio]);
	return i-1;
 }
 //função principal quick sort
 void quickSort(int *V, int inicio, int fim)
 {
 		if(inicio < fim)
 	{
 		int pivot = partition(V, inicio, fim);
 		quickSort(V,inicio, pivot-1);
 		quickSort(V,pivot+1, fim);
	 }
 	
 	
 }
 // função para fazer a trocas de elementos entre si
 void swap(int *a, int *b){
 	int aux = *a;
 	*a = *b;
 	*b = aux;
 }
 
 
 
