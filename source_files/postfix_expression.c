
#include "config.h"
#include "postfix_expression.h"
#include "main.h"

#define INITSIZE  20
#define INCREMENT 10
#define MAXBUFFER 20
#define LEN  sizeof(Elemtype)


/*栈的动态分配存储结构*/ 
typedef char Elemtype;
struct SqStack{
	Elemtype *base;
	Elemtype *top;
	int StackSize;
};


/**
 * @brief 初始化栈
 * 
 * @param  无 
 * @return 无 
 */
void InitStack(struct SqStack *S)
{
	S->base=(Elemtype*)malloc(LEN*INITSIZE);
	//assert(S->base != NULL);
	S->top=S->base;
	S->StackSize=INITSIZE;
}

/**
 * @brief 压栈操作
 * 
 * @param  *S
 * @param  *c
 * @return 无 
 */
void PushStack(struct SqStack *S,Elemtype c)
{
	if(S->top - S->base >= S->StackSize)
	{
		S->base=(Elemtype*)realloc(S->base,LEN*(S->StackSize+INCREMENT));
		//assert(S->base !=NULL);
		S->top =S->base+S->StackSize;
		S->StackSize+=INCREMENT;
	}
	*S->top++ = c;
}

/**
 * @brief 求栈长
 * 
 * @param  无 
 * @return int
 */
int StackLength(struct SqStack *S)
{
	return (S->top - S->base);
}

/**
 * @brief 弹栈操作
 * 
 * @param   *S
 * @param		*c
 * @return int
 */
int PopStack(struct SqStack *S,Elemtype *c)
{
	if(!StackLength(S))
	{
		return 0;
	}
	*c=*--S->top;
	return 1;
}


/**
 * @brief 中缀转后缀函数
 * 
 * @param  *S
 * @param  str[]
 * @return 无 
 */
void Change(struct SqStack *S,Elemtype str[])
{
	int i=0;
	Elemtype e;
	InitStack(S);
	while(str[i]!='\0')
	{
		while(isdigit(str[i])) 
		{/*过滤数字字符，直接输出，直到下一位不是数字字符打印空格跳出循环 */
			printf("%c",str[i++]);
			if(!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		/*加减运算符优先级最低，如果栈顶元素为空则直接入栈，否则将栈中存储
		的运算符全部弹栈，如果遇到左括号则停止，将弹出的左括号从新压栈，因为左
		括号要和又括号匹配时弹出，这个后面单独讨论。弹出后将优先级低的运算符压入栈中*/
		if(str[i]=='+'||str[i]=='-')
		{
			if(!StackLength(S))
			{
				PushStack(S,str[i]);
			}
			else
			{
				do
				{
					PopStack(S,&e);
					if(e=='(')
					{
						PushStack(S,e);
					}
					else
					{
						printf("%c ",e);
					}
				}while( StackLength(S) && e != '(' );
				
				PushStack(S,str[i]);
			}
		}
		/*当遇到右括号是，把括号里剩余的运算符弹出，直到匹配到左括号为止
		左括号只弹出不打印（右括号也不压栈）*/
		else if(str[i]==')')
		{
			PopStack(S,&e);
			while(e!='(')
			{
				printf("%c ",e);
				PopStack(S,&e);
			}
		}
		/*乘、除、左括号都是优先级高的，直接压栈*/
		else if(str[i]=='*'||str[i]=='/'||str[i]=='(')
		{
			PushStack(S,str[i]);
		}
		
		else if(str[i]=='\0')
		{
			break;
		}
		
		else
		{
			// printf("\n输入格式错误！\n");
			return ;
		}
		i++;
	}
	/*最后把栈中剩余的运算符依次弹栈打印*/
	while(StackLength(S))
	{
		PopStack(S,&e);
		printf("%c ",e);
	}
}