#include <Cola.h>


void crear_cola(t_cola* pcola)
{
    pcola->pri = 0;
    pcola->ult = -1;
    pcola->ce = 0;
}

int poner_en_cola(t_cola* pcola, const t_dato* pd)
{
    if(TAM == pcola->ce)
        return 0;

    pcola->ult++;
    if(pcola->ult == TAM)
        pcola->ult = 0;

    (pcola->vcola[pcola->ult]) = *pd;
    pcola->ce++;

    return 1;

}

int sacar_de_cola(t_cola* pcola, t_dato* pd)
{
    if(pcola->ce == 0)
        return 0;

    *pd = pcola->vcola[pcola->pri];
    pcola->ce--;

    pcola->pri++;
    if(pcola->pri ==TAM)
        pcola->pri = 0;

    return 1;
}

int frente_de_cola(const t_cola* pcola, t_dato* pd)
{
    if(pcola->ce == 0)
        return 0;
    *pd = pcola->vcola[pcola->pri];

    return 1;
}

int cola_vacia(const t_cola* pcola)
{
    return pcola->ce == 0;
}
int cola_llena(const t_cola* pcola)
{
    return pcola->ce == TAM;
}

void vaciar_cola(t_cola* pcola)
{
    pcola->pri = 0;
    pcola->ult = -1;
    pcola->ce = 0;
}
