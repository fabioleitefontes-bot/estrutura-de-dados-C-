/*
	Name: insertionsort
	Author: Fabio.Fonts 
	Date: 07/04/26 08:50
	Description: programa para demostrar a aplicação do método selection sort
*/
 #include<windows.h>
 #include<stdio.h>
 #include<locale.h>
 #include<time.h>
 
 //prototipação
 
 void insertionSort(int*, int);
 int trocas, comp = 0;
 
 
 main()//inicio do main
 {
	    setlocale(LC_ALL,"portuguese");
	    //sessão de cores
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    
	    CONSOLE_SCREEN_BUFFER_INFO csbi;
	    GetConsoleScreenBufferInfo(hConsole, &csbi);
	    WORD cor_original = csbi.wAttributes; 
	    	SetConsoleTextAttribute(hConsole, 15);//negrito
	    	SetConsoleTextAttribute(hConsole, 7);
	 
	//int vet[] = {17,38,12,2,44,25, 19, -4, 30, 10};
	 int vet[100];
	int tam = sizeof(vet)/sizeof(int);
	
	srand(time(NULL));
	for(int i =0; i<tam; i++){
		vet[i] = rand()%10000;}
	

	int x;
	 	SetConsoleTextAttribute(hConsole, 15);//negrito
	 	printf("vetor original:\n");
	 	SetConsoleTextAttribute(hConsole, 2);
	for(x = 0; x < tam; x++)
	 	printf("[%d]", vet[x]);
	SetConsoleTextAttribute(hConsole, 15); 
 insertionSort(vet, tam);
	
	 	printf("\n\nvetor ordenado com o insertion sort:\n");
	 	SetConsoleTextAttribute(hConsole, 11);
	 	
	for(x = 0; x < tam; x++)
	 	printf("[%d]", vet[x]);	
	 	
 
 SetConsoleTextAttribute(hConsole, 15);	
	 printf("\n\nquantidade de comparações: "); 
	  SetConsoleTextAttribute(hConsole, 14);
	   printf("[%d]", comp);
	    SetConsoleTextAttribute(hConsole, 15);
	 printf("\n\nquantidade de trocas:"); 
	 SetConsoleTextAttribute(hConsole, 14);
	 printf("[%d]", trocas);
 	
 	
 	
 } //fim do progama
 void insertionSort(int *V, int tam){
 	
 	int i, j, chave;
 	
 	for(i=1; i < tam; i++){
 		chave = V[i];
 		j = i -1;
 		while(j>=0 && chave < V[j]){
 			V[j+1] = V[j];
 			j--;
 			comp++;
 			trocas++;
		 }
		 V[j+1]= chave;
		 trocas++;
	 }
 }
 
 
 
 
