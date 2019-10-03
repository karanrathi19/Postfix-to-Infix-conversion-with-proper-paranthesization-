#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct stack
{
int top;
char a[20];
};


char pop(struct stack *p){
    if(p->top==-1)
    {
        printf("\nInvalid postfix expression");exit(0);
    }
return(p->a[p->top--]);
}



void push(struct stack *p,char ch)
{
p->a[++p->top]=ch;
}

char givetopel(struct stack *p)
{
    return p->a[p->top];
}


int givetopval(struct stack *p)
{
    return p->top;
}

int prior(char ch){

switch(ch){
case '+':return 1;
case'-':return 1;
case '*':return 2;
case '/':return 2;
case '^':return 3;
default:return 0;
}

}


void main(){

struct stack p;
p.top=-1;

char e[20],r[20];

scanf("%s",e);

char ch;
int i=0;
int k=-1;
while((ch=e[i])!='\0')
    {
        if(isalnum(ch))
        {
            r[++k]=ch;
        }
        else if(ch=='(')
        {
            push(&p,ch);
        }
        else if(ch==')')
        {
            while(givetopel(&p)!='(' && givetopval(&p)>-1)
        {
                r[++k]=pop(&p);

        }
            if(givetopel(&p)!='(')
           {
                printf("error missing (\n");return;
           }
        else
        {
            pop(&p);
        }
        }

    else{
        while(prior(givetopel(&p))>=prior(ch))
        {
            r[++k]=pop(&p);
        }
        push(&p,ch);
        }
    i++;

}
while(givetopval(&p)>-1)
{
    r[++k]=pop(&p);
}
r[++k]='\0';
printf("result= %s",r);

}


