#include <stdio.h> //Comunica��o com o Usu�rio
#include <stdlib.h> //Aloca��o de espa�o de mem�ria
#include <locale.h> //Aloca��o de txt por regi�o
#include <string.h> //Biblioteca respons�vel pelas Strings


//Declara��o das Fun��es:

int registro();
int consulta();
int deletar();


int main()
{
	int escolha; //Defini��o da vari�vel para o menu (while e switch)
	
	setlocale(LC_ALL, "Portuguese");
	
	/*
	Foi escolhido a fun��o While para criar um la�o de repeti��o para a
	visualiza��o do menu at� que o usu�rio escolha a op��o 9 (Sa�da).
	Dessa forma a fun��o Switch	fica mais din�mica.
	*/
	
	while (escolha != 9)
	{
		
		printf("\n### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada no Menu\n\n");
		printf("1 - Registrar nomes\n");
		printf("2 - Consultar nomes\n");
		printf("3 - Deletar nomes\n");
		printf("9 - Sair do Cart�rio de Registro\n");
		printf("Op��o: ");
		
		scanf("%d", &escolha);
		
		system("cls"); //Comando que limpa a tela.
		
		switch (escolha)
		{
			
			case 1:
				//fun��o registro
				escolha = registro();
				system("cls");
				break;
				
			case 2:
				//fun��o consulta
				escolha = consulta();
				system("cls");
				break;
				
			case 3:
				//fun��o delete
				escolha = deletar();
				system("cls");
				break;
				
			case 9:
				printf("\nFinalizando o Programa...\n");
				break;
				
			default:
				printf("Favor escolher uma op��o v�lia...\n\n");
				system("pause");
				system("cls");
				break;
		}
	}
	
	
	printf("\n\nEste Software � de livre uso - Criado por Dan Gomes\n");
	return 0;
}


//�rea para as fun��es.
//Abaixo da fun��o Main para ficar mais organizado.

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Voc� selecionou a op��o de Registro.\n\n");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobreNome[40];
	char cargo[40];
	
	int escolha; //Vari�vel para retornar ao Menu ou para Finalizar o programa.
	
	printf("\nInforme o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Fun��o Respons�vel por copiar o conte�do de 'cpf' em 'arquivo'.
	
	FILE *file; //Acesse um 'FILE' (fun��o) e crie um '*file'. Cria o arquivo no BD.
	file = fopen(arquivo, "w"); //Abrir o 'file' e escrever nele ('w') o conte�do de 'arquivo'.
	
	fprintf(file,cpf); //Salva o valor da vari�vel.
	fclose(file); //Fecha o arquivo.
	
	file = fopen(arquivo, "a"); //'a' atualiza a informa��o.
	fprintf(file, ";");
	fclose(file);
	
	printf("\nInforme o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //'a' atualiza a informa��o.
	fprintf(file, ";");
	fclose(file);
	
	printf("\ninforme o sobrenomes a ser cadastrado: ");
	scanf("%s", sobreNome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobreNome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //'a' atualiza a informa��o.
	fprintf(file, ";");
	fclose(file);
	
	printf("\nInforme o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	system("cls");
	
	
	//Sistema para verificar se o usu�rio deseja que o programa retorne ao menu
	//ou se deseja finalizar a aplica��o:
	
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
				printf("\n\nFavor escolher uma op��o v�lida...\n");
				system("pause");
				system("cls");
		}
	}
}



int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Voc� selecionou a op��o de Consulta.\n\n");
	
	char cpf[40];
	char conteudo[200];
	
	int escolha; //Vari�vel para retornar ao Menu ou para Finalizar o programa.
	
	printf("\nInforme o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Consulta. 'r' = Read.
	
	if (file == NULL)
	{
		printf("\nUsu�rio n�o encontrado...\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Escreve a informa��o at� que n�o seja mais Nulo.
	{
		printf("\nEssas s�o as informa��es do Usu�rio informado: ");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
	
	system("cls");
	
	
	//Sistema para verificar se o usu�rio deseja que o programa retorne ao menu
	//ou se deseja finalizar a aplica��o:
	
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
				printf("\n\nFavor escolher uma op��o v�lida...\n");
				system("pause");
				system("cls");
		}
	}
}



int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Voc� selecionou a op��o de Delete.\n\n");
	
	char cpf[40];
	
	int escolha; //Vari�vel para retornar ao Menu ou para Finalizar o programa.
	
	printf("\nInforme o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nUsu�rio n�o se encontra no sistema.\n\n");
		system("pause");
	}
	
	fclose(file);
	
	if (remove(cpf) == 0)
	{
		printf("\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	else
	{
		printf("\nErro ao deletar o Usu�rio...\n\n");
		system("pause");
	}
	
	system("cls");
	
	
	//Sistema para verificar se o usu�rio deseja que o programa retorne ao menu
	//ou se deseja finalizar a aplica��o:
	
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
				printf("\n\nFavor escolher uma op��o v�lida...\n");
				system("pause");
				system("cls");
		}
	}
}
