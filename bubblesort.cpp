/*
	Name: bubble sort
	Author: Fabio.Fonts 
	Date: 24/03/2026
	Description: programa para demostrar o uso do método de bubble sort
*/
 #include<windows.h>
 #include<stdio.h>
 #include<locale.h>
 #include<time.h>
 
 int trocas, comp;
 
 //sessão de prototipação
 
 void bubblesort(int *, int tam);
 
 main()
 {
    setlocale(LC_ALL,"portuguese");
    //sessão de cores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WORD cor_original = csbi.wAttributes; 
 
	
	// int vet[] = {17, 38, 2, 2, 44, 25, 19, -4, 30, 10};
	int vet[100000];
	int tam = sizeof(vet)/sizeof(int);
	
	srand(time(NULL));
	for(int i =0; i<tam; i++){
		vet[i] = rand()%10000;
	}
	 
	 int trocas, comp;
	 comp = trocas = 0;
 
		 puts("vetor original\n");
	 for(int i=0; i < tam; i++){
	 		SetConsoleTextAttribute(hConsole, 11);//negrito
	 	printf("[%d]", vet[i]);
	 		SetConsoleTextAttribute(hConsole, 7);//negrito
	}
	bubblesort(vet, tam);
	SetConsoleTextAttribute(hConsole, 15);
	 puts("\n\nvetor após o bubble\n");
	 for(int i=0; i < tam; i++){
	 		SetConsoleTextAttribute(hConsole, 10);//negrito
	 	printf("[%d]", vet[i]);
	 		SetConsoleTextAttribute(hConsole, 7);//negrito
	}
	
	 	SetConsoleTextAttribute(hConsole, 15);
	
	  }//fim do progama
  
  //função para ordenação em bubble sort
 void bubblesort(int *vet, int tam) {
    int aux;
    trocas = comp = 0;
    do {
        int i = 0;
        while(i < tam - 1) {
            comp++;
            if(vet[i] > vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                trocas++;
            }
            i++;
        }
        tam--;
     
    } while(tam > 1);
  	
  	 printf("\n\nquantidade de comparações: %d", comp);
	 printf("\n\nquantidade de trocas: %d", trocas);
  	
  }
  
  
