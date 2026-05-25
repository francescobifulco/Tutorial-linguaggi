#include "Wrapper.h"

typedef struct restrituzioni{
    char dataPrestito[10];
    char dataScadenza[10];
    char codiceFiscale[16];
    char nomeLibro[200];
    char autoreLibro[200];
} restrituzioni;

typedef struct prestiti{
    char dataScadenza[10];
    char codiceFiscale[16];
    char nomeLibro[200];
    char autoreLibro[200];
} prestiti;

void creareFileNoEsiste(){
    if (_access("restituzioni.txt", 0)){
        fopen("restituzioni.txt", "w");
    }

    if (_access("prestiti.txt", 0)){
        fopen("prestiti.txt", "w");
    }
}
