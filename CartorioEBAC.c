#include <stdio.h> //biblioteca de comunica��o
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletanto informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file,","); //Adicina uma v�gula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //"a" = atualizar
	fprintf(file,nome); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file,","); //Adciona uma v�gula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file, sobrenome); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file,","); //Adicona uma v�gula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cargo); //"%s" refere-se a string
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file, cargo); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa na tela
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo [200];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser consultado: "); //Consultando informa��os do usu�rio
	scanf("%s",cpf); //"%s" refere-se as strings
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
	
	if(file == NULL) //Fun��o para informa��es n�o existentes no sistema
	{
		printf("Arquivo n�o localizado! \n"); //Informa a inexist�ncia do usu�rio
	}
	
	while(fgets(conteudo, 200, file)!=NULL); //Informa��es consultadas do usu�rio
	{
		printf("\n\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa na tela
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char cpf[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser deletado: "); //Consultando informa��os do usu�rio a serem deletadas
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0;//Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
	
	 system("cls");
	
	 setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	 printf("### Cart�rio da EBAC ###\n\n");//In�cio do menu
	 printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n");
	  printf("\t4 - Sair do sistema\n\n\n");
	  printf("Op��o:");//Fim do menu
	 
	  scanf("%d", &opcao);
	 
	  system("cls"); //Respons�vel por limpar a tela
	 
	  switch(opcao) //In�cio da sele��o do menu
	  {
	  	case 1: //chamada de fun��es
	  		registro();
		 	break;
		 	
		case 2:
		  	consulta();
		   	break;
		
		case 3:
		 	deletar();
		 	break;
		 	
		case 4:
			printf("Obrigado por utilizar o sistema!\n\n\n");
			return 0;
			break;
		 	
		default:	
		 	printf("Essa op��o n�o est� dispon�vel!\n\n\n");
		 	system("pause");
		 	break;
	  }
	 
	
	 printf("Projeto do curso de TI da EBAC.");
	//Fim da sele��o
   }
}
