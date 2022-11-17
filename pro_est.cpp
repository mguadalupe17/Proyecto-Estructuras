#include <iostream>
#include <time.h>

using namespace std;

struct numeros
{
	 int n1;
	 int n2;
	 int n3;
	 int n4;
	 int n5;
	 int n6;
};

time_t tiempo()
{
	time_t t1=0;
	time_t
		
}

void merge(numeros A[],int inicio, int mitad, int final)
{
    int i, j, k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    numeros izquierda[elementosIzq];
    numeros derecha[elementosDer];

    for(int i = 0; i < elementosIzq; i++)
	{
        izquierda[i].n5 = A[inicio+i].n5;
    }
    for(int j = 0; j < elementosDer; j++)
	{
        derecha[j].n5 = A[mitad + 1 + j].n5;
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < elementosIzq && j < elementosDer)
	{
        if(izquierda[i].n5 <= derecha[j].n5)
		{
            A[k].n5 = izquierda[i].n5;
            i++;
        }else
		{
            A[k].n5 = derecha[j].n5;
            j++;
        }
        k++;
    }

    while(j < elementosDer)
	{
        A[k].n5 = derecha[j].n5;
        j++;
        k++;
    }

    while(i < elementosIzq)
	{
        A[k].n5 = izquierda[i].n5;
        i++;
        k++;
    }

}
void mergeSort(numeros A[],int inicio, int final)
{
    if(inicio < final)
	{
        int mitad = inicio + (final - inicio)/2;
        mergeSort(A,inicio,mitad);
        mergeSort(A,mitad+1,final);
        merge(A,inicio,mitad,final);
    }
}

void swap(int &a,int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

int particion(numeros A[],int inicio, int fin)
{
    int pivote = A[inicio].n6;
    int i = inicio + 1;
    for(int j = i; j <= fin; j++)
	{
        if(A[j].n6 < pivote)
		{
            swap(A[i].n6,A[j].n6);
            i++;
        }
    }
    swap(A[inicio],A[i-1]);
    return i-1;
}

void quickSort(numeros A[], int inicio, int fin)
{
    if(inicio < fin){
        int pivote = particion(A,inicio,fin);
        quickSort(A,inicio,pivote-1);
        quickSort(A,pivote+1,fin);
    }
}
int main()
{
	srand(time(NULL));
	int op, opo;
	int numero;
	long int tam = 40000, aux, i, j;
	numeros A[tam];
	for(long int i=0; i<tam; i++)
	{
		numero = 1+rand()%(5001-1);
		A[i].n1 = numero;
		A[i].n2 = numero;
		A[i].n3 = numero;
		A[i].n4 = numero;
		A[i].n5 = numero;
		A[i].n6 = numero;
	}
	do
	{
		cout<<"\n\t* * *MENU* * *"<<endl;
		cout<<"1.-Ordenamiento de Datos"<<endl;
		cout<<"2.-Busqueda de Datos"<<endl;
		cout<<"3.-Salir"<<endl;
		do{
			cout<<"\nSeleccione una opcion: ";
			cin>>op;
			if(op<1 || op>3)
				cout<<"Error...!Opcion incorrecta\n";
		}while(op<1 | op>3);
		switch(op)
		{
			case 1:
				do
				{
					cout<<"\n\tMENU ORDENAMIENTO"<<endl;
					cout<<"1) Metodo de la Burbuja"<<endl;
					cout<<"2) Metodo de Seleccion"<<endl;
					cout<<"3) Metodo de Insercion"<<endl;
					cout<<"4) Metodo Shell"<<endl;
					cout<<"5) Metodo MergeSort"<<endl;
					cout<<"6) Metodo Quick Sort"<<endl;
					cout<<"7) Tabla de tiempos de ejecucion"<<endl;
					cout<<"8) Salir"<<endl;
					do
					{
						cout<<"\nSeleccione una opcion: ";
						cin>>opo;
						if(opo<1 || opo>8)	
							cout<<"Error...!Opcion incorrecta\n";
					}while(opo<1 || opo>8);	
					switch(opo)
					{
						case 1: 
							for(i=0;i<tam;i++)
							{
								for(j=0; j<(tam -1);j++)
								{
									if(A[j].n1>A[j+1].n1)
									{
										aux=A[j].n1;
										A[j].n1=A[j+1].n1;
										A[j+1].n1=aux;	
									}
								}
							}
						break;
						case 2:
							long int minimo;
							for(i=0; i<tam-1; i++)
							{
								minimo=i;
								for(j=i+1; j<tam;j++)
								{
									if(A[j].n2<A[minimo].n2)
									minimo=j;
								}
								if (minimo!=i)
								{
									aux=A[i].n2;
									A[i].n2=A[minimo].n2;
									A[minimo].n2=aux;
								}
							}
						break;
						case 3:
							long int valor;
							for(i=1;i<tam;i++)
							{
								valor=A[i].n3;
								j=i;
								while(j>0 && A[j-1].n3>valor)
								{
									A[j].n3=A[j-1].n3;
									j--;
								};
								A[j].n3=valor;
							}
							break;
						case 4:
							long int incremento;
							incremento=tam/2;
							while(incremento>0){
								for(i=incremento;i<tam;i++)
								{
									aux=A[i].n4;
									j=i-incremento;
									while(j>=0 && aux<A[j].n4)
									{
										A[j+incremento].n4=A[j].n4;
										j=j-incremento;
									}
									A[j+incremento].n4=aux;
								}
								incremento=incremento/2;
							}
							break;
						case 5:
							mergeSort(A, 0, tam-1);
							break;	
						case 6:
							quickSort(A,0,tam-1);
							break;
							
					}
				}while(opo!=8);
				break;
		}
	} while(op!=3);
		
	return 0;
}
