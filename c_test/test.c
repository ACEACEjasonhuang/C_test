#include<string.h>
#include<stdio.h>
#include<c_test/test.h>
#include<math.h>
#include<c_test/linklist.h>
#include<stdlib.h>
int func_cnt = 0;
Function func_head, *func_tail = &func_head;
struct FunctionInfo c_test_info;

int RUN_ALL_TESTS(){
    for (struct LinkNode *p = func_head.p.next; p; p = p->next){
        Function *func = Head(p, Function, p);
        printf(GREEN("[====RUN====] ")RED_HL("%s\n"), func->str);
        c_test_info.total = 0, c_test_info.success = 0;
        func->func();
        double rate = 1.0 * c_test_info.success / c_test_info.total;
        rate *= 100.0;
        printf(PURPLE("[  "));
        if (fabs(rate - 100.0) < 1e-6){
            printf(BLUE_HL("%6.2lf%%"), rate);
        }
        else{
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(PURPLE("  ]")"total : %d    success : %d\n", 
            c_test_info.total, 
            c_test_info.success
              );
    }
    struct LinkNode *p = func_head.p.next;
    while (p){     
        Function *func = Head(p, Function, p);
        p = p->next;
        free((char*)(func->str));
        free(func);
    }
    return 0;
}

void add_function(TestFuncT func, const char* str){
    Function *temp = (Function*)calloc(1, sizeof(Function));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->p.next = &(temp->p);
    func_tail = temp;
    return ;
}
