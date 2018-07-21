#include "stdio.h"
#include <stdlib.h>
#include "arraylist.h"
#include "mensaje.h"

#include "string.h"
#include "conio.h"

eMensaje* new_msj()
{
  eMensaje* auxMsj;
  auxMsj = (eMensaje*)malloc(sizeof(eMensaje));
  return auxMsj;


}
int set_eMensajeID(eMensaje* this,int id)
{
  int retorno = 0;
  if(this!=NULL && id>=0)
  {
    this->ID_MENSAJE = id;
    retorno = 1;
  }
  return retorno;
}
int set_eMensajeMSJ(eMensaje* this, char* msj)
{
  int retorno = 0;
  if(this!=NULL && strlen(msj)>3)
  {
    strcpy(this->MENSAJE,msj);
    retorno = 1;
  }
  return retorno;
}
int set_eMensajePOPU(eMensaje* this,int like)
{
  int retorno = 0;
  if(this!=NULL && like>=0)
  {
    this->POPULARIDAD = like;
    retorno = 1;
  }
  return retorno;
}
int set_eMensajeIDUSU(eMensaje* this,int idUsu)
{
  int retorno = 0;
  if(this!=NULL && idUsu>=0)
  {
    this->ID_USUARIO = idUsu;
    retorno = 1;
  }
  return retorno;
}
int get_eMensajeID(eMensaje*this)
{
  int aux;
  if(this!=NULL)
  {
    aux = this->ID_MENSAJE;
  }
  return aux;
}
char* get_eMensajeMSJ(eMensaje*this)
{
  char* aux;
  if(this!=NULL)
  {
    aux = this->MENSAJE;
  }
  return aux;
}
int get_eMensajePOPU(eMensaje* this)
{
  int aux;
  if(this!=NULL)
  {
   aux = this->POPULARIDAD;
  }
  return aux;
}
int get_eMensajeIDUSU(eMensaje*this)
{
  int aux;
  if(this!=NULL)
  {
    aux = this->ID_USUARIO;
  }
  return aux;
}
int leer_Mensajes(FILE* archivo,ArrayList* this)
{
  char auxId[500];
  char auxMensaje[3000];
  char auxPopu[500];
  char idUsu[500];
  eMensaje* miMensaje;
  int retorno;

  if(archivo==NULL || this==NULL)
  {
    retorno = -1;
  }
  while(!feof(archivo))
  {
    fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n",auxId,idUsu,auxPopu,auxMensaje);
    miMensaje = new_msj();
    if(miMensaje!=NULL)
    {
      set_eMensajeID(miMensaje,atoi(auxId));
      set_eMensajeIDUSU(miMensaje,atoi(idUsu));
      set_eMensajePOPU(miMensaje,atoi(auxPopu));
      set_eMensajeMSJ(miMensaje,auxMensaje);

      al_add(this,miMensaje);
      retorno = 0;


    }

  }
  return retorno;
}
void mostrarMensajes(ArrayList* this)
{
  eMensaje* auxMsj;
  int i;
  if(this!=NULL)
  {
    for(i=0;i<al_len(this);i++)
    {
      auxMsj = (eMensaje*)al_get(this,i);
      printf("ID MSJ\tID USU\tLIKES\n");
      printf("%d\t%d\t%d\n",get_eMensajeID(auxMsj),get_eMensajeIDUSU(auxMsj),get_eMensajePOPU(auxMsj));
      printf("MENSAJE\n");
      printf("%s\n",get_eMensajeMSJ(auxMsj));
    }
  }
}














