
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dato;
    struct node *next;
};
struct node *head=NULL;

void create()
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node)); //newNode
    printf("\nTeclea valor: ");
    scanf("%d",&temp->dato);
    temp->next=NULL;

    if(head==NULL) //comprueba si es es el primer elemento
    {
        head=temp;
    }
    else //hay mas de 0 elementos
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }

        ptr->next=temp;
    }
}

void insertI() //inserta al inicio
{
    //Primera parte (generamos un nuevo nodo con su dato)
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Teclea el valor: ");
    scanf("%d",&temp->dato);
    temp->next=NULL;
    temp->next=head;
    head=temp;
}

void insertF()
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\nTeclea valor: ");
    scanf("%d",&temp->dato);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }

}

void insertPos()
{
    struct node *ptr,*temp;
    int i,pos;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\nEscribe la posicion: ");
    scanf("%d",&pos);
    printf("\nTeclea el valor: ");
    scanf("%d",&temp->dato);
    temp->next=NULL;
    if(pos==0) //insertar al inicio
    {
        temp->next=head;  //aqui se liga con el primer elemento
        head=temp;
    }
    else
    {
        for(i=0,ptr=head;i<pos-1;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\n No existe la posicion\n");
                return;
            }

        }
        temp->next=ptr->next; //liga siguiente
        ptr->next=temp; //liga anteior
    }
}


void deleteI()
{

    if(head==NULL)
    {
        printf("\n La lista esta vacia \n");
        return;
    }
    else
    {
        struct node *ptr=head; //temporal para saber a quien se elimina
        head=head->next;
        printf("\nEl elemento eliminado fue: %d ",ptr->dato);
        free(ptr);
    }
}

void deleteF()
{
    if(head==NULL)
    {
        printf("\n La lista esta vacia \n");
        return;
    }
    else if(head->next==NULL) //si solo hay un elemento
    {
        printf("\n Se elimino e lelemento %d ",head->dato);
        head=NULL;
    }
    else
    {
        struct node *temp,*ptr;
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr; //penultimo
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("\nSe elimino el elemento %d",ptr->dato);
        free(ptr);

    }
}

void deletePos()
{
    int i, pos;
    struct node *temp,*ptr;
    if(head==NULL)
    {
        printf("\nla lista esta vacia \n");
        return;
    }
    else
    {
        printf("\n Escribe el indice: ");
        scanf("%d",&pos);
        if(pos==0)
        {
            printf("Se elimino el elmento %d",head->dato);
            head=head->next;
        }
        else
        {
            ptr=head;
            for(i=0;i<pos;i++)
            {
                temp=ptr; //anterior
                ptr=ptr->next; //actual que eliminmare
                if(ptr==NULL)
                {
                    printf("\nel indice no existe");
                    return;
                }
            }
            temp->next=ptr->next;
            printf("\n se elimnio el dato %d",ptr->dato);
            free(ptr);

        }
    }

}

void print()
{
    if(head==NULL)
    {
        printf("\nLa lista esta vacia");
        return;
    }
    else
    {
        struct node *ptr=head;
        printf("Los elemento s de la lista son: \n");
        while(ptr!=NULL)
        {
            printf("%d |",ptr->dato);
            ptr=ptr->next;
        }
        free(ptr);
    }
}
 
//Función para contar el toral de nodos en la lista
int count(struct node *list)
{
    int nodes = 0;
    //Mientras la lista no sea nula, se suma 1 al contador
    while (list != NULL) 
    {
        nodes++;
        list = list->next;
    }

    return nodes;
}

int swap(struct node *list, int elemento1, int elemento2)
{
    //Declaracion de variables de tipo node
    struct node *nodo1, *nodo2, *prev1, *prev2, *temp;
    int i;

    // Obtenemos la distancia entre los nodos
    const int maxPos = (elemento1 > elemento2) ? elemento1 : elemento2;

    //Obtenemos el valor total de los nodos
    const int totalnodos = count(list);

    // Validamos que los elementos sean validos para intercambiar
    if ((elemento1 <= 0 || elemento1 > totalnodos) || (elemento2 <= 0 || elemento2 > totalnodos))
    {
        return -1;
    }
    
    // Si ambas posiciones son iguales, no se requiere intercambio
    if (elemento1 == elemento2)
    {
        return 1;
    }


    // Nodos a intercambiar
    i = 1;
    temp  = list;
    prev1 = NULL;
    prev2 = NULL;

    //Encontrar nodos a intercambiar
    while (temp != NULL && (i <= maxPos))
    {
        if (i == elemento1 - 1)
            prev1 = temp;
        if (i == elemento1)
            nodo1 = temp;

        if (i == elemento2 - 1)
            prev2 = temp;
        if (i == elemento2)
            nodo2 = temp;

        temp = temp->next;
        i++;
    }

    //Si se encuentran ambos nodos para intercambiar.
    if (nodo1 != NULL && nodo2 != NULL)
    {
        // Link previous of nodo1 with nodo2
        if (prev1 != NULL)
            prev1->next = nodo2;

        // Link previous of nodo2 with nodo1
        if (prev2 != NULL)
            prev2->next = nodo1;

        //Intercambie nodo1 y nodo2 intercambiando sus
        //Enlace al siguiente de nodo1 con nodo2
        temp        = nodo1->next;
        nodo1->next = nodo2->next;
        nodo2->next = temp;

        // Cambiar el nodo cabeza si se intercambia el primer nodo
        if (prev1 == NULL)
            head = nodo2;
        else if (prev2 == NULL)
            head = nodo1;
    }

    return 1;
}



int main()
{
    int opc;
    while(1){

        printf("\n                MENU                             \n");
        printf("\n 1.Crear\n");
        printf("\n 2.Display\n");
        printf("\n 3.Insertar al principio\n");
        printf("\n 4.Insert al final\n");
        printf("\n 5.Insertar en alguna posicion:\n");
        printf("\n 6.ELiminar al principio\n");
        printf("\n 7.Eliminar del final\n");
        printf("\n 8.ELiminar de alguna posicion\n");
        //Necesito más tiempo para implementarla en el main
        printf("\n 9.Salir\n");
        printf("\n--------------------------------------\n");
        printf("Seleccione:\t");
        scanf("%d",&opc);
        switch(opc)
        {
            case 1:
                create();
                break;
            case 2:
                print();
                break;
            case 3:
                insertI();
                break;
            case 4:
                insertF();
                break;
            case 5:
                insertPos();
                break;
            case 6:
                deleteI();
                break;
            case 7:
                deleteF();
                break;
            case 8:
                deletePos();
                break;

            case 9:
                exit(0);
                break;

            default:
                printf("\n NO existe la opcion\n");
                break;
        }
    }
    return 0;
}
