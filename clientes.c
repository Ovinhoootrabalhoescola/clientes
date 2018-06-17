#include <stdio.h>
#include <conio.h>
#include <string.h>



void menu() {
	
  system("cls");
  printf("========== Menu ================\n");
  printf("1 - Inserir\n");
  printf("2 - Alterar\n");
  printf("3 - Excluir\n");
  printf("4 - Consultar\n");
  printf("5 - Sair\n");
  printf("Digite a opcao desejada: ");
	
	
}
 
int main()
{
	
	
  	
  struct pessoa {
  	char nome[50], rua[70], bairro[100],estado[120];
    int idade;
  	int ativo;
  	int rg;
  	int cpf;
  	int telefone; 
  	int cep;
  };	
	
	
  FILE *pont_arq;
  char texto_str[250];
  char* token;
  
  struct pessoa A[200];
  int i = 0,op;
  int x = 0,j,pos;
  
  
  pont_arq = fopen("clientes.txt", "r");
 
  
  while(fgets(texto_str, 250, pont_arq) != NULL) {
  	
  	
	token = strtok(texto_str, "@");
    
    while (token != NULL) {
        
      if (x == 0)   {
	  
        strcpy(A[i].nome,token);
        x++;
      } else if (x == 1) {
      	
      	A[i].idade = atoi(token); 
        x++;
	  } else if (x == 2) {
      	
      	A[i].telefone = atoi(token); 
        x++;
	  } else if (x == 3) {
      	
      	strcpy(A[i].rua,token);
        x++;
	  } else if (x == 4) {
      	
      	strcpy(A[i].bairro,token);
        x++;
	  } else if (x == 5) {
      	
      	strcpy(A[i].estado,token);
        x++;
	  } else if (x == 6) {
      	
      	A[i].rg = atoi(token); 
        x++;
	  } else if (x == 7) {
      	
      	A[i].cpf = atoi(token); 
        x++;
	  } else if (x == 8) {
      	
      	A[i].cep = atoi(token); 
        x++;
	  }
	  
	
	  else if (x == 3) {
	  	
      	A[i].ativo = atoi(token);
        x++;
	  }
        token = strtok(NULL, "@"); 
       
    }
     x=0; 
     i++; 
}
  
  fclose(pont_arq);
  
  menu(); 
  scanf("%d",&op);
  
  while (op != 5) {
  	
  	
  	switch(op) {
  		case 1:
  			printf("Nome ...: ");
  			scanf("%s",&A[i].nome);
  			
  			printf("Idade ...: ");
  			scanf("%d",&A[i].idade);
  			
  			printf("Telefone ...: ");
  			scanf("%d",&A[pos].telefone);
  			
  			printf("rua ...: ");
  			scanf("%s",&A[pos].rua);
  			
  			printf("bairro ...: ");
  			scanf("%s",&A[pos].bairro);
  			
  			printf("estado ...: ");
  			scanf("%s",&A[pos].estado);
  			
  			printf("rg ...: ");
  			scanf("%d",&A[pos].rg);
  			
  			printf("cpf ...: ");
  			scanf("%d",&A[pos].cpf);
  		
  		    printf("cep ...: ");
  			scanf("%d",&A[pos].cep);
  			
  			
  			A[i].ativo=1;
  			i++;
  			
  			
  		break;
  		case 2:
  			printf("Digite o codigo do registro: ");
  			scanf("%d",&pos);
  			
  			printf("\n%s - %d - %d - %s - %s - %s -  %d - %d - %lf - %d\n\n", A[pos].nome, A[pos].idade, A[pos].telefone, A[pos].rua, A[pos].bairro,A[pos].estado, A[pos].rg, A[pos].cpf, A[pos].cep);
  			
  			printf("Nome ...: ");
  			scanf("%s",&A[pos].nome);
  			
  			printf("Idade ...: ");
  			scanf("%d",&A[pos].idade);
  			
  			printf("Telefone ...: ");
  			scanf("%d",&A[pos].telefone);
  			
  			printf("rua ...: ");
  			scanf("%s",&A[pos].rua);
  			
  			printf("bairro ...: ");
  			scanf("%s",&A[pos].bairro);
  			
  			printf("estado ...: ");
  			scanf("%s",&A[pos].estado);
  			
  			printf("rg ...: ");
  			scanf("%d",&A[pos].rg);
  			
  			printf("cpf ...: ");
  			scanf("%d",&A[pos].cpf);
  			
  			printf("cep ...: ");
  			scanf("%d",&A[pos].cep);
  			
  			
  		
  			
  		break;
  		case 3:
  			printf("Digite o codigo do clientes: ");
  			scanf("%d",&pos);
  			
  			A[pos].ativo=0;
  			
  			printf("clientes excluido!\n\n");
  			system("pause");
  			
  		break;
  		case 4:
  			printf("Digite o codigo do clientes: ");
  			scanf("%d",&pos);
  			printf("%s - %d - %d - %s - %s - %s - %d - %d - %d \n\n", A[pos].nome, A[pos].idade, A[pos].telefone, A[pos].rua, A[pos].bairro, A[pos].estado, A[pos].rg, A[pos].cpf, A[pos].cep);
  			system("pause");
  		break;
  		default:
  			printf("Opcao invalida!\n");
		break;    		
  		
	  }
  	
  	menu();
  	scanf("%d",&op);
  	
  	
  }
  
  
  pont_arq = fopen("clientes.txt", "w");
  
  for(j=0; j < i; j++) {
  	
    //if (A[j].ativo == 1){
	  	fprintf(pont_arq,"%s@%d@%d@%s@%s@%s@%d@%d@%d\n", A[j].nome, A[j].idade, A[j].telefone, A[j].rua, A[j].bairro, A[j].estado, A[j].rg, A[j].cpf, A[j].cep );
    //}
  }
  
  fclose(pont_arq);
  
  
  
 
  
}
