

#ifndef zapa_h
#define zapa_h

typedef struct zap{
    char marca[50];
    char modelo[50];
    char color[50];
    int codigo;
    int talla;
} Zapato;

Zapato obtenerZapato(void);
void desplegarZapato(Zapato zap);


#endif
