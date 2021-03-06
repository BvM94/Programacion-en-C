#include<utilitarias.h>

int alta (t_alumno * alu, FILE * arch, t_arbol* pa)
{
    ///Escriba aqui el codigo...

    fseek(arch,0L,SEEK_END);
    t_reg_ind ind;
    ind.nro_reg = ftell(arch)/sizeof(t_alumno);
    ind.dni = alu->dni;
    alu->estado = 'A';

    int ret = insertar_en_arbol_bin_busq(pa,&ind,comparar_ind);
    if(ret != TODO_OK)
        return ret;

    fwrite(alu,sizeof(t_alumno),1,arch);
    actualizar_arch_indices(pa);
    return TODO_OK;
}

int baja (t_alumno * alu, FILE * arch, t_arbol* pa)
{
    ///Escriba aqui el codigo...
    t_info ind;
    ind.dni = alu->dni;
    int ret = eliminar_de_arbol(pa,&ind,comparar_ind);
    if(ret != TODO_OK)
        return ret;

    fseek(arch,sizeof(t_alumno)*ind.nro_reg,SEEK_SET);
    fread(alu,sizeof(t_alumno),1,arch);
    fseek(arch,sizeof(t_alumno)*ind.nro_reg,SEEK_SET);

    alu->estado = 'B';
    fwrite(alu,sizeof(t_alumno),1,arch);

    actualizar_arch_indices(pa);

    return TODO_OK;
}


int comparar_ind(const t_info* d1, const t_info* d2)
{
    return d1->dni - d2->dni;
}

 void imprimir_indice(const t_info* pinfo)
 {
     printf("Dni: %d - Nro reg: %d ",pinfo->dni,pinfo->nro_reg);
 }


 void crear_archivo_indice()
 {
     FILE * arch;
     arch = fopen("../archivos/alumnosIndice.dat","wb");
     if(!arch)
        return;

     t_reg_ind vecReg[]={{9111111,1},{9222222,3},{11111111,0},{33333333,4},{55555555,2}};

     fwrite(&vecReg,sizeof(vecReg),1,arch);

    fclose(arch);
 }


 void actualizar_arch_indices(t_arbol *pa)
 {
     FILE * arch = fopen("../archivos/alumnos.idx", "wb");
     if(!arch)
        return;

     recorrer_Enorden(pa,grabar_arch_indice,arch);

    fclose(arch);
 }

 void grabar_arch_indice (t_info* pinfo, void* datos_accion)
 {
     FILE * arch_indices = (FILE*)datos_accion;
     fseek(arch_indices,0l,SEEK_END);
     fwrite(pinfo,sizeof(t_reg_ind),1,arch_indices);
 }
