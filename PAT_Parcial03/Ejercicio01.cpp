#include "Ejercicio01.h"
#include <queue>
using namespace std;

struct Comparador {
    bool operator()(Node<int>*& a, Node<int>*& b) {
        return a->value < b->value;
    }
};

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    priority_queue<Node<int>*, vector<Node<int>*>, Comparador> colaprior;

    while (lists)
    {
        if (lists->value)
        {
            colaprior.push(lists->value);
        }
        lists = lists->next;
    }

    Node<int>* head = nullptr;
    Node<int>* tail = nullptr;

    while (!colaprior.empty())
    {
        Node<int>* current = colaprior.top();
        colaprior.pop();

        if (!head)
        {
            head = tail = current;
        }
        else
        {
            tail->next = current;
            tail = current;
        }

        if (current->next)
        {
            colaprior.push(current->next);
        }
    }

    if (tail)
    {
        tail->next = nullptr;
    }

    return head;
}
