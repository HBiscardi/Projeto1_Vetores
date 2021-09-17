#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int idUsuario[1000], vacina[1000], i=0, opc;
char nome[1000][50], eMail[1000][50], sexo[1000][10], endereco[1000][150];
double altura[1000];


int menu();
void cadastrarId();
void cadastrarNome();
void cadastrarSexo();
void cadastrarAltura();
void cadastrarVacina();
void cadastrarEmail();
//int idUsuario[i], int vacina[i],nome[i], eMail[i], sexo[i], endereco[i], altura[i]//


int main(){

	int cont=0;
	do{	

		opc = menu();

		switch(opc){
			case 1:
				cadastrarId();
				cadastrarNome();
				/*cadastrarEmail();*/
				/*cadastrarSexo();*/
				cadastrarVacina();
				/*cadastrarAltura();*/
				
								
				i++;				
				cont ++;
				break;	
			case 2:				
				for(i=0;i<cont;i++){
					printf("idUsuario: %i %i\n", i, idUsuario[i] );			
					printf("Nome: %i = %s", i, nome[i]);
					printf("Email cadastrado: %i = %s\n",i, eMail[i]);
					/*printf("Sexo: %s\n", sexo[i]);*/
					printf("Tomou vacina? %i = ", i);
					
					if(vacina[i] == 1){ 
						printf("SIM\n");
					}else{
						printf("NAO\n");					
					}				
					printf("Altura: %i = %lf\n", i, altura[i]);				
					printf("\n");
				}
				
			
			
			system ("pause");
				break;
			case 3: 
				//insira aqui a função Pesquisar//
				break;
			case 4:
				
			break;
			case 5:	
				//insira aqui a função Editar//			
				break;			
			case 6:			
               //insira aqui a função Backup//
				break;						
		}
	
	}while(opc !=7);
	
	return 0; 	
}

int menu(){

system ("cls");
	int opcao=0;
		
	do{
		system ("cls");
		printf("\n==================================================\n");
		printf("\tSelecione uma opcao: ");
		printf("\n==================================================\n");
		printf(" [1]\tCadastrar Novo Usuario\n");
		printf(" [2]\tListar Usuarios Cadastrados\n");
		printf(" [3]\tPesquisar Usuario\n");
		printf(" [4]\tExcluir Cadastro\n");
		printf(" [5]\tEditar Cadastro\n");		
		printf(" [6]\tBackup\n");
		printf(" [7]\tSair\n");	
		
		printf("\nOpcao desejada: ");	
		scanf("%d", &opcao);
		getchar();
		if(opcao > 7 || opcao < 1){
			printf("\n\tATENCAO!!!\n\n");
			printf("\tOpcao Invalida\n\n");
			system("pause");
		}			
	}while(opcao == 0);	
return opcao;
}

void cadastrarId(){
	int idTemp;
	do{
		srand(time(NULL));
		idTemp = rand()%10000;
			
	}while (idTemp == idUsuario[i]);

	idUsuario[i] = idTemp;
}
void cadastrarNome(){
	printf("Informe seu nome: ");
    fgets(nome[i],sizeof(nome), stdin);

}
/*void cadastrarSexo(){ 

	do{
		printf("Informe sexo: Masculino, Feminino ou Nao declarado ");
   		fgets(sexo[i],sizeof(sexo), stdin);
   		strupr(sexo[i]); //função que converte a string para maiúsculo.
   		
		if(strcmp(sexo[i],"MASCULINO") == 0 || strcmp(sexo[i],"FEMININO") == 0 || strcmp(sexo[i], "NAO DECLARADO") == 0){
			printf("Erro, opcao invalida\n");			
		}
	}while(strcmp(sexo[i],"MASCULINO") == 0 || strcmp(sexo[i],"FEMININO") == 0 || strcmp(sexo[i], "NAO DECLARADO") == 0);
}*/



void cadastrarAltura(){
	
	do{
		printf("Informe sua altura, valores entre 1 e 2 metros: ");
		scanf("%lf", &altura[i]);
		
		if (altura[i] < 1 || altura[i] > 2){
			printf("Erro, altura invalida\n");			
		}		
	}while(altura[i] < 1.0 || altura[i] > 2.0);	
}

void cadastrarVacina(){
	
	do{
		printf("Tomou a vacina? [1] SIM [2] NAO: ");
		scanf("%d", &vacina[i]);
		
		if (vacina[i] < 1 || vacina[i] > 2){
			printf("Erro, opcao invalida\n");			
		}		
	}while(vacina[i] < 1 || vacina[i] > 2);
		
}

/*void cadastrarEmail(){	

		printf("Informe o seu e-mail: ");
    	fgets((eMail[i]),sizeof(eMail[i]), stdin);	
    	strupr(eMail[i]); //função que converte a string para maiúsculo.
    	//printf("\n%s", email(i);
    	
    	do{
    		
    		
    		
		}while();	   
}*/