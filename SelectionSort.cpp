/*
	Name: SelectionSort
	Author: Fabio.Fonts 
	Date: 31/03/2026
	Description: Programa para implemen
*/
 #include<windows.h>
 #include<stdio.h>
 #include<locale.h>
 #include<time.h>
 
int trocas = 0, comp = 0;
 
 void selectionSort(int*, int);
 
 main()
 {
 	 //sessão de cores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD cor_original = csbi.wAttributes; 
    
    setlocale(LC_ALL,"portuguese");
	//int vet[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
 int vet[100000];
	int tam = sizeof(vet)/sizeof(int);
	
	srand(time(NULL));
	for(int i =0; i<tam; i++){
		vet[i] = rand()%10000;}
 	
 	puts("vetor original\n");
	 	for(int i=0; i < tam; i++){
	 			SetConsoleTextAttribute(hConsole, 10);//negrito
	 		printf("[%d]", vet[i]);
	 			SetConsoleTextAttribute(hConsole, 7);//negrito
	 		}
		selectionSort(vet, tam);
	SetConsoleTextAttribute(hConsole, 15);
	 puts("\n\nvetor após o selection\n");
	 for(int i=0; i < tam; i++){
	 		SetConsoleTextAttribute(hConsole, 13);//negrito
	 	printf("[%d]", vet[i]);
	 		SetConsoleTextAttribute(hConsole, 7);//negrito
	} 			
	 printf("\n\nquantidade de comparações: %d", comp);
	 printf("\n\nquantidade de trocas: %d", trocas);
  	
	}
  //fim do progama
 
 
 //função com algorito selection sort
 void selectionSort(int *S, int tam){
 	
 	int i, j, menor, chave, aux;
	 //laço externo que itera do início ao fim do vetor
 	for(i=0; i < tam-1; i++){
 		
 		//assume que o menor elemento está na primeira posição do vetor
 		chave = i;
 		menor = i+1;
 		//laço interno para descobrir quem é o menor el
 			for(j= i+1; j < tam; j++){
 				if(S[j] < S[menor])
 					menor = j;
 					comp++;
 				
		 	}
		 	comp++;
		 	
		 //troca o menor elemento encontrando pelo elemento que está na chave
		 if(S[menor] < S[chave]){
		 	aux = S[chave];
		 	S[chave] = S[menor];
		 	S[menor] = aux;
		 	trocas++;
		 }
	 }
 	
 	
 }
 
 
 
 
 
 
