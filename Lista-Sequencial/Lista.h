typedef struct{
    int *dados;
    int n;
    int nmax;
} tlista;

extern void cria_lista (tlista *lista, int tam) ;
extern int verifica_vazia (tlista *lista) ;
extern int verifica_cheia (tlista *lista) ;
extern int tamanho (tlista *lista) ;
extern int obter_elemento (tlista *lista, int pos) ;
extern int obter_posicao (tlista *lista, int dado) ;
extern int insere (tlista *lista, int pos , int dado) ;
extern int retira (tlista *lista, int pos) ;
extern void exibir (tlista *lista);
