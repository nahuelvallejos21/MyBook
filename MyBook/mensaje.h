
struct
{
  int ID_MENSAJE;
  char MENSAJE[3000];
  int POPULARIDAD;
  int ID_USUARIO;

}typedef eMensaje;

eMensaje* new_msj(void);
int leer_Mensajes(FILE*,ArrayList*);
void mostrarMensajes(ArrayList*);
