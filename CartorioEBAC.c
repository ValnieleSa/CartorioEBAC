#include <stdio.h> //biblioteca de comunicação
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletanto informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file,","); //Adicina uma vígula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //"a" = atualizar
	fprintf(file,nome); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file,","); //Adciona uma vígula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file, sobrenome); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file,","); //Adicona uma vígula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cargo); //"%s" refere-se a string
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file, cargo); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa na tela
}

int consulta() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	//Início da criação de variáveis/string
	char cpf[40];
	char conteudo [200];
	//Final da criação de variáveis/string
	
	printf("Digite o cpf a ser consultado: "); //Consultando informaçãos do usuário
	scanf("%s",cpf); //"%s" refere-se as strings
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
	
	if(file == NULL) //Função para informações não existentes no sistema
	{
		printf("Arquivo não localizado! \n"); //Informa a inexistência do usuário
	}
	
	while(fgets(conteudo, 200, file)!=NULL); //Informações consultadas do usuário
	{
		printf("\n\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausa na tela
}

int deletar() //Função responsável por deletar os usuários no sistema
{
	//Início da criação de variáveis/string
	char cpf[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser deletado: "); //Consultando informaçãos do usuário a serem deletadas
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo e o "r" significa ler
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0;//Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	
	 system("cls");
	
	 setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	 printf("### Cartório da EBAC ###\n\n");//Início do menu
	 printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n");
	  printf("\t4 - Sair do sistema\n\n\n");
	  printf("Opção:");//Fim do menu
	 
	  scanf("%d", &opcao);
	 
	  system("cls"); //Responsável por limpar a tela
	 
	  switch(opcao) //Início da seleção do menu
	  {
	  	case 1: //chamada de funções
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
		 	printf("Essa opção não está disponível!\n\n\n");
		 	system("pause");
		 	break;
	  }
	 
	
	 printf("Projeto do curso de TI da EBAC.");
	//Fim da seleção
   }
}
