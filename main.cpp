#include <iostream>
#include "Sort.h"
#include <cstring>

using namespace DTLib;
using namespace std;


struct Node
{
    int value;
    Node* next;
};

Node* create_list( int v,int len )
{
    Node* ret = NULL;
    Node* slider = NULL;

    for(int i = 0;i<len;i++)
    {
        Node* n = new Node();

        n->value = v++;

        n->next = NULL;

        if( NULL == slider )
        {
            slider = n;
            ret = n;
        }
        else
        {
            slider->next = n;
            slider = slider->next;
        }
    }
    return ret;
}

void destroy_list(Node* list)
{
    while( list )
    {
        Node* del = list;

        list = list->next;

        delete del;
    }
}

void print_list(Node* list)
{
    while( list )
    {
        cout << list->value << "->";


        list = list->next;
    }

    cout << "NULL" << endl;
}

Node*reverse_list(Node* list)
{
    if(( NULL == list ) || ( NULL == list->next ))
    {
        return list;
    }
    else
    {
        Node* guard = list->next;

        Node* ret = reverse_list(list->next);

        guard->next = list;

        list->next = NULL;

        return ret;
    }
}


Node* merge_list( Node*list1,Node*list2 )
{
    if( NULL == list1 )
    {
        return list2;
    }
    else if( NULL == list2 )
    {
        return list1;
    }
    else if( list1->value < list2->value )
    {
        Node* list1_ = list1->next;

        Node* list = merge_list(list1_,list2);

        list1->next = list;

        return list1;
    }
    else
    {
        Node* list2_ = list2->next;
        Node* list = merge_list(list1,list2_);

        list2->next = list;

        return list2;
    }

}

/*递归打印链表中的偶数结点*/
void print_even(Node* list)
{
    if( list != NULL )
    {
        print_even(list->next);

        if( list->value % 2 == 0 )
        {
            cout << list->value << endl;
        }
    }
}

/*递归思想实现汉诺塔问题*/
void HanoiTower( int n,char a,char b,char c)
{
    if( n == 1 )
    {
        cout << a << "->" << c << endl;
    }
    else
    {
        HanoiTower(n-1,a,c,b);
        HanoiTower(1,a,b,c);
        HanoiTower(n-1,b,a,c);
    }
}

template <typename T >
void Swap(T& a,T& b)
{
    T temp;
    temp = a;
    a= b;
    b = temp;
}

void permutation(char*s,char*e)
{
    if(*s == '\0')
    {
        cout << e << endl;
    }
    else
    {
        int len = strlen(s);

        for(int i = 0;i < len;i++)
        {

            if( (s[0] != s[i]) || ( i == 0 ))
            {
                Swap(s[0],s[i]);
                permutation(s+1,e);
                Swap(s[0],s[i]);
            }
        }
    }

}

int main()
{
    char s[] = "aac";

    permutation(s,s);

#if 0
    HanoiTower(3,'a','b','c');
#endif

#if 0
    Node* list= create_list(2,5);

    print_list(list);

    print_even(list);

    destroy_list(list);
#endif

#if 0
    Node*list1 = create_list(1,5);

    Node*list2 = create_list(6,7);

    print_list(list1);

    print_list(list2);

    Node* list= merge_list(list1,list2);

    print_list(list);

    destroy_list(list);

#endif
#if 0
    Node* list= create_list(2,6);

    print_list(list);

    list = reverse_list(list);

    print_list(list);

    destroy_list(list);

#endif

#if 0
    int array[] = {2,6,5,3,7,9,8,1,4,0};

    //Sort::Select(array,10,false);
    //Sort::Insert(array,10,true);
    //Sort::Bubble(array,10,false);
    //Sort::Shell(array,10,false);
    //Sort::Merge(array,10,false);
    Sort::Quick(array,10,false);

    for(int i = 0;i<10;i++)
    {
        cout << array[i] << endl;
    }

#endif
    return 0;
}

