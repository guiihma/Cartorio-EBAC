#include <stdio.h> //biblioteca de comunicação com o úsuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca reponsável por cuidar das string

int registro() //Função responsável por cadastrar usuários no sitema
{
	// inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivon e o "w" signifia escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //atualiza o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser Cadastrado:");
	scanf("%s", nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser Cadastrado:");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s", cargo);
    
    file=fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definido a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("Não foi possivel, não foi localizado\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
	printf("O usuário não se encontra no sistema!\n");
	system("pause");
	}
}

int main()
{
    int opcao=0; //Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {	
    	system("cls");
    	
	setlocale(LC_ALL,"Portuguese"); //Definido a linguagem
   
        printf("###Cartório da EBAC###\n\n"); //Inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n"); 
        printf("\t4 - Sair do sistema\n\n"); 
	printf("Opção:"); //Fim do menu
         
        scanf("%d", &opcao); // Armazenando a escolha do usuário
    
        system("cls"); // responsável por limpar a tela
        
        switch(opcao) //inicio da seleção de menu
        {
        case 1:
        registro(); //chamada de funções
	break;
			
	case 2:
	consultar();
	break;
			
	case 3:
	deletar();
	break;
    	    
        case 4:
    	printf("Obrigado por ultilizar o sistema!\n");
    	return 0;
    	break;
    	    
        default:
        printf("Essa opção não está disponivel\n");
	system("pause");
    	break;
	}//fim da seleção
    }   
}

