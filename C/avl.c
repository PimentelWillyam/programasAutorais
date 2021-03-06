#include <stdio.h>
#include <stdlib.h>

struct Tree{
        int size;
        struct Node *head;
}tree;

struct Node {
            int val,height;
            struct Node *left, *right,*father;
};

void nodeBalance(struct Node *node)
{
	if (node->left == NULL && node->right == NULL){
			return 0;
	}
	else{
			if (node->left !=NULL && node->right == NULL){
					return -(node->left->height);
			}
			else if (node->right !=NULL && node->left == NULL){
					return node->right->height;
			}
			else{
					return node->right->height - node->left->height;
			}
			
	}
}

void LRot(struct Node *node)
{
		struct Node *aux = malloc(sizeof(struct Node));
		aux = node->right;
		node->right = aux->left;
		aux->left = node;
		aux->father = node->father;
		node->father = aux;
		node->right->father = node;
		attHeight(node->left,0);
		attHeight(node,0);
		free(aux);
}

void RRot(struct Node *node)
{
		struct Node *aux = malloc(sizeof(struct Node));
		aux = node->left;
		node->left = aux->right;
		aux->right = node;
		aux->father = node->father;
		node->father = aux ;
		node->left->father = node;
		attHeight(node->right,0);
		attHeight(node,0);
		free(aux);

}

void LRRot(struct Node *node)
{
		LRot(node->left);
		RRot(node);
}


void RLRot(struct Node *node)
{
		RRot(node->right);
		LRot(node);
}


int attHeight(struct Node *bottom,int i)
{
		int balance;
		balance = nodeBalance(bottom);
		bottom->height = i;
		if(balance < -1){
				if (bottom->val <= bottom->left->val){
					LRot(bottom);
				}
				else{
					LRRot(bottom);
				}		
		}
		if (balance >1){
				if (bottom->right->val > bottom->val){
						RRot(bottom);
				}
				else{
						RLRot(bottom);
				}
		}
		if (bottom != tree.head)
				attHeight(bottom->father,i++);
		return;

}




void insertThis(int insertion, struct Node *side)
{

	        if (tree.size == 0){
                	struct Node *newNode = malloc (sizeof(struct Node));
	                tree.head = newNode;
		            newNode->val = insertion;
		            newNode->left = NULL;
		            newNode->right = NULL;
	                newNode->father = NULL;
            }
	        else{
		                struct Node *aux = side;
		                if (insertion <= aux ->val && aux->left != NULL){
                                                insertThis(insertion, aux->left);
                                }
		                else if (insertion > aux->val && aux->right != NULL){
			                        insertThis(insertion,aux->right);
                                }
		        else if (insertion > aux->val){
                            struct Node *newNode = malloc (sizeof(struct Node));
							aux->right = newNode;
			                newNode->father = aux;
			                newNode->left = NULL;
			                newNode->right = NULL;
			                newNode->val = insertion;
                        }

		        else if (insertion <= aux->val){
                            struct Node *newNode = malloc (sizeof(struct Node));
							aux->left = newNode;
			                newNode->father = aux;
			                newNode->left = NULL;
			                newNode->right = NULL;
			                newNode->val = insertion;
							
                        }
                }
				attHeight(*newNode,0);
                tree.size++;
				return;
}

void removeThis(int insertion, struct Node *side)
{
		struct Node *aux = side;
		if (insertion < aux->val){
				removeThis(insertion,aux->left); // vai pra esquerda
		}
		else if (insertion > aux->val){
				removeThis(insertion,aux->right); // vai pra direita
		}
		else{
				if (aux->left == NULL && aux->right == NULL && aux != tree.head){ // verifica se é uma folha
						aux = aux->father;
						if (aux->left->val == insertion){
								aux->left = NULL;
						}
						else if (aux->right->val == insertion){
								aux->right == NULL;
						}
				}
				else if (tree.head == aux){
						if (tree.head->left == NULL && tree.head->right != NULL){ //verifica se a esquerda ta vazia e a direita tem coisa
								struct Node *aux2 = tree.head;
								tree.head = tree.head->right;
								free(aux2);
						}
						else if (tree.head->left != NULL){ //verifica se  tem coisa na esquerda
								struct Node *aux2 = tree.head;
								tree.head = tree.head->left;
								free(aux2);
						}
						else if(tree.head->right == NULL && tree.head->left == NULL){ // verifica se a cabeça da arvore é uma folha
								free(tree.head);
								tree.head = NULL;
						}
				}
				else{ // o valor não é nem head nem folha, ta no meio da arvore
						if (aux->val != insertion){
								if (insertion <= aux->val){
										removeThis(insertion,aux->left);
								}
								else if (insertion > aux->val){
										removeThis (insertion,aux->right);
								}
						}
						else{ // achou o no pra tirar
								if (aux->left == NULL){
										aux->right->father = aux->father;
										aux->right->val = aux->val;
								}
								else if (aux->right ==NULL){
										aux->left->father = aux->father;
										aux->left->val = aux->val;
										free(aux);
								}
								else if (aux->right !=NULL && aux->left !=NULL){
										aux->left->father = aux->father;
										aux->left->val = aux->val;
										free(aux);
								}
							}	
					}
			}
			tree.size--;
			return;
}

void kilTree(struct Node *side)
{
	removeThis(side->val,side	);
	if(tree.head != NULL){
			kilTree(tree.head);
	}
	tree.size = 0;
	return;
}

void printPreOrder(struct Node *side)
{
		if (side != NULL){
				printf("%d ",side->val);
				printPreOrder(side->left);
				printPreOrder(side->right);
		}
		return;
}

void printInOrder(struct Node *side)
{
		if (side != NULL){	
		printInOrder(side->left);
		printf("%d ",side->val);
		printInOrder(side->right);
		}
	return;
}

void printPostOrder(struct Node *side)
{
		if (side != NULL){	
		printPostOrder(side->left);
		printPostOrder(side->right);
		printf("%d ",side->val);
		}
	return;
}
int main (void)
{	
		int quantidadeDeArvores,quantidadeDeNos,insertion,i,j;
		scanf("%d	",&quantidadeDeArvores);
		for(i=0;i<quantidadeDeArvores;i++){
				scanf("%d",&quantidadeDeNos);
				for(j=0;j<quantidadeDeNos;j++){
						scanf("%d",&insertion);
						insertThis(insertion,tree.head);
				}
				printf("Case %d:",i+1);
				printf("\nPre.: ");
				printPreOrder(tree.head);
				printf("\nIn..: ");
				printInOrder(tree.head);
				printf("\nPost: ");
				printPostOrder(tree.head);
				printf("\n");
				kilTree(tree.head);
				if(i != quantidadeDeArvores-1){
						printf("\n");
				}
		}
        return 0;
}