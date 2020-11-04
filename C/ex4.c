#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ex4 de hazin
struct Node {
                int val;
                char name[50];
                struct Node *next; 
};

struct LinkedList{ 
                int size;
                struct Node *head;
}listaInicial,listaFiltrada;


void insert (int insertion,char insertion2[50],struct LinkedList *linkedList)
{
                struct Node *newNode = malloc(sizeof(struct Node));
                struct Node *aux;
                if (linkedList->size == 0){
                                linkedList->head = newNode;
                                newNode->val = insertion;
                                strcpy(newNode->name,insertion2);
                                newNode->next = NULL;
                }
                else{

                                aux = linkedList->head;
                                while (aux->next!=NULL){  
                                                aux = aux->next;
                                }
                                aux->next = newNode;
                                aux->next->val = insertion;
                                strcpy(aux->next->name,insertion2);
                                aux->next->next = NULL;
                }
                linkedList->size++;
                return;
}

void printNames (struct LinkedList *linkedList)
{
                struct Node *aux = linkedList->head;
                if (linkedList->size == 1){
                                printf("%s ",aux->name);
                }
                else{
                                while (aux != NULL){
                                                printf("%s ",aux->name);
                                                aux = aux->next;
                                }
                }
                free(aux);
                return;
}

void ThrowThisAt(int interest,struct LinkedList *LinkedList1,struct LinkedList *LinkedList2)
{
        struct Node *aux = LinkedList1->head;
        while (aux != NULL){
                        if (aux->val == interest){
                                        insert(aux->val,aux->name,LinkedList2);
                        }
                        aux=aux->next;
        }
        return;
}

int main (void)
{
        int i,nAmigos,idade,interesse;
        char name[50];
        scanf("%d",&nAmigos);
        for (i=0;i<nAmigos;i++){
                scanf("%s %d",&name,&idade);
                insert(idade,name,&listaInicial);         
        }
        scanf("%d",&interesse);
        ThrowThisAt(interesse,&listaInicial,&listaFiltrada);
        if (listaFiltrada.size == 0)
                        printf("Eleven nao tem amigos com essa idade.");
        else
                        printNames(&listaFiltrada);
        return 0;
}