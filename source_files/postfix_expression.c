
#include "config.h"
#include "postfix_expression.h"

#define INITSIZE  20
#define INCREMENT 10
#define MAXBUFFER 20
#define LEN  sizeof(Elemtype)

/*ջ�Ķ�̬����洢�ṹ*/ 
typedef char Elemtype;
typedef struct{
	Elemtype *base;
	Elemtype *top;
	int StackSize;
}SqStack;

/**
 * @brief ��ʼ��ջ
 * 
 * @param  �� 
 * @return �� 
 */
void InitStack(SqStack *S)
{
	S->base=(Elemtype*)malloc(LEN*INITSIZE);
	assert(S->base !=NULL);
	S->top=S->base;
	S->StackSize=INITSIZE;
}

/**
 * @brief ѹջ����
 * 
 * @param  *S
 * @param  *c
 * @return �� 
 */
void PushStack(SqStack *S,Elemtype c)
{
	if(S->top - S->base >= S->StackSize)
	{
		S->base=(Elemtype*)realloc(S->base,LEN*(S->StackSize+INCREMENT));
		assert(S->base !=NULL);
		S->top =S->base+S->StackSize;
		S->StackSize+=INCREMENT;
	}
	*S->top++ = c;
}

/**
 * @brief ��ջ��
 * 
 * @param  �� 
 * @return int
 */
int StackLength(SqStack *S)
{
	return (S->top - S->base);
}

/**
 * @brief ��ջ����
 * 
 * @param   *S
 * @param		*c
 * @return int
 */
int PopStack(SqStack *S,Elemtype *c)
{
	if(!StackLength(S))
	{
		return 0;
	}
	*c=*--S->top;
	return 1;
}


/**
 * @brief ��׺ת��׺����
 * 
 * @param  *S
 * @param  str[]
 * @return �� 
 */
void Change(SqStack *S,Elemtype str[])
{
	int i=0;
	Elemtype e;
	InitStack(S);
	while(str[i]!='\0')
	{
		while(isdigit(str[i])) 
		{/*���������ַ���ֱ�������ֱ����һλ���������ַ���ӡ�ո�����ѭ�� */
			printf("%c",str[i++]);
			if(!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		/*�Ӽ���������ȼ���ͣ����ջ��Ԫ��Ϊ����ֱ����ջ������ջ�д洢
		�������ȫ����ջ�����������������ֹͣ���������������Ŵ���ѹջ����Ϊ��
		����Ҫ��������ƥ��ʱ������������浥�����ۡ����������ȼ��͵������ѹ��ջ��*/
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
		/*�������������ǣ���������ʣ��������������ֱ��ƥ�䵽������Ϊֹ
		������ֻ��������ӡ��������Ҳ��ѹջ��*/
		else if(str[i]==')')
		{
			PopStack(S,&e);
			while(e!='(')
			{
				printf("%c ",e);
				PopStack(S,&e);
			}
		}
		/*�ˡ����������Ŷ������ȼ��ߵģ�ֱ��ѹջ*/
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
			// printf("\n�����ʽ����\n");
			return ;
		}
		i++;
	}
	/*����ջ��ʣ�����������ε�ջ��ӡ*/
	while(StackLength(S))
	{
		PopStack(S,&e);
		printf("%c ",e);
	}
}