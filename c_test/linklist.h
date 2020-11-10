/*************************************************************************
	> File Name: linklist.h
	> Author: Jasonhuang 
	> Mail: acejasonhuang@163.com
	> Created Time: Tue 10 Nov 2020 01:11:57 AM CST
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define offset(T, name) (long long)(&(((T*)(NULL))->name))

#define Head(p, T, name) (T*)((char*)(p) - offset(T, name))

struct LinkNode {
    struct LinkNode * next;
};
#endif
