#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define DIM 50

typedef struct
{
    int matricula;
    char nombre[30];
    char genero;

} stAlumno;

stAlumno CargaUnAlumno ();
int CargaArregloAlumnos(stAlumno alumnos[], int dim);
void muestraArregloAlumnos(stAlumno alumno[], int v);
void muestraUnAlumno(stAlumno a);
void muestraMatricula(stAlumno a[], int v);
void intercambio (stAlumno *a, stAlumno *b);
void OrdenaPorSeleccion(stAlumno a[], int v);
void muestraXGenero(stAlumno a[], int v);
int insertaNuevoAlumno(stAlumno a[], int v);
int sumaPorGenero(stAlumno a[], int v, char genero);

int main()
{
    stAlumno alumnos[DIM];

    char opcion = 0;
    int validos = 0;
    char generos;

    while(opcion != 27)
    {
        system("cls");
        printf("\t\tTP estructuras");
        printf("\n1. Carga un arreglo de alumnos\n");
        printf("\n2. Muestra un arreglo de alumnos\n");
        printf("\n3. Muestra matricula de alumno\n");
        printf("\n4. Ordenamiento por seleccion, matricula\n");
        printf("\n5. Muestra alumnos por genero\n");
        printf("\n6. Insertar nuevo alumno\n");
        printf("\n7. Suma por genero\n");




        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case '1':
            validos = CargaArregloAlumnos(alumnos, DIM);
            break;

        case '2':
            muestraArregloAlumnos(alumnos, validos);
            break;
        case '3':
            muestraMatricula(alumnos, validos);
            break;
        case '4':
            OrdenaPorSeleccion(alumnos, validos);
            muestraArregloAlumnos(alumnos, validos);
            break;
        case '5':
            muestraXGenero(alumnos, validos);
            break;
        case '6':
            OrdenaPorSeleccion(alumnos,validos);
            validos = insertaNuevoAlumno(alumnos, validos);
            muestraArregloAlumnos(alumnos, validos);
            break;
        case '7':
            printf(">>Ingrese el genero a contar: \n");
            fflush(stdin);
            scanf("%c", &generos);
            system("cls");
            printf("La suma del genero %c es: %d", generos, sumaPorGenero(alumnos, validos, generos));
            muestraArregloAlumnos(alumnos, validos);
            break;
        default:
            printf("Error, no es una opcion valida");

        }
        opcion = getch();

    }
    return 0;
}


stAlumno CargaUnAlumno ()
{
    stAlumno alumno;

    printf("\nIngrese la matricula\n");
    scanf("%d", &alumno.matricula);

    printf("\nIngrese un nombre: \n");
    fflush(stdin);
    gets(alumno.nombre);

    printf("\nIngrese un genero (f/m/o): \n");
    fflush(stdin);
    scanf("%c", &alumno.genero);

    return alumno;
}


///Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
int CargaArregloAlumnos(stAlumno alumnos[], int dim)
{
    int i = 0;
    char opcion = 0;


    while(i<dim && opcion != 27)
    {
        alumnos[i] = CargaUnAlumno();
        system("cls");
        printf("\nIngrese cualquier tecla para continuar o ESC para salir\n");
        opcion = getch();
        i++;
    }


    return i;

}
//muestra 1 alumno
void muestraUnAlumno(stAlumno a)
{
    printf("\n      Matricula: %d\n", a.matricula);
    printf("\n      Nombre: %s\n", a.nombre);
    printf("\n      Nombre: %c\n", a.genero);
    puts("=================================================");
}
///mostrar stAlumno
void muestraArregloAlumnos(stAlumno alumnos[], int v)
{
    for(int i=0; i<v; i++)
    {
        printf("\n      Matricula: %d\n", alumnos[i].matricula);
        printf("\n      Nombre: %s\n", alumnos[i].nombre);
        printf("\n      Genero: %c\n", alumnos[i].genero);
        puts("=================================================");
    }
}
///Hacer una función que muestre por pantalla los datos de un alumno,
///conociendo su matrícula. Modularizar.
void muestraMatricula(stAlumno a[], int v)
{

    int i = 0;
    int matricula = 0;
    printf("Ingrese una matricula a buscar: \n");
    scanf("%d", &matricula);

    while(i<v && a[i].matricula != matricula)
    {
        i++;
    }
    if(a[i].matricula == matricula)
    {
        muestraUnAlumno(a[i]);
    }
    else
    {
        printf("La matricula no ha sido hallada");
    }
}
///Hacer una función que ordene el arreglo de alumnos por medio del método de selección.
///El criterio de ordenación es el número de matrícula.

void intercambio (stAlumno *a, stAlumno *b)
{

    stAlumno aux;
    aux = *a;
    *a = *b;
    *b = aux;



}
void OrdenaPorSeleccion(stAlumno a[], int v)
{
    int i;
    int j;


    for(i=0; i<v; i++)
    {
        for(j=i+1; j<v; j++)
        {
            if(a[j].matricula < a[i].matricula)
            {
                intercambio(&a[i], &a[j]);
            }
        }
    }

}
///Hacer una función que muestre por pantalla los datos de los estudiantes de un
///género determinado (se envía por parámetro). Modularizar.


void muestraXGenero(stAlumno a[], int v)
{
    int i = 0;
    char genero;
    int flag = 0;

    printf("Ingrese un genero a buscar: \n");
    fflush(stdin);
    scanf("%c", &genero);


    while(i<v)
    {
        if(genero == a[i].genero)
        {
            flag = 1;
            muestraUnAlumno(a[i]);
        }
        i++;
    }
    if(!flag)
    {
        printf("No se han hallado alumnos del genero buscado\n");
    }

    getch();


}
///Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato,
///conservando el orden.
int insertaNuevoAlumno(stAlumno a[], int v)
{

    int i = v;
    int j = i+1;

    stAlumno alumno;
    printf("Alumno a insertar\n");
    alumno = CargaUnAlumno();

    while(i>=0 && a[i].matricula> alumno.matricula)
    {
        intercambio(&a[j], &a[i]);
        i--;
        j--;
    }

    return v+1;
}

///Hacer una función que cuente y retorne la cantidad de estudiantes
///de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos

int sumaPorGenero(stAlumno a[], int v, char genero)
{
    int cuenta = 0;
    int i = 0;


    while(i<v)
    {
        if(a[i].genero == genero)
        {
            cuenta++;
        }
        i++;
    }

    return cuenta;

}
