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
				system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tCadastrar Novo usuario");
				printf("\n============================================================================================\n");
				cadastrarId();
				cadastrarNome();
				cadastrarEmail();
				cadastrarSexo();
				cadastrarVacina();
				cadastrarAltura();								
				i++;				
				cont ++;
				printf("\n\t\t\tCadastro realizado com sucesso!!!\n\n");
				system("pause");
				break;	
			case 2:	
					system("cls");
					printf("\n============================================================================================\n");
					printf("\t\t\tUsuarios Cadastrados");
					printf("\n============================================================================================\n");			
				for(i=0;i<cont;i++){					
					printf("\n\tID Usuario...........................................: %i\n", idUsuario[i] );			
					printf("\tNome.................................................: %s", nome[i]);
					printf("\tEmail cadastrado.....................................: %s\n",eMail[i]);
					printf("\tSexo.................................................: %s\n", sexo[i]);
					printf("\tTomou vacina?........................................: ");					
					if(vacina[i] == 1){ 
						printf("SIM\n");
					}else{
						printf("NAO\n");					
					}				
					printf("\tAltura...............................................: %i = %.2f\n", i, altura[i]);				
					printf("\n");
				}				
			
			system ("pause");
				break;
			case 3: 
				system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tPesquisar Usuarios Cadastrados");
				printf("\n============================================================================================\n");
					//insira aqui a função Pesquisar por id e por e-mail//
			system ("pause");
				break;
			case 4:
				system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tExcluir Usuarios Cadastrados");
				printf("\n============================================================================================\n");
					//insira aqui a função excluir//
			system ("pause");
			break;
			case 5:
				system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tEditar Usuarios Cadastrados");
				printf("\n============================================================================================\n");
					//insira aqui a função Editar//
			system ("pause");			
				break;			
			case 6:			
               system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tRealizar Backup");
				printf("\n============================================================================================\n");
					//insira aqui a função Backup//
			system ("pause");
				break;
			case 7 :			
               system("cls");
				printf("\n============================================================================================\n");
				printf("\t\t\tRestaurar Backup");
				printf("\n============================================================================================\n");
					//insira aqui a função restaurar Backup//
			system ("pause");
				break;							
		}
	
	}while(opc !=8);
	
	return 0; 	
}
int menu(){
system ("cls");
	int opcao=0;		
	do{
		system ("cls");
		printf("\n==============================================================\n");
		printf("\tSelecione uma opcao: ");
		printf("\n==============================================================\n");
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
		printf("\n");	
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
	printf("ID Usuario...................................................: %i\n", idUsuario[i]);
}
void cadastrarNome(){
	do{
		printf("Informe seu nome.............................................: ");
   		fgets(nome[i],sizeof(nome[i]), stdin);
		if (strlen(nome[i])== 1){
			
			printf("Este campo nao pode ser vazio\n");
		}
	}while(strlen(nome[i])== 1);
}
void cadastrarSexo(){ 
	do{
		printf("Informe sexo: Masculino, Feminino ou Nao-declarado...........: ");		
   		scanf("%s", sexo[i]);
		fflush(stdin);
   		strupr(sexo[i]); //função que converte a string para maiúsculo. 
		if(strcmp(sexo[i],"MASCULINO")!=0 && strcmp(sexo[i],"FEMININO")!=0 && strcmp(sexo[i], "NAO-DECLARADO")!=0){
			printf("Erro, opcao invalida\n");		
		}
	}while(strcmp(sexo[i],"MASCULINO")!=0 && strcmp(sexo[i],"FEMININO")!=0 && strcmp(sexo[i], "NAO-DECLARADO")!=0);
}
void cadastrarAltura(){	
	do{
		printf("Informe sua altura separada por '.'ponto: ex: 1.60...........: ");
		scanf("%lf", &altura[i]);		
		if (altura[i] < 1 || altura[i] > 2){
			printf("Erro, altura invalida\n");
			printf("valor não pode ser superior a 2.00 mts\n");			
		}		
	}while(altura[i] < 1 || altura[i] > 2);	
}
void cadastrarVacina(){	
	do{
		printf("Tomou a vacina? digite [1] para SIM ou [2] para NAO..........: ");
		scanf("%d", &vacina[i]);		
		if (vacina[i] < 1 || vacina[i] > 2){
			printf("Erro, opcao invalida\n");			
		}		
	}while(vacina[i] < 1 || vacina[i] > 2);		
}
void cadastrarEmail(){	
char *validador;
	do{
		printf("Informe o seu e-mail.........................................: ");
		scanf("%s", eMail[i]);	
		strlwr(eMail[i]); //função que converte a string para minusculo.
		validador = strchr(eMail[i],'@'); //função que percorre a string comparando o caractere @ com cada caractere da string, caso não encontre retorna NULL.
		if(validador == NULL){
			printf("digite um e-mail valido\n");	
		}
	}while(validador == NULL);

}