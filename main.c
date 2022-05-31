#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

///Terminado

typedef struct{
    int matricula;
    char nombre[30];
    char genero;
}stAlumno;

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();

int cargarStruct(stAlumno Arr[], int dimension);
void mostrarStruct(stAlumno Arr[], int validos);
int buscarMatricula(stAlumno Arr[], int dimension);
int cargarAlumno(stAlumno Arr[], int validos);
void mostrarAlumno(stAlumno Arr[], int posicion);
int menorMatricula(stAlumno Arr[], int i, int validos);
void xSeleccion(stAlumno Arr[], int validos);
char cualGenero();
void mostrarPorGenero(stAlumno Arr[], int validos);
void insertarMatricula(stAlumno Arr[], int i);
void xInsercionMatricula(stAlumno Arr[], int validos);
void insertarNombre(stAlumno Arr[], int i);
void xInsercionNombre(stAlumno Arr[], int validos);
int contadorGenero(stAlumno Arr[], int validos, char generoBuscado);

int main(){
    int seleccion=0;
    char seguir='s';

    do{
        puts("\t----SELECCIONE UN EJERCICIO----\n");
        printf("\nEJERCICIO 1");
        printf("\nEJERCICIO 2");
        printf("\nEJERCICIO 3");
        printf("\nEJERCICIO 4");
        printf("\nEJERCICIO 5");
        printf("\nEJERCICIO 6");
        printf("\nEJERCICIO 7");
        printf("\nEJERCICIO 8");
        printf("\nEJERCICIO 9\n\n");
        scanf("%i", &seleccion);


        switch(seleccion){
        case 1:
            {
                system("cls");
                ejercicio1();
                break;
            }
        case 2:
            {
                system("cls");
                ejercicio2();
                break;
            }
        case 3:
            {
                system("cls");
                ejercicio3();
                break;
            }
        case 4:
            {
                system("cls");
                ejercicio4();
                break;
            }
        case 5:
            {
                system("cls");
                ejercicio5();
                break;
            }
        case 6:
            {
                system("cls");
                ejercicio6();
                break;
            }
        case 7:
            {
                system("cls");
                ejercicio7();
                break;
            }
        case 8:
            {
                system("cls");
                ejercicio8();
                break;
            }
        case 9:
            {
                system("cls");
                ejercicio9();
                break;
            }
        }

        puts("\n");
        system("pause");
        system("cls");

        printf("Desea ver otro ejercicio? s/n\n\n");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir=='s');
}

int cargarStruct(stAlumno Arr[], int dimension){
    int i=0;
    char control='s';
    srand(time(NULL));

    while(i<dimension && control=='s'){
        puts("\nMatricula del alumno:\n");
        fflush(stdin);
        scanf("%d", &Arr[i].matricula);

        puts("\nNombre del alumno:\n");
        fflush(stdin);
        gets(Arr[i].nombre);

        puts("\nGenero del alumno: \n");
        fflush(stdin);
        scanf("%c", &Arr[i].genero);

        while(Arr[i].genero != 'm' && Arr[i].genero != 'f' && Arr[i].genero != 'o'){
            puts("\nEl genero ingresado no es correcto. Ingrese 'm', 'f', 'o'\n");
            fflush(stdin);
            scanf("%c", &Arr[i].genero);
        }

        i++;

        puts("\nDesea ingresar otro registro? 's' o 'n'\n");
        fflush(stdin);
        scanf("%c", &control);
    }

    return i;
}

void mostrarStruct(stAlumno Arr[], int validos){
    int i=0;

    puts("\nNombre ---------- Matricula ---------- Genero \n");

    while(i<validos){
        printf("\n%s\t\t     %d\t\t       ", Arr[i].nombre, Arr[i].matricula, Arr[i].genero);
        if(Arr[i].genero=='m'){
            printf("Masculino\n");
        }else if(Arr[i].genero=='f'){
            printf("Femenino\n");
        }else{
            printf("Otro\n");
        }
        i++;
    }
}

int buscarMatricula(stAlumno Arr[], int dimension){
    int i=0, flag=0, matBuscada=0;

    puts("\nIngrese la matricula buscada: \n");
    scanf("%d", &matBuscada);

    while(i<dimension && flag==0){
        if(Arr[i].matricula==matBuscada){
            flag=1;
        }else{
            i++;
        }
    }

    return i;
}

int cargarAlumno(stAlumno Arr[], int validos){

    puts("\nMatricula del alumno:\n");
    fflush(stdin);
    scanf("%d", &Arr[validos].matricula);

    puts("\nNombre del alumno:\n");
    fflush(stdin);
    gets(Arr[validos].nombre);

    puts("\nGenero del alumno: \n");
    fflush(stdin);
    scanf("%c", &Arr[validos].genero);

    return validos+1;
}

void mostrarAlumno(stAlumno Arr[], int posicion){
    puts("\nNombre ---------- Matricula ---------- Genero \n");
    printf("\n%s\t\t     %d\t\t           %c\n", Arr[posicion].nombre, Arr[posicion].matricula, Arr[posicion].genero);
}

int menorMatricula(stAlumno Arr[], int i, int validos){
    int posicion=i;
    int j=i+1;
    int menor=Arr[i].matricula;

    while(j<validos){
        if(menor>Arr[j].matricula){

            menor=Arr[j].matricula;
            posicion=j;
        }
        j++;
    }

    return posicion;
}

