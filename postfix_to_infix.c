/*
FILE NAME: postfix_to_infix.c
AUTHOR NAME: Karan Rathi
DATE: 9/11/2017
AIM: Write a C program to convert a postfix expression into its equivalent infix expression( with proper paranthesization)
*/ 

//HEADER FILES//  
    #include <stdio.h>
    #include <stdlib.h>
    #include<string.h>
    #include<ctype.h>
    
 
    
//NODE STRUCTURE//        
    struct node
    {
        char b1;
        char b2;
    	char ch;
    	struct node *next;
    	struct node *prev;
    }  *stack[51];
    typedef struct node node;

   int top = 50;     
    void push(node *str)
    {
    	if (top <= 0)
    	printf("Stack is Full \n");
    	else
    	{
    		stack[top] = str;
    		top--;
    	}
    	
    }
     
    node *pop()
    {
    	node *exp;
    	if (top >= 50)
    		printf("Stack is Empty \n");
    	else
    	{
    	    
    		exp = stack[++top];
    	}
    	return exp;
    }
    void convert(char post[])
    {
    	node *op1,  *op2;
    	node *temp;
    	int i;
    	for (i=0;post[i]!='\0';i++)
    	if (post[i] >= 'a'&& post[i] <= 'z'|| post[i] >= 'A' && post[i] <= 'Z')
    	{
    		temp = (node*)malloc(sizeof(node));
    		temp->ch = post[i];
    		temp->next = NULL;
    		temp->prev = NULL;
    		temp->b1=0;
    		temp->b2=0;
    		push(temp);
    	}
    	else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^')
    	{
    		op1 = pop();
    		op2 = pop();
    		temp = (node*)malloc(sizeof(node));
    		temp->ch = post[i];
    		temp->next = op1;
    		temp->prev = op2;
    		temp->b1='(';
    		temp->b2=')';
    		push(temp);
    	}
    }
     
    void display(node *temp)
    {
    	if (temp != NULL)
    	{
    	    printf("%c",temp->b1);
    		display(temp->prev);
    		printf("%c", temp->ch);
    		display(temp->next);
    		printf("%c",temp->b2);
    	}
    }
    char operator(char op)
    {
	if(op=='+' || op=='-' || op=='/' || op=='*' || op=='^')
		return op;
	else 
		return 0;
    }

    int count(char post[])
    {
    int i,check=0;
    for(i=0;i<strlen(post);i++)
    {
        if(isalpha(post[i]))
            check++;
        else
            check--;
    }
    if(check==1)
        return 1;
    else
        return 0;
    }

    int validexp(char post[])
    {
    int l,i=0,flag=0;
	l=strlen(post);
	while(post[i]!='\0')
	{
	    if(post[0]==operator(post[0])){
		 	printf("\nfirst character is an operator");
		 	printf("\nInvalid exp\n");
		 	break;
		 }
	    else if(post[1]=='\0'){
	 	 	printf("\nsingle character expression");
	 	 	printf("\nInvalid exp\n");
	 	 	break;
		 }
		 else if(isalpha(post[l-1])){
	 	 		printf("\nLast character is an operand");
	 	 		printf("\nInvalid exp\n");
	 	 		break;
	 	 }
	 	 else if(!(isalpha(post[0]) && isalpha(post[1]))){
	 	        printf("\nFirst two characters are not operand");
	 	        printf("\nInvalid exp\n");
	 	        break;
	 	 }
	 	 else if(!(count(post))){
	 	        printf("\nInvalid exp");
	 	        break;
	 	 }
	 	 else
	 	 {
	 	    flag=1;
	 	    printf("\nValid expression\n");
	 	    break;
	 	    
	 	 }
	 	 ++i;
	}
    return flag;
} 	 

//DRIVER FUNCTION

    void main()
    {
    	char post[50];
    	int temp=1,choice,top=50;
    	do{
    	    printf("\n------------------Postfix to Infix------------------\n");
    	    printf("1.Conversion\t0.Exit\n\n");
    	    printf("Enter the operation to perform:: ");
    	    scanf("%d",&choice);
    	    switch(choice)
    	    {
    	        case 0: temp=0;
    	                printf("You have opted to exit..\n");
    	                break;
    	        
    	        case 1: printf("Enter the postfix expression :");
    	                scanf("%s", post);
    	                
			                //printf("\nINVALID INFIX EXPRESSION\n\n");
                        if((validexp(post)==1))
                        {
                            convert(post);                                        
    	                    printf("\nThe Equivalant Infix expression is:");
    	                    display(pop());
    	                    printf("\n\n");
                        }
                        break;
                default:printf("Invalid input\n");
                        break;
            }
            }while(temp!=0);
    }
    
    
/*OUTPUT::


------------------Postfix to Infix------------------
1.Conversion	0.Exit

Enter the operation to perform:: 1
Enter the postfix expression :ab+

Valid expression

The Equivalant Infix expression is:(a+b)


------------------Postfix to Infix------------------
1.Conversion	0.Exit

Enter the operation to perform:: 1
Enter the postfix expression :ab+cd-/*ef

Last character is an operand
Invalid exp

------------------Postfix to Infix------------------
1.Conversion	0.Exit

Enter the operation to perform:: 1
Enter the postfix expression :ABC*DEF^/G*-H*+

Valid expression

The Equivalant Infix expression is:(A+(((B*C)-((D/(E^F))*G))*H))


------------------Postfix to Infix------------------
1.Conversion	0.Exit

Enter the operation to perform:: 0
You have opted to exit..


*/    
