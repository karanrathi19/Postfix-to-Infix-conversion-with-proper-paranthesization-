# Prefix-to-Infix-conversion-with-proper-paranthesization-

Postfix: An expression is called the postfix expression if the operator appears in the expression after the operands. Simply of the form (operand1 operand2 operator).

Infix : The expression of the form a op b. When an operator is in-between every pair of operands.

# Implementation:

I have implemented postfix to infix conversion(with proper paranthesization) using Stack.

# Algorithm:

1. While there are input symbol left
2.  	Read the next symbol from input
3.		If the symbol is an operand 
          PUSH it onto the stack.
4.		Otherwise,
			    the symbol is an operator.
5.		If there are fewer than two values on the stack
          error “input not sufficient values in the expression”.
6.		Else
			    POP the top 2 values from the stack.
			    Put the operator ,with the values as argument and  
          form a string.(value1  operator  value2)
			    Encapsulate the resulted string with the parenthesis.
			    PUSH the resulted string back to stack.       
7.  	If there is only one value in the stack
			    That value in the stack is the desired INFIX string.
8.		If there are more values in the stack
			    Error”the user input has too many values”.
