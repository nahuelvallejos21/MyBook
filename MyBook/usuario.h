
struct
{
  int ID_USUARIO;
  char NICK[30];
  int POPULARIDAD;


}typedef eUsuario;

eUsuario* new_usuario(void);
int leer_Usuarios(FILE*,ArrayList*);
void mostrarUsuarios(ArrayList*);
