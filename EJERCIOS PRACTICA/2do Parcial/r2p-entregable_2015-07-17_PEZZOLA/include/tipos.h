#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED


#define TODO_OK 0
#define SIN_MEM 1
#define ERROR_ARCHIVO 2
#define DUPLICADO 3
#define NO_EXISTE 4
#define VERDADERO 1
#define FALSO 0


typedef struct
{
	int dni;
	char apyn[30];
	int notas[50];
	int cant_materias;
}
t_alumno;


typedef t_alumno t_info;



#endif // TIPOS_H_INCLUDED
