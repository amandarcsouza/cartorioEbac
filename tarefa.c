#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // Busca na biblioteca e cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo. O "w" significa escrever
	fprintf(file,cpf); // Escreve e salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,","); // Coloca v�rgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,nome); // Escreve e salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,sobrenome); // Escreve e salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,cargo); // Escreve e salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
    system("pause");
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Definindo as vari�veis
	char conteudo[100];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser consultado: "); //Coletando as informa��es do usu�rio
	scanf("%s",cpf);
  	
	FILE *file; //Busca na biblioteca e cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo
  	
	if(file == NULL) //Caso o valor digitado pelo usu�rio for inexistente
	{
		printf("Arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL) //Caso o valor digitado pelo usu�rio existir
	{
		printf("\nEssas s�o as informa��es do usu�rio: \nCPF: ", cpf, "\nNome: ", nome, "\nSobrenome: ", sobrenome, "\nCargo: ", cargo ); //Mostra as informa��es ao usu�rio
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system("pause");
	fclose(file); //Fecha o arquivo consultado
}

int deletar ()
{
	char cpf[40]; //Definindo vari�veis
	
	printf("Digite o CPF do cadastro a ser deletado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //Busca na biblioteca e cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo
	
	if(file == NULL) //Caso o valor digitado pelo usu�rio for inexistente
	{
		printf("Cadastro n�o encontrado!\n");
		system("pause");
	}
	else //Caso o valor digitado pelo usuario existir
		fclose(file);
		remove(cpf);
		printf("Cadastro deletado com sucesso!\n");
		system("pause");
} 

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
		{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");	
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("Op��o: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls"); //respons�vel por limpar a tela
			
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
				registro (); //chamada de fun��es
				break;
				
				case 2:
				consulta ();
				break;
				
				case 3:
				deletar ();
				break;
				
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");	
				break;	
			} //fim da sele��o
		}
	}
