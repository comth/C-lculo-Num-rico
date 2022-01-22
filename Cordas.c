//MÉTODO DAS CORDAS

#include <stdio.h>
#include <math.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL,"Portuguese");
	int i,g;
	double a,fa,b,fb,c[11],e,erro,x,fx,xnovo,fxnovo;
	printf("MÉTODO DAS CORDAS \nEsse algorítimo calcula a raíz de um polinômio até grau 10 contida num intervalo definido por a e b.\n\n");
	//por causa do set locale, na hora de fornecer os números é necessário usar vígula no lugar do ponto.
	// exemplo: digite 2,5 ao invés de 2.5.
	printf("Digite o valor de a:");
	scanf("%lf",&a);
	printf("Digite o valor de b:");
	scanf("%lf",&b);
	printf("Digite o valor do erro:");
	scanf("%lf",&e);
	printf("Digite o grau do polinômio:");
	scanf("%d",&g);	
	if (g<=10){
		i=0;
		//definindo o polinômio
		while (i<=g){
			printf("Digite o valor de a%d:",i);
			scanf("%lf",&c[i]);
			//printf("O valor de a%d eh %lf",i,c[i]);
			i=i+1;		
		}
		//calculando f(a) e f(b)
		i=0;
		fa=0;
		while (i<=g){
			fa=fa+(c[i]*pow(a,i));
			//printf("\nO valor de f(a) eh %lf",fa);
			i=i+1;	
		}
		i=0;
		fb=0;
		while (i<=g){
			fb=fb+(c[i]*pow(b,i));
			//printf("\nO valor de f(b) eh %lf",fb);
			i=i+1;	
		}
		x=((a*fb)-(b*fa))/(fb-fa);
		//printf("O valor de x eh: %lf",x);
		i=0;
		fx=0;
		while (i<=g){
			fx=fx+(c[i]*pow(x,i));
			//printf("\nO valor de f(x) eh %lf",fx);
			i=i+1;	
		}
		erro=b-a;
		xnovo=x;
		fxnovo=fx;
		while(erro>e){
			if(fxnovo==0)
				printf("A raiz é:%lf",x);
			if(fa*fxnovo<0){
				a=a;
				b=xnovo;
				i=0;
				fa=0;
				while (i<=g){
					fa=fa+(c[i]*pow(a,i));
					//printf("\nO valor de f(a) eh %lf",fa);
					i=i+1;	
				}
				i=0;
				fb=0;
				while (i<=g){
					fb=fb+(c[i]*pow(b,i));
					//printf("\nO valor de f(b) eh %lf",fb);
					i=i+1;	
				}
			}
			else{
				a=xnovo;
				b=b;
				i=0;
				fa=0;
				while (i<=g){
					fa=fa+(c[i]*pow(a,i));
					//printf("\nO valor de f(a) eh %lf",fa);
					i=i+1;	
				}
				i=0;
				fb=0;
				while (i<=g){
					fb=fb+(c[i]*pow(b,i));
					//printf("\nO valor de f(b) eh %lf",fb);
					i=i+1;	
				}
			}
			x=xnovo;
			xnovo=((a*fb)-(b*fa))/(fb-fa);
			//printf("O valor de xnovo eh: %lf",xnovo);
			i=0;
			fxnovo=0;
			while (i<=g){
				fxnovo=fxnovo+(c[i]*pow(xnovo,i));
				//printf("\nO valor de f(xnovo) eh %lf",fxnovo);
				i=i+1;	
			}
			erro=xnovo-x;
			erro=fabs(erro);
			//printf("O erro é: %lf",erro);
		}
		printf("\nA raiz é: %lf",xnovo);
		
	}
	else printf("O grau do polinômio é muito alto! \nEsse algorítimo só calcula polinômios até grau 10.");
		
	return 0;
}