//RK4

#include<stdio.h>
float funcao(float a,float b){
    float f;
    f=1-a+4*b;
    return f;
}

float rk4(float x,float y,float h,int n){
    int i=1;
    float k1,k2,k3,k4;
    while(i<=n){
        k1=funcao(x,y);
        k2=funcao((x+h/2),(y+(h/2)*k1));
        k3=funcao((x+h/2),(y+(h/2)*k2));
        k4=funcao((x+h),(y+h*k3));
        y=y+(h/6)*(k1+2*k2+2*k3+k4);
        i=i+1;
    }
   return y;
}



int main(){
    int n;
    float y,h,x;
    printf("Digite x0:");
    scanf("%f",&x);
    printf("Digite y(0):");
    scanf("%f",&y);
    printf("Digite h:");
    scanf("%f",&h);
    printf("Digite o numero de interacoes:");
    scanf("%d",&n);
    printf("y[%d]=%f",n,rk4(x,y,h,n));

    return 0;
}
