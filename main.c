#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define MAX_ALUMNOS 10
#define TAMANO_NOMBRE 50
#define ALTA 1
#define BAJA 2
#define CAMBIO 3
#define MOSTRAR 4
#define LISTAR 5
#define SALIR 6
typedef enum {FALSO,VERDADERO} booleano;

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;
typedef struct
{
    char nombre[TAMANO_NOMBRE+1];
    int codigo;
    int edad;
    float aportacionVoluntaria;
    Fecha fechaNacimiento;
} Persona;

Persona alumnos[MAX_ALUMNOS];

void agregarAlumno();
void cambiarDatosDeAlumno();
int seleccionarOpcion();
void darDeBajaAlumno();
void mostrarListaDeAlumnos();
void limpiarRegistroAlumno();
void listarAlumnos();

int main()
{
    booleano salidaDePrograma=VERDADERO;
    do
    {
        switch(seleccionarOpcion())
        {
        case ALTA:
            agregarAlumno();
            break;
        case BAJA:
            darDeBajaAlumno();
            break;
        case CAMBIO:
            cambiarDatosDeAlumno();
            break;
        case MOSTRAR:
            mostrarListaDeAlumnos();
            break;
        case LISTAR:
            listarAlumnos();
            break;
        case SALIR:
            salidaDePrograma=FALSO;
            break;
        default:
            printf("Opcion no valida!\n");
        }
        salidaDePrograma?5:0;
    }
    while(salidaDePrograma);
    return 0;
}

int seleccionarOpcion()
{
    int opc;
    printf("Registro de alumnos UdeG\n");
    printf("\n");
    printf("1. Alta de nuevo alumno\n");
    printf("2. Baja de alumno\n");
    printf("3. Cambio de datos del alumno\n");
    printf("4. Listado de profesores\n");
    printf("5. Salir\n");
    printf("Opcion: ");
    scanf("%d",&opc);
    return opc;
}

void agregarAlumno()
{
    int i;
    printf("AGREGAR ALUMNO NUEVO\n\n");
    for(i=0; i<MAX_ALUMNOS; i++)
    {
        cambiarDatosDeAlumno();
    }

}

void cambiarDatosDeAlumno()
{
    int i;
    printf("Ingrese los datos para el registro %d.\n",i+1);
    printf("Codigo:");
    scanf("%d",&alumnos[i].codigo);
    printf("Nombre:");
    getchar();
    gets(alumnos[i].nombre);
    printf("Edad:");
    scanf("%d",&alumnos[i].edad);
    printf("Aportación Voluntaria");
    scanf("%f",&alumnos[i].aportacionVoluntaria);
    printf("Fecha nacimiento dd/mm/aaaa:");
    scanf("%d/%d/%d",&alumnos[i].fechaNacimiento.dia,
          &alumnos[i].fechaNacimiento.mes,
          &alumnos[i].fechaNacimiento.anio);
}

void limpiarRegistroAlumno()
{
    int i
    alumnos[i].codigo=0;
    strcpy(alumnos[i].nombre,"");
    strcpy(alumnos[i].edad,"");
    alumnos[i].aportacionVoluntaria=0;
    alumnos[i].fechaNacimiento.anio=0;
    alumnos[i].fechaNacimiento.mes=0;
    alumnos[i].fechaNacimiento.dia=0;
}

void darDeBajaAlumno()
{
    int i;
    char opcion;
    printf("Dar de baja a alumno\n\n");
    printf("Ingresa el numero del registro a eliminar (1 a %d): ",MAX_ALUMNOS);
    scanf("%d",&i);
    i--;
    printf("\n");
    mostrarListaDeAlumnos(i);
    printf("\nEstas seguro de eliminar el registro (s/n)?");
    getchar();
    scanf("%c",&opcion);
    if (opcion=='S' || opcion=='s')
    {
        limpiarRegistroAlumno(i);
        printf("Registro eliminado!\n");
    }
    else
    {
        printf("Registro conservado!\n");
    }

}

void mostrarListaDeAlumnos()
{
    int i=indice;
    printf("Registro %d:\n",i+1);
    printf("Codigo=%d\n",alumnos[i].codigo);
    printf("Nombre=%s\n",alumnos[i].nombre);
    printf("Edad=%d\n",alumnos[i].edad);
    printf("Aportación voluntaria=%.2f\n",alumnos[i].aportacionVoluntaria);
    printf("Fecha nacimiento=%02d/%02d/%04d\n",alumnos[i].fechaNacimiento.dia,
           alumnos[i].fechaNacimiento.mes,alumnos[i].fechaNacimiento.anio);
}

void listarAlumnos()
{
    printf("Listado de alumnos\n\n");
    int i;
    printf("#\tCodigo\tNombre\n");
    for(i=0; i<MAX_ALUMNOS; i++)
    {
        printf("%d\t",i+1);
        printf("%d\t",alumnos[i].codigo);
        printf("%s\n",alumnos[i].nombre);

    }

}
