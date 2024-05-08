#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das string
	
	FILE *file; // Busca na biblioteca e cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo. O "w" significa escrever
	fprintf(file,cpf); // Escreve e salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,","); // Coloca vírgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,nome); // Escreve e salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,sobrenome); // Escreve e salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file,cargo); // Escreve e salva o valor da variável
	fclose(file); // Fecha o arquivo
	
    system("pause");
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Definindo as variáveis
	char conteudo[100];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser consultado: "); //Coletando as informações do usuário
	scanf("%s",cpf);
  	
	FILE *file; //Busca na biblioteca e cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo
  	
	if(file == NULL) //Caso o valor digitado pelo usuário for inexistente
	{
		printf("Arquivo não localizado!\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL) //Caso o valor digitado pelo usuário existir
	{
		printf("\nEssas são as informações do usuário: \nCPF: ", cpf, "\nNome: ", nome, "\nSobrenome: ", sobrenome, "\nCargo: ", cargo ); //Mostra as informações ao usuário
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system("pause");
	fclose(file); //Fecha o arquivo consultado
}

int deletar ()
{
	char cpf[40]; //Definindo variáveis
	
	printf("Digite o CPF do cadastro a ser deletado: "); //Coletando informações do usuário
	scanf("%s",cpf);
	
	FILE *file; //Busca na biblioteca e cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo
	
	if(file == NULL) //Caso o valor digitado pelo usuário for inexistente
	{
		printf("Cadastro não encontrado!\n");
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
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
		{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //Início do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");	
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("Opção: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usuário
	
			system("cls"); //responsável por limpar a tela
			
			switch(opcao) //inicio da seleção do menu
			{
				case 1:
				registro (); //chamada de funções
				break;
				
				case 2:
				consulta ();
				break;
				
				case 3:
				deletar ();
				break;
				
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");	
				break;	
			} //fim da seleção
		}
	}
