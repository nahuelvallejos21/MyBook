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
      miMensaje->ID_MENSAJE = atoi(auxId);
      miMensaje->ID_USUARIO = atoi(idUsu);
      miMensaje->POPULARIDAD = atoi(auxPopu);
      strcpy(miMensaje->MENSAJE,auxMensaje);

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
      printf("%d\t%d\t%d\n",auxMsj->ID_MENSAJE,auxMsj->ID_USUARIO,auxMsj->POPULARIDAD);
      printf("MENSAJE\n");
      printf("%s\n",auxMsj->MENSAJE);
    }
  }
}














