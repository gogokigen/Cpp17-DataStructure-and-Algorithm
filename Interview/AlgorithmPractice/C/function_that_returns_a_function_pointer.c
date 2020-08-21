//https://www.gamedev.net/forums/topic/687109-function-that-returns-a-function-pointer/5335426/
#include <stdio.h>
#include <stdlib.h>

//e.g. 1
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

typedef int (*FNP)(int, int);

FNP get_func1(int op){
    if (op == '+') return &add;
    return &sub;
}

FNP get_func2(int op){
    if (op == '-') return &sub;
    return &add;
}

//e.g. 2
typedef struct _op* t_op;

typedef t_op ADD(int);
typedef t_op SUB(int);

typedef struct _op{
    ADD* func1;
    SUB* func2
}op;

static t_op func1(int op);
static t_op func2(int op);

op operation1 = {
    func1,
    func2
};

op operation2 = {
    func2,
    func1
};

static t_op func1(int op){
    printf("func1 op = %d\n", op);
    return &operation1;
}

static t_op func2(int op){
    printf("func2 op = %d\n", op);
    return &operation2;
}

static op* op_ptr = &operation1;



int main(void){

//e.g. 1
    int (*fnc)(int, int);

    int a = 3;
    int b = 5;
    int result;

    fnc = get_func1('+');
    result = (*fnc)(a, b);
    printf("%d + %d = %d\n", a, b, result);
    
    fnc = get_func2('-');
    result = (*fnc)(a, b);
    printf("%d - %d = %d\n", a, b, result);
    
//e.g. 2
    op (*fnc_o)(int);
    fnc_o = op_ptr->func1(4);

    return 0;
}