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

//Seters
int set_eFeedID_USU(eFeed*,int);
int set_eFeedNICK(eFeed*,char*);
int set_eFeedFOLLOW(eFeed*,int);
int set_eFeedID_MSJ(eFeed*,int);
int set_eFeedMSJ(eFeed*,char*);
int set_eFeedLIKE(eFeed*,int);

//Geters
int get_eFeedID_USU(eFeed*);
char* get_eFeedNICK(eFeed*);
int get_eFeedFOLLOW(eFeed*);
int get_eFeedID_MSJ(eFeed*);
char* get_eFeedMSJ(eFeed*);
int get_eFeedLIKE(eFeed*);
