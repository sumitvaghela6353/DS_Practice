//Write a program to evaluate a prefix expression.

#include<stdio.h>
#include<string.h>

int isOperand(char);
int evaluate(char[]);
void push(int);
int pop();

int stack[20];
int top=-1;

int main()
{
	char pre[20];
	int res;

	printf("Enter Prefix expression : ");
	gets(pre);

	printf("Input expression : %s \n", pre);
	res = evaluate(pre);
	printf("Result is : %d \n", res);

	return 0;
}

int evaluate(char exp[])
{
	int j;
	for(j=strlen(exp)-1 ; j>=0 ; j--)
	{
		if(isOperand(exp[j]))
		{
			push(exp[j]-'0');
		}
		else
		{
			int x,y;
			x = pop();
			y = pop();

			switch(exp[j])
			{
				case '+'	:	push(x+y);
							break;

				case '-'	:	push(x-y);
							break;

				case '*'	:	push(x*y);
							break;

				case '/'	:	push(x/y);
							break;
			}
		}
	}
	return pop();
}

int isOperand(char ch)
{
	if(ch>=48 && ch<=57)
		return 1;
	else
		return 0;
}

void push(int val)
{
	stack[++top] = val;
}

int pop()
{
	return stack[top--];
}
