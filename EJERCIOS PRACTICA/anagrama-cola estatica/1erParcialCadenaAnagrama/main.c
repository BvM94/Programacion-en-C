
#include <Cadena.h>



int main()
{
	char linea[TAM];
	char *palabra1 = linea, *palabra2, *finLinea;
	FILE* archAnagramas = fopen("../ArchivosDeTest/Anagramas.txt", "rt");

	if(!archAnagramas)
	{
		puts("archivo inexistente");
		return ERROR_ARCHIVO;
	}

	fgets(linea,TAM,archAnagramas);

	while(!feof(archAnagramas))
    {
        finLinea=mistrchr(linea,'\n');
        *finLinea='\0';
        palabra2=mistrchr(linea,'|');
        *palabra2='\0';
        palabra2++;

        if(son_anagramas_res(palabra1,palabra2))
            printf("%s y %s son anagramas\n",palabra1,palabra2);
        else
            printf("%s y %s NO son anagramas\n",palabra1,palabra2);

    fgets(linea,TAM,archAnagramas);
    }

	return 0;
}
