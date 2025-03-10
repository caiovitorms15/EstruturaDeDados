#include <stdio.h>

typedef struct lista { //definição da lista implementada em vetor, com tamanho do vetor e variável de controle
    int v[10];
    int ctr;
}lista;

void criar_lista(lista *ll) //criação da lista, com lista vazia definida como -1
{
    ll->ctr= -1;
}

void inserir_elementoI(lista *ll, int valor) //função de inserir elemento no inicio
{
    if(ll->ctr+1 <= 10) //se ainda tiver espaço na lista:
    {
        int i;
        for (i=ll->ctr+1;i>=0;i--) //o i começa do final e vai absorvendo seu antecessor, copiando os valores
        {
            ll->v[i] = ll->v[i-1];
        }
        ll->v[0] = valor; //adiciona o valor no espaço "vago" que estará no inicio
        ll->ctr++; //incremento de elementos
    }
    else //caso não tenha espaço na lista
    {
        printf("Não foi possivel adicionar o valor %d no inicio da lista, devido a falta de espaço", valor);
    }
}
void remover_elementoI (lista *ll) //função de remover elemento no inicio
{
    if (ll->ctr==-1) //caso seja uma lista vazia:
    {
        printf("Não é possivel remover do inicio, pois a lista está vazia");
    }
    else //caso não seja lista vazia:
    {
        int i;
        for (i=0;i<=ll->ctr;i++) //i começa do primeiro elemento da lista e para no ultimo elemento
        {
            ll->v[i] = ll->v[i+1]; //o i irá absorver seu sucessor, apagando o elemento que não tem antecessor(inicio)
        }
        ll->ctr--; //decrécimo de elementos
    }
}
void inserir_elemento(lista *ll, int valor) //função de inserir elemento no final
{
    if(ll->ctr+1<=10) //caso tenha espaco
    {
    ll->v[ll->ctr+1] = valor; //adição de elemento no espaço sobrando da lista
    ll->ctr++; //acréscimo de elemento
    }
    else //caso não tenha espaco
    {
        printf("Nao e possivel adicionar elemento na lista, sem espaco"); 
    }
}
void remover_elemento(lista *ll) //função de remover elemento no final da lista
{

    if (ll->ctr==-1) //lista vazia
    {
        printf("Não é possivel remover do inicio, pois a lista está vazia");
    }
    else
    {
    ll->ctr--; //decréscimo de elemento
    }
}

void apagar_lista (lista *ll)
{
    ll->ctr=-1; //redefine a lista
}

void exibir_lista (lista *ll) //função de exibir a lista
{
    int i;
    if (ll->ctr == -1) //lista vazia
    {
        printf("Lista vazia");
    }
    else
    {
    for (i=0; i<=ll->ctr;i++) //percorre a lista do primeiro elemento ao ultimo
    {
        printf("O elemento %d da lista e %d\n", i, ll->v[i]); //print
    }
}
}

void inserir_meio(lista *ll, int valor, int pos) //função de inserção no meio
{
    if(pos>=ll->ctr+1 || pos<0) //caso a posição escolhida seja fora dos elementos existentes ou menor que 0
    {
        printf("Nao existe essa posicao no vetor\n"); 
    }
    else
    {
    if(ll->ctr+1<=10) //caso tenha espaço na lista
    {
        int i;
        for (i=ll->ctr+1;i>pos;i--) //começa do espaço extra na lista e vai diminuindo até a posição escolhida
        {
            ll->v[i] = ll->v[i-1]; //a posição absorve o valor da sua antecessora, translocando pra direita a lista
        }
        ll->v[pos] = valor; //no espaço "vago", adiciona um elemento
        ll->ctr++; //incremento de elementos
    }
    else //caso não tenha espaço
    {
        printf("Nao tem espaco no vetor para a insercao");
    }
    }
}
void remover_meio(lista *ll, int pos) //função de remover uma posição na lista
{
    if(pos>=ll->ctr+1 || pos<0) //caso a posição escolhida seja fora dos elementos existentes ou menor que 0
    {
        printf("Nao existe essa posicao no vetor\n");
    }
    else
    {
    if(ll->ctr==-1) //lista vazia
    {
        printf("Lista vazia");
    }
    else
    {
        int i;
        for (i=pos;i<ll->ctr;i++) //começa da posição que deseja remover
        {
            ll->v[i] = ll->v[i+1]; //elemento absorve seu sucessor, elemento sem antecessor (pos) se perde
        }
        ll->ctr--; //decréscimo de elementos
    }
    }
}

int main ()
{
    lista l1;
    criar_lista(&l1);
}