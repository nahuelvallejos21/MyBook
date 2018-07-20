struct
{
  int ID_MENSAJE;
  char MENSAJE[3000];
  int POPU_MENSAJE;
  int ID_USUARIO;
  char NICK[30];
  int POPU_USUARIO;

}typedef eFeed;
eFeed* new_feed(void);
ArrayList* crear_Feed(ArrayList*,ArrayList*);

void mostrarFeed(ArrayList*);
int comparar_Feed(void*,void*);
void listarFeed(ArrayList*);