void xSeleccion(stAlumno Arr[], int validos){
    int auxM, i=0, posicion;
    char auxN[30], auxG;

    while(i<validos-1){

        posicion=menorMatricula(Arr, i, validos);

        auxM=Arr[posicion].matricula;
        strcpy(auxN, Arr[posicion].nombre);
        auxG=Arr[posicion].genero;

        Arr[posicion].matricula=Arr[i].matricula;
        strcpy(Arr[posicion].nombre, Arr[i].nombre);
        Arr[posicion].genero=Arr[i].genero;

        Arr[i].matricula=auxM;
        strcpy(Arr[i].nombre, auxN);
        Arr[i].genero=auxG;

        i++;
    }
}

char cualGenero(){
    char generoBuscado;

    puts("\nQue genero desea ver? m/f/o\n");
    fflush(stdin);
    scanf("%c", &generoBuscado);

    return generoBuscado;
}

void mostrarPorGenero(stAlumno Arr[], int validos){
    int i=0;
    char generoBuscado=cualGenero();

    while(i<validos){
        if(Arr[i].genero==generoBuscado){
            mostrarAlumno(Arr, i);
            i++;
        }else{
            i++;
        }
    }
}

void insertarMatricula(stAlumno Arr[], int i){
    int valorM=Arr[i+1].matricula;
    char valorN[1][30];
    strcpy(valorN[0],Arr[i+1].nombre);
    char valorS=Arr[i+1].genero;

    while(i>=0 && valorM<Arr[i].matricula)
    {
        Arr[i+1].matricula=Arr[i].matricula;
        strcpy(Arr[i+1].nombre,Arr[i].nombre);
        Arr[i+1].genero=Arr[i].genero;
        i--;
    }
    Arr[i+1].matricula=valorM;
    strcpy(Arr[i+1].nombre,valorN[0]);
    Arr[i+1].genero=valorS;

}

void xInsercionMatricula(stAlumno Arr[], int validos){
    int i=0;

    while(i<validos-1){
        insertarMatricula(Arr, i);
        i++;
    }
}

void insertarNombre(stAlumno alumno[], int i){
    int valorM=alumno[i+1].matricula;
    char valorN[1][30];
    strcpy(valorN[0],alumno[i+1].nombre);
    char valorS=alumno[i].genero;
    int j=i;
    while(j>=0 && strcmp(valorN[0],alumno[j].nombre)<0)
    {
        alumno[j+1].matricula=alumno[j].matricula;
        strcpy(alumno[j+1].nombre,alumno[j].nombre);
        alumno[j+1].genero=alumno[j].genero;
        j--;
    }
    alumno[j+1].matricula=valorM;
    strcpy(alumno[j+1].nombre,valorN[0]);
    alumno[j+1].genero=valorS;
}

void xInsercionNombre(stAlumno Arr[], int validos){
    int i=0;

    while(i<validos-1){
        insertarNombre(Arr, i);
        i++;
    }
}

int contadorGenero(stAlumno Arr[], int validos, char generoBuscado){
    int cantidadGenero=0, i=0;

    while(i<validos){
        if(generoBuscado=Arr[i].genero){
            cantidadGenero++;
            i++;
        }else{
            i++;
        }
    }

    return cantidadGenero;
}

void ejercicio1(){
    stAlumno Alumno1[30];

    int validos=cargarStruct(Alumno1, 30);
}

void ejercicio2(){
    stAlumno Alumno2[30];

    int validos=cargarStruct(Alumno2, 30);
    mostrarStruct(Alumno2, validos);
}

void ejercicio3(){
    stAlumno Arr3[30];

    int validos=cargarStruct(Arr3, 30);
    mostrarStruct(Arr3, validos);

    int posicion=buscarMatricula(Arr3, 30);
    mostrarAlumno(Arr3, posicion);
}

void ejercicio4(){
    stAlumno Alumno4[30];

    int validos = cargarStruct(Alumno4, 30);
    mostrarStruct(Alumno4, validos);

    puts("\n    -------- REGISTROS ORDENADOS --------");

    xSeleccion(Alumno4, validos);
    mostrarStruct(Alumno4, validos);
}

void ejercicio5(){
    stAlumno Alumno5[30];

    int validos = cargarStruct(Alumno5, 30);

    mostrarPorGenero(Alumno5, validos);
}

void ejercicio6(){
    stAlumno Alumno6[30];

    int validos = cargarStruct(Alumno6, 30);
    xSeleccion(Alumno6, validos);
    mostrarStruct(Alumno6, validos);

    validos = cargarAlumno(Alumno6, validos);

    puts("\n------ARREGLO ORDENADO------\n");

    xInsercionMatricula(Alumno6, validos);
    mostrarStruct(Alumno6, validos);
}

void ejercicio7(){
    stAlumno Alumno7[30];

    int validos = cargarStruct(Alumno7, 30);
    mostrarStruct(Alumno7, validos);

    puts("\n       ------ARREGLO ORDENADO------\n");

    xInsercionNombre(Alumno7, validos);
    mostrarStruct(Alumno7, validos);
}

void ejercicio8(){
    stAlumno Alumno8[30];
    char generoBuscado;

    int validos=cargarStruct(Alumno8, 30);
    mostrarStruct(Alumno8, validos);

    puts("\nIngrese el genero que busca para saber la cantidad\n");
    scanf("%c", &generoBuscado);

    int cantidad=contadorGenero(Alumno8, validos, generoBuscado);
    printf("\nLa cantidad de personas de ese genero es de: %d\n", cantidad);
}

void ejercicio9(){
    puts("\nSwitch en el main\n");
}
