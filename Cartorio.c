#include <stdio.h> //biblioteca de comunica��o com o �su�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca repons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar usu�rios no sitema
{
	// inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores da string
	
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
		printf("N�o foi possivel, n�o foi localizado\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main()
   {
        setlocale (LC_ALL, "Portuguese");
        
	    int opcao =0; //Definindo vari�veis
	    int laco=1;
	    char senhadigitada[10]="a";
	    int comparacao;


	    printf("###Cart�rio da EBAC###\n\n");
	    printf("Login de administrador!\n\nDigite sua senha: ");
	    scanf("%s", senhadigitada);
	
	    comparacao = strcmp(senhadigitada, "admin");
	
	   if(comparacao == 0)
	   {
	   	    system("cls");
            for(laco=1;laco=1;)
            {
	            setlocale(LC_ALL,"Portuguese"); //Definido a linguagem
   
                printf("###Cart�rio da EBAC###\n\n"); //Inicio do menu
                printf("Escolha a op��o desejada do menu:\n\n");
                printf("\t1 - Registrar nomes\n");
                printf("\t2 - Consultar nomes\n");
                printf("\t3 - Deletar nomes\n\n"); 
                printf("\t4 - Sair do sistema\n\n"); 
	            printf("Op��o:"); //Fim do menu
         
                scanf("%d", &opcao); // Armazenando a escolha do usu�rio
    
                system("cls"); // respons�vel por limpar a tela
        
                switch(opcao) //inicio da sele��o de menu
			    {
                    case 1:
                    registro(); //chamada de fun��es
		            break;
			
		            case 2:
		            consulta();
		            break;
			
		            case 3:
	                deletar();
		            break;
    	    
    	            case 4:
    	            printf("Obrigado por ultilizar o sistema!\n");
	                return 0;
    	            break;
		    	    
                    default:
                    printf("Essa op��o n�o est� disponivel\n");
	                system("pause");
    	            break;
                } //fim da sele��o
           }  
    	}
	    else
	    printf("Senha incorreta!");
    }
           


