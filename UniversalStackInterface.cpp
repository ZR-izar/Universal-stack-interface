#define CREATE_NEW_STACK(DATATYPE, STACK_NAME, STACK_SIZE, ERROR)   \
    DATATYPE STACK_NAME##Array[STACK_SIZE];                         \
    int STACK_NAME##_top_element = -1;                              \
    int STACK_NAME##IsEmpty(void)                                   \
    {                                                               \
        return STACK_NAME##_top_element == -1;                      \
    }                                                               \
    int STACK_NAME##IsFull(void)                                    \
    {                                                               \
        return STACK_NAME##_top_element == STACK_SIZE-1;            \
    }                                                               \
    DATATYPE STACK_NAME##Push(DATATYPE value)                       \
    {                                                               \
        if(STACK_NAME##IsFull()){return ERROR;}                     \
        STACK_NAME##Array[++STACK_NAME##_top_element] = value;      \
        return (DATATYPE)!ERROR;                                    \
    }                                                               \
    DATATYPE STACK_NAME##Pop(void)                                  \
    {                                                               \
        if(STACK_NAME##IsEmpty()){return ERROR;}                    \
        STACK_NAME##Array[STACK_NAME##_top_element--] = ERROR;      \
        return (DATATYPE)!ERROR;                                    \
    }                                                               \
    DATATYPE STACK_NAME##Top(void)                                  \
    {                                                               \
        if(STACK_NAME##IsEmpty()){return ERROR;}                    \
        return STACK_NAME##Array[STACK_NAME##_top_element];         \
    }
	
	
//以上宏定义可以提供的接口：
/******************************************************************
 *功    能：创建堆栈
 *输    入： DATATYPE  ：堆栈存放的数据的类型
 *          STACK_NAME：堆栈的名字
 *          STACK_SIZE：堆栈的大小
 *          ERROR     ：自定义错误码，错误码数据类型必须与堆栈存放的数据的类型一致
 *返    回：无
 *注    意：注意结尾不加分号，
 ******************************************************************/
CREATE_NEW_STACK(DATATYPE, STACK_NAME, STACK_SIZE, ERROR)


/******************************************************************
 *功    能：判断堆栈是否为空
 *输    入：无
 *返    回：0：不为空
           1：为空
 *注    意：将[STACK_NAME]替换成堆栈的名字
 ******************************************************************/
int [STACK_NAME]IsEmpty(void);


/******************************************************************
 *功    能：判断堆栈是否存满
 *输    入：无
 *返    回：0：未存满
           1：存满
 *注    意：将[STACK_NAME]替换成堆栈的名字
 ******************************************************************/
int [STACK_NAME]IsFull(void);


/******************************************************************
 *功    能：入栈
 *输    入：DATATYPE value:要压入堆栈的数据
 *返    回：ERROR :入栈出错
           !ERROR:入栈成功
 *注    意：将[STACK_NAME]替换成堆栈的名字
 ******************************************************************/
DATATYPE [STACK_NAME]Push(DATATYPE value); 


/******************************************************************
 *功    能：出栈
 *输    入：无
 *返    回：ERROR :出栈出错
           !ERROR:出栈成功
 *注    意：将[STACK_NAME]替换成堆栈的名字
 ******************************************************************/
DATATYPE [STACK_NAME]Pop(void);


/******************************************************************
 *功    能：获取栈顶的数据
 *输    入：无
 *返    回：栈顶的数据
 *注    意：将[STACK_NAME]替换成堆栈的名字
 ******************************************************************/
DATATYPE [STACK_NAME]Top(void);



//应用举例
#include <iostream>

using namespace std;

//创建堆栈1
CREATE_NEW_STACK(int, stack1, 10, -1)
//创建堆栈2
CREATE_NEW_STACK(const char *, stack2, 255, NULL)

int main()
{
    int a = 1;
    int b = 3;
    int c = 5;
    const char *p1 = "this is test one";
    const char *p2 = "this is test two";

    //堆栈1入栈
    if (-1 == stack1Push(a))
    {
        return -1;
    }
    if (-1 == stack1Push(b))
    {
        return -1;
    }
    if (-1 == stack1Push(c))
    {
        return -1;
    }

    //堆栈2入栈
    if (NULL == stack2Push(p1))
    {
        return -1;
    }

    if (NULL == stack2Push(p2))
    {
        return -1;
    }

    //堆栈1验证
    printf("satck1_top: %d\r\n",stack1Top());
    if (-1 == stack1Pop())
    {
        return -1;
    }
    printf("satck1_top: %d\r\n", stack1Top());
    if (-1 == stack1Pop())
    {
        return - 1;
    }
    printf("satck1_top: %d\r\n", stack1Top());

    //堆栈2验证
    printf("satck2_top: %s\r\n",stack2Top());
    if (NULL == stack2Pop())
    {
        return -1;
    }
    printf("satck2_top: %s\r\n", stack2Top());

    system("pause");//输出后暂停在cmd中

    return 0;
}

