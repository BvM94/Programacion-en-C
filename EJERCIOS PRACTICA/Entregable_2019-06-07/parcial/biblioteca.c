#include <biblioteca.h>
#include <utilitarias.h>
#include <string.h>
#include <lista.h>
void actualizar_stock(FILE * arch_libros, FILE * arch_stock, FILE * arch_err)
{
    t_libro libro;
    t_libro_stock libro_stock;
    char reg_stock [200];
    char * retorno;
    t_lista lista;
    int ret;

    crear_lista(&lista);

    fread(&libro,sizeof(t_libro),1,arch_libros);
    retorno = fgets(reg_stock,200,arch_stock);

    while( !feof(arch_libros) && retorno )
    {
        texto_a_stock(reg_stock,&libro_stock);

        if(isbn_valido(libro_stock.isbn))   //reemplazar por la mia
        {
            if(strcmp(libro.isbn,libro_stock.isbn)>0)
            {
                fprintf(arch_err,"%s, ingreso:%d - Libro inexistente\n",libro_stock.isbn,libro_stock.stock);
                retorno = fgets(reg_stock,200,arch_stock);
            }
            if(strcmp(libro.isbn,libro_stock.isbn)<0)
            {
                instertar_prim5_lista(&lista,&libro,cmp_stock_libro);
                fseek(arch_libros,-sizeof(t_libro),SEEK_CUR);
                fwrite(&libro,sizeof(t_libro),1,arch_libros);
                fseek(arch_libros,0L,SEEK_CUR);
                fread(&libro,sizeof(t_libro),1,arch_libros);
            }
            else
            {
                libro.stock+=libro_stock.stock;
                retorno = fgets(reg_stock,200,arch_stock);
            }
        }
        else
        {
            fprintf(arch_err,"%s, ingreso:%d - Error de ISBN\n",libro_stock.isbn,libro_stock.stock);
            retorno = fgets(reg_stock,200,arch_stock);
        }
    }
    while( !feof(arch_libros))
    {
        instertar_prim5_lista(&lista,&libro,cmp_stock_libro);
        fread(&libro,sizeof(t_libro),1,arch_libros);
    }
    while(retorno)
    {
        texto_a_stock_res(reg_stock,&libro_stock);
        if(isbn_valido(libro_stock.isbn))   //reemplazar por la mia
            fprintf(arch_err,"%s, ingreso:%d - Libro inexistente\n",libro_stock.isbn,libro_stock.stock);
        else
            fprintf(arch_err,"%s, ingreso:%d - Error de ISBN\n",libro_stock.isbn,libro_stock.stock);

        retorno = fgets(reg_stock,200,arch_stock);
    }

    puts("************* INICIO TOP 5 LIBROS DE STOCK **************\n");
    printf("%-17s %-60s %-20s %s\n","ISBN","TITULO","AUTOR", "STOCK" );

    ret = sacar_primero_lista_res(&lista,&libro);
    while(ret)
    {
        printf("%-17s %-60s %-20s %3d\n",libro.isbn,libro.titulo,libro.autor, libro.stock );
        ret = sacar_primero_lista_res(&lista,&libro);
    }
    puts("\n\n************* FIN TOP 5 LIBROS DE STOCK **************\n");

}

int cmp_stock_libro(const t_libro * l1, const t_libro * l2)
{
    return l1->stock - l2->stock;
}


/*Validación del ISBN:
978 - <El código de país o lengua de origen (2 d.)> - <el editor (3 d.)> - <el número del artículo (4 d.)> - <verificador (1 d.)>.
Y el dígito verificador se calcula de manera que:
<suma de las cifras de lugares impares> + 3* <suma de las cifras de lugares pares> De múltiplo de 10.
Los dígitos los numeramos de izquierda a derecha empezando por el número 1, sin tener en cuenta los guio-nes.

*/
int isbn_valido(const char * isbn)
{
    char * pc = (char*)isbn;
    int sumP=0,sumI=0,i,cont=1;
    char dig;


    if(*pc != '9' || *(++pc) != '7' || *(++pc) != '8')// *(++pc) != '-')
        return 0;

    pc++;
    if(*pc != '-')
        return 0;

    pc++;

    for(i=1; i<=2; i++,pc++)
    {
        if(!ES_NUMERO(*pc))
            return 0;
    }

    if(*pc != '-')
        return 0;

    pc++;

    for(i=1; i<=3; i++,pc++)
    {
        if(!ES_NUMERO(*pc))
            return 0;
    }
    if(*pc != '-')
        return 0;

    pc++;

    for(i=1; i<=4; i++,pc++)
    {
        if(!ES_NUMERO(*pc))
            return 0;
    }

    if(*pc != '-')
        return 0;

    pc++;

    if(!ES_NUMERO(*pc))
        return 0;

    pc = (char*)isbn;

    for(i=1; i<=17; i++,pc++)
    {
        if(ES_NUMERO(*pc))
        {
            dig = *pc;
            if(cont%2 == 0)
                sumP += atoi(&dig);
            else
                sumI += atoi(&dig);

            cont++;
        }
    }

    return (((sumI+ 3*sumP)%10 == 0)? 1:0);
}
