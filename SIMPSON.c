//PRIMEIRA E SEGUNDA REGRA DE SIMPSON 

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define t 50
float primeira(float a,float e,int n){
    int i;
    float y[t],se,si,sp;
    for(i=0;i<=n;i++){
            //função
            y[i]=1/a;
            a=a+e;
    }
    se=y[0]+y[n];
    sp=0;
    si=0;
    for(i=1;i<n;i++){
        if((i%2)!=1) sp=sp+y[i];
        if((i%2)==1) si=si+y[i];
    }

    return((e/3)*(se+4*si+2*sp));
}


float segunda(float a,float e,int n){
    int i;
    float y[t];
    for(i=0;i<=n;i++){
        //função
        y[i]=1/a;
        a=a+e;
    }

    return(((3/8)*e)*(y[0]+3*y[1]+3*y[2]+y[3]));
}



int main(){
    int n,auxn;
    float li,ls,h,e,integral,auxls;
    //entrada de dados
    printf("Digite o limite inferior:");
    scanf("%f",&li);
    printf("Digite o limite superior:");
    scanf("%f",&ls);
    printf("Digite o numero de intervalos:");
    scanf("%d",&n);
    if(n>=t){
        printf("Esse so funciona com até %d intervalos!",t);
        exit(0);
    }
    //para n ímpar
    if((n%2)==1){
        h=(ls-li)/n;
        auxls=ls;
        ls=h*3;
        auxn=n;
        n=3;
        integral=segunda(li,h,n);
        li=ls;
        ls=auxls;
        n=auxn-3;
        integral=integral+primeira(li,h,n);
        printf("I=%f",integral);
    }
    else{
        h=(ls-li)/n;
        integral=primeira(li,h,n);
        printf("I=%f",integral);
    }

return 0;
}
