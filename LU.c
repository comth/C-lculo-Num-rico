//LU

#include<stdio.h>

int main(){
	printf("Fatoracao LU")
    int k,i,n,j,aux,aux1;
    printf("Quantidade de variaveis: ");
    scanf("%d",&n);

    float a[n][n],m[n][n];

    for(aux=0;aux<n;aux++){
        for(aux1=0;aux1<n;aux1++){
            printf("Valor a[%d][%d]: ",aux+1,aux1+1);
            scanf("%f",&a[aux][aux1]);
        }
    }

    for(aux=0;aux<n;aux++){
        for(aux1=0;aux1<n;aux1++){
            if(aux==aux1)
                m[aux][aux1] = 1.0;
            else
                m[aux][aux1] = 0.0;
        }
    }

    for(k=0;k<(n-1);k++){
        for(i=k+1;i<n;i++){
            m[i][k] = a[i][k]/a[k][k];
            for(j=k+1;j<n;j++)
                a[i][j] = a[i][j]-(m[i][k]*a[k][j]);
            a[i][k] = 0;
        }
    }

    printf("\n\n");

    printf("Matriz U:\n");
    for(aux=0;aux<n;aux++){
        for(aux1=0;aux1<n;aux1++){
            printf("\t%.3f",a[aux][aux1]);
        }
        printf("\n");
    }

    printf("Matriz L:\n");
    for(aux=0;aux<n;aux++){
        for(aux1=0;aux1<n;aux1++){
            printf("\t%.3f",m[aux][aux1]);
        }
        printf("\n");
    }

    printf("\n\n");
    
    return 0;

}
