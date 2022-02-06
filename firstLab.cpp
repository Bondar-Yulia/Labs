#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *prev;
    Node *next;
};
void addToBeginning(Node** head, Node* node){
    node->next = (*head);
    node->prev = NULL;
    (*head)->prev = node;
}
void addAfter(Node* prev, Node* node)
{
    node->next = prev->next;
    prev->next = node;
    node->prev = prev;
    if (node->next != NULL) {
        node->next->prev = node;
    }
}
void addToEnd(Node** head, Node* node){
    Node* last = *head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = node;
    node->prev = last;
}
void remove(Node** head, Node* node){
    if(node->prev == NULL){
        head = &(node->next);
        (*head)->prev = NULL;
        delete node;
    } else if(node->next == NULL){
        node->prev->next = NULL;
        delete node;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
}
void add_group(Node** head, Node* nodes[], int number_of_nodes){
    for(int i = 0; i < number_of_nodes; i++){
        addToEnd(head, nodes[i]);
    }
}
void remove_group(Node** head, Node* nodes[], int number_of_nodes){
    for(int i = 0; i < number_of_nodes; i++){
        remove(head, nodes[i]);
    }
}
void sort(Node** head){
    int n = 0;
    Node* iter = *head;
    while(iter != NULL){
        iter = iter->next;
        n++;
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(iter->data > iter->next->data){
                Node* node = iter;
                iter->next = iter->next->next;
                iter->next->prev = iter->next->prev->prev;
                iter->next->prev->next = iter;
                iter->prev = iter->next->prev;
                node->prev->next = iter->prev;
                iter->prev->prev = node->prev;
            }
            iter = *head;
        }
    }
}
int main() {
}