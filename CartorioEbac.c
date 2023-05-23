#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das sting

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); 
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa acessar
	fprintf(file, ","); //salva o valor "," 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa acessar
	fprintf(file, nome);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa acessar
	fprintf(file, ",");//salva o valor ","
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informações do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa acessar
	fprintf(file, sobrenome);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa acessar
	fprintf(file, ",");//salva o valor ","
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informações do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//cria o arquivo e o "a" significa acessar
	fprintf(file, cargo);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//inicio da criação das variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação das variáveis/string
	
	printf("Digite o CPF a ser consultado: ");//coletando informações do usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n\n");
	}	
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF de usuário não registrado!\n");
		system("pause");
	}
	

}



int main()
{
	int opcao=0; //defenindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{ 
		
		system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	
		printf("####Cartório da EBAC ####\n\n"); //inicio do menu
		printf("Escolha a opção desejado do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
		
	
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consultar(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break; 
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;	 //fim da seleção
		
		}
	
	}
}
