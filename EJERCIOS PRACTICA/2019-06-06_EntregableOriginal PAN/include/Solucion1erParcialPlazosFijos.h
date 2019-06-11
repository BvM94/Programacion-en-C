#ifndef SOLUCION1ERPARCIALPLAZOSFIJOS_H
#define SOLUCION1ERPARCIALPLAZOSFIJOS_H


void cargarListaPF(FILE* plazosFijosTxt, t_lista* plazosFijosList);
void cargarListaPF_res(FILE* plazosFijosTxt, t_lista* plazosFijosList);
void procesarPF(FILE* cuentasDat, t_lista* plazosFijosList, t_fecha* fechaProceso);
void procesarPF_res(FILE* cuentasDat, t_lista* plazosFijosList, t_fecha* fechaProceso);
void generarArchivos(const char* nombreCuentas, const char* nombrePlazosFijos);
void mostrarCuentas(const char* nombreArchCuentas);
void mostrarCuenta(const t_cuenta* cuenta);


#endif // SOLUCION1ERPARCIALPLAZOSFIJOS_H
