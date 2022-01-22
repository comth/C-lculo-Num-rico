//Jacobi

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define t 50
//esse programa calcula sitemas lineares at� t vari�veis,inicialmente, 
//define t como 50, mas para calcular um sistema maior basta modificar
// o valor de t no define acima.
int main(){
	int i,j,v,d;
	float a[t][t],x[t],b[t],aux[t],auxx[t],erro,e,maiore,maiorx,auxe[t];
	//preenchi a matriz e alguns vetores com 0, para n�o ocorrerem erros.
	for(i=0;i<t;i++){
		for(j=0;j<t;j++)
			a[i][j]=0;
	}
	for(i=0;i<t;i++){
		auxe[i]=0;
		x[i]=0;
	}

    //coleta de dados
    printf("GAUSS-JACOBI");
	printf("\nQuantas variaveis deseja calcular:");
	scanf("%d",&v);
	if(v>t){
		printf("\nEsse programa calcula sistemas ate %d variaveis!\n",t);
		exit(0);	
	}
	printf("Digite a precisao desejada:");
	scanf("%f",&erro);
	for(i=0;i<v;i++){
		printf("Digite o valor da aproximacao inicial de x%d:",i+1);
		scanf("%f",&x[i]);
	}
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("Digite a[%d][%d]:",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
		
	}
	for(i=0;i<v;i++){
		printf("Digite o valor de b[%d]:",i+1);
		scanf("%f",&b[i]);
	}

    //processamento
    e=100;
    while(e>erro){
    	//todos os vetores que come�am com aux s�o vetores auxiliares
		//(usei para facilitar o processamento).
    	for(d=0;d<v;d++){
                auxx[d]=x[d];
		}
		//processo interativo:
		for(i=0;i<v;i++){
			aux[i]=b[i];
			for(j=0;j<v;j++){
				if(i==j){
					
				}
				if(i!=j){
					aux[i]=aux[i]-(a[i][j]*auxx[j]);	   	
				}	
			}
			x[i]=(1/a[i][i])*(aux[i]);
		}
		//c�lculo do erro:
        for(i=0;i<v;i++){
            auxe[i]=fabs(x[i]-auxx[i]);
        }
        maiore=auxe[0];
        for(i=1;i<v;i++){
            if(maiore<auxe[i+1]) maiore=auxe[i+1];
        }
    	maiorx=x[0];
        for(i=1;i<v;i++){
            if(maiorx<x[i+1]) maiorx=x[i+1];
        }
        e=maiore/maiorx;

	}
	
	//resultados:
	for(i=0;i<v;i++){
        printf("\n x[%d]=%f",i+1,x[i]);
	}

	return 0;
}