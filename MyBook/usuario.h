
struct
{
  int ID_USUARIO;
  char NICK[30];
  int POPULARIDAD;


}typedef eUsuario;

eUsuario* new_usuario(void);
int leer_Usuarios(FILE*,ArrayList*);
void mostrarUsuarios(ArrayList*);

//Seters
int set_eUsuarioID(eUsuario*,int);
int set_eUsuarioNICK(eUsuario*,char*);
int set_eUsuarioPOPU(eUsuario*,int);
//Geters
int get_eUsuarioID(eUsuario*);
char* get_eUsuarioNICK(eUsuario*);
int get_eUsuarioPOPU(eUsuario*);
