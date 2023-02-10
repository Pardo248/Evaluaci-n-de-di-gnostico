#include <stdio.h>
#include <stdlib.h>


//FUNCIONES DE APOYO PARA COMPROBAR
void rellena(int *n, int *arr);
void imprime (int n, int *arr, char c);

//FUNCIONES DE TAREA
void addAtTail(int data, int *n, int *arr);//Inserta al final del arreglo
void addAtFront(int data, int *n, int *arr); // Inserta al inicio del arreglo
int size(int n,int *arr); // Indica cuántos datos se han insertado
void removeAll(int n, int *arr); // Borra todos los elementos insertados
int  getAt(int n,int *arr, int index);// Recibe un índice (0-index) y devuelve el valor en esa posición si es válido


int main(){

    int max = 5;
    int *arr=NULL;

    arr= malloc (max*sizeof(int));

    removeAll(max,arr);

    imprime (max,arr,'M');

    addAtTail(2,&max,arr);
    imprime (max,arr,'-');
    addAtTail(5,&max,arr);
    imprime (max,arr,'+');
    addAtFront(7,&max,arr);
    imprime (max,arr,'#');


    printf("\n>> %i <<\n",size(max,arr));
    printf("== %i ==\n",getAt(max,arr,0));


    rellena(&max,arr);
    imprime (max,arr,'R');
    addAtFront(9,&max,arr);
    imprime (max,arr,'?');


    printf("\n>> %i <<\n",size(max,arr));
    printf("== %i ==\n",getAt(max,arr,0));



}

int  getAt(int n,int *arr, int index ){
    if(index < n){
        return *(arr+index);
    }else{
        return NULL;
    }
}

int size(int n,int *arr){
    int i=0,cont=0;

    while(*(arr+i)!= NULL && i<n){
        cont++;
        i++;
    }
    return cont;
}

void removeAll(int n, int *arr){

    for(int j=0;j < n ; j++){
        *(arr+j)=NULL;
    }
}

void addAtFront(int data, int *n, int *arr){

    int i=1;

    if (*arr == NULL){
        *arr=data;
    }
    else{
        while(*(arr+i)!= NULL && i< *n){
                i++;
        }
        if(i < *n ){
            for(int j=i;j>-1;j--){
                *(arr+(j+1))=*(arr+j);
            }
            *arr=data;
        }
        else{
            *n=*n+1;
            arr=realloc(arr,((*n)*sizeof(int)));

            for(int j=i;j>-1;j--){
                *(arr+(j+1))=*(arr+j);
            }
            *arr=data;
        }
    }
}

void addAtTail (int data, int *n, int *arr){

    int i=1;

    if (*arr == NULL){
        *arr=data;
    }
    else{
        while(*(arr+i)!= NULL && i< *n){
                i++;
        }
        if(i < *n ){
            *(arr + i)= data;
        }else{

            *n=*n+1;
            arr=realloc(arr,((*n)*sizeof(int)));

            *(arr + i)= data;
        }
    }

}

void rellena(int *n, int *arr){
    for(int j=1;j < 5 ; j++){
        addAtTail (j,n,arr);
    }
}

void imprime (int n, int *arr, char c){
    printf(" ---------- \n");

    for(int j=0;j < n ; j++){
        printf("%i %c%c %i\n",*(arr+j), c,c, j);
    }
}

