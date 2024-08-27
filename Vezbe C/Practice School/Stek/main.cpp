#include <iostream>
#include "dinstring.hpp"


using namespace std;

class Var{
protected:
    DinString ime;
    DinString tip;
    int duzina;
public:
    Var(): ime("ime"), tip("tip"){
        duzina = 1;
    }
    Var(Var& V): ime(V.ime), tip(V.tip){
        duzina = V.duzina;
    }
    Var(DinString i, DinString t, int d): ime(i), tip(t){
        duzina = d;
    }
};

template<class T, int D>
class Stek{
protected:
    class node{
    public:
        T el;
        node * next;
    };
    node *top;
    int cap;
    int popu;
public:
    Stek(){
    top = NULL;
    cap = D;
    popu = 0;}

    bool isEmpty(){
    if (popu == 0){return true;}
    else{return false;}
    }

    bool isFull(){
    if (popu == cap){return true;}
    else{return false;}
    }

    int size(){return popu;}

    bool push(node& n){
        if(isFull() == true){return false;}
        n.next = top;
        top = &n;
        popu ++;
        return true;
    }
    node* pop(){
        if(isEmpty() == true){return NULL;}
        node *tmp;
        tmp = top;
        top = top->next;
        return tmp;
    }
    node* Top(){
        if(isEmpty() == true){return NULL;}
        return top;
    }
    void clear(){
        popu = 0;
        top = NULL;
    }
};

int main()
{
    Var v1;
    Stek<Var, 10>Stack;

    if(Stack.push(v1) == true){cout << "JEEE";}

    return 0;
}
