
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
//Setters
int set_eMensajeID(eMensaje*,int);
int set_eMensajeMSJ(eMensaje*,char*);
int set_eMensajePOPU(eMensaje*,int);
int set_eMensajeIDUSU(eMensaje*,int);
//Getters
int get_eMensajeID(eMensaje*);
char* get_eMensajeMSJ(eMensaje*);
int get_eMensajePOPU(eMensaje*);
int get_eMensajeIDUSU(eMensaje*);
