#ifndef NOTA_H
#define NOTA_H


typedef struct
{
	int dni;
	char apyn[51];
	char materia[31];
	char codigo_nota[3]; ///PR = Promocion�, CU = Curs�, RE = Reprob�, AU = Ausente
	int nota;
}
t_nota;


#endif // NOTA_H
