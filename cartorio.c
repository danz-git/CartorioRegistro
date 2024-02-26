#include <stdio.h> //Comunicação com o Usuário
#include <stdlib.h> //Alocação de espaço de memória
#include <locale.h> //Alocação de txt por região
#include <string.h> //Biblioteca responsável pelas Strings


//Declaração das Funções:

int registro();
int consulta();
int deletar();


int main()
{
	int escolha; //Definição da variável para o menu (while e switch)
	
	setlocale(LC_ALL, "Portuguese");
	
	/*
	Foi escolhido a função While para criar um laço de repetição para a
	visualização do menu até que o usuário escolha a opção 9 (Saída).
	Dessa forma a função Switch	fica mais dinâmica.
	*/
	
	while (escolha != 9)
	{
		
		printf("\n### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada no Menu\n\n");
		printf("1 - Registrar nomes\n");
		printf("2 - Consultar nomes\n");
		printf("3 - Deletar nomes\n");
		printf("9 - Sair do Cartório de Registro\n");
		printf("Opção: ");
		
		scanf("%d", &escolha);
		
		system("cls"); //Comando que limpa a tela.
		
		switch (escolha)
		{
			
			case 1:
				//função registro
				escolha = registro();
				system("cls");
				break;
				
			case 2:
				//função consulta
				escolha = consulta();
				system("cls");
				break;
				
			case 3:
				//função delete
				escolha = deletar();
				system("cls");
				break;
				
			case 9:
				printf("\nFinalizando o Programa...\n");
				break;
				
			default:
				printf("Favor escolher uma opção vália...\n\n");
				system("pause");
				system("cls");
				break;
		}
	}
	
	
	printf("\n\nEste Software é de livre uso - Criado por Dan Gomes\n");
	return 0;
}


//Área para as funções.
//Abaixo da função Main para ficar mais organizado.

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Você selecionou a opção de Registro.\n\n");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobreNome[40];
	char cargo[40];
	
	int escolha; //Variável para retornar ao Menu ou para Finalizar o programa.
	
	printf("\nInforme o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Função Responsável por copiar o conteúdo de 'cpf' em 'arquivo'.
	
	FILE *file; //Acesse um 'FILE' (função) e crie um '*file'. Cria o arquivo no BD.
	file = fopen(arquivo, "w"); //Abrir o 'file' e escrever nele ('w') o conteúdo de 'arquivo'.
	
	fprintf(file,cpf); //Salva o valor da variável.
	fclose(file); //Fecha o arquivo.
	
	file = fopen(arquivo, "a"); //'a' atualiza a informação.
	fprintf(file, ";");
	fclose(file);
	
	printf("\nInforme o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //'a' atualiza a informação.
	fprintf(file, ";");
	fclose(file);
	
	printf("\ninforme o sobrenomes a ser cadastrado: ");
	scanf("%s", sobreNome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobreNome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //'a' atualiza a informação.
	fprintf(file, ";");
	fclose(file);
	
	printf("\nInforme o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	system("cls");
	
	
	//Sistema para verificar se o usuário deseja que o programa retorne ao menu
	//ou se deseja finalizar a aplicação:
	
	while (escolha != 9 || escolha != 0)
	{
		printf("\nDejesa continuar?\n\n");
		printf("Digite [0] para Retornar ao Menu ou [9] para Encerrar o Programa: ");
		scanf("%d", &escolha);
		
		switch (escolha)
		{
			case 9:
				printf("\n\nFinalizando o Programa...\n\n");
				system("pause");
				system("cls");
				return 9;
				break;
				
			case 0:
				printf("\n\nRetornando ao menu...\n\n");
				system("pause");
				system("cls");
				return;
				break;
			
			default:
				printf("\n\nFavor escolher uma opção válida...\n");
				system("pause");
				system("cls");
		}
	}
}



int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Você selecionou a opção de Consulta.\n\n");
	
	char cpf[40];
	char conteudo[200];
	
	int escolha; //Variável para retornar ao Menu ou para Finalizar o programa.
	
	printf("\nInforme o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Consulta. 'r' = Read.
	
	if (file == NULL)
	{
		printf("\nUsuário não encontrado...\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Escreve a informação até que não seja mais Nulo.
	{
		printf("\nEssas são as informações do Usuário informado: ");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
	
	system("cls");
	
	
	//Sistema para verificar se o usuário deseja que o programa retorne ao menu
	//ou se deseja finalizar a aplicação:
	
	while (escolha != 9 || escolha != 0)
	{
		printf("\nDejesa continuar?\n\n");
		printf("Digite [0] para Retornar ao Menu ou [9] para Encerrar o Programa: ");
		scanf("%d", &escolha);
		
		switch (escolha)
		{
			case 9:
				printf("\n\nFinalizando o Programa...\n\n");
				system("pause");
				system("cls");
				return 9;
				break;
				
			case 0:
				printf("\n\nRetornando ao menu...\n\n");
				system("pause");
				system("cls");
				return;
				break;
			
			default:
				printf("\n\nFavor escolher uma opção válida...\n");
				system("pause");
				system("cls");
		}
	}
}



int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Você selecionou a opção de Delete.\n\n");
	
	char cpf[40];
	
	int escolha; //Variável para retornar ao Menu ou para Finalizar o programa.
	
	printf("\nInforme o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nUsuário não se encontra no sistema.\n\n");
		system("pause");
	}
	
	fclose(file);
	
	if (remove(cpf) == 0)
	{
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
	}
	else
	{
		printf("\nErro ao deletar o Usuário...\n\n");
		system("pause");
	}
	
	system("cls");
	
	
	//Sistema para verificar se o usuário deseja que o programa retorne ao menu
	//ou se deseja finalizar a aplicação:
	
	while (escolha != 9 || escolha != 0)
	{
		printf("\nDejesa continuar?\n\n");
		printf("Digite [0] para Retornar ao Menu ou [9] para Encerrar o Programa: ");
		scanf("%d", &escolha);
		
		switch (escolha)
		{
			case 9:
				printf("\n\nFinalizando o Programa...\n\n");
				system("pause");
				system("cls");
				return 9;
				break;
				
			case 0:
				printf("\n\nRetornando ao menu...\n\n");
				system("pause");
				system("cls");
				return;
				break;
			
			default:
				printf("\n\nFavor escolher uma opção válida...\n");
				system("pause");
				system("cls");
		}
	}
}
