
#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "feed.h"
#include "mensaje.h"
#include "usuario.h"
#include "string.h"
#include "conio.h"

eFeed* new_feed()
{
  eFeed* aux;
  aux = (eFeed*)malloc(sizeof(eFeed));
  return aux;
}
int set_eFeedID_USU(eFeed*this,int id)
{
  int retorno = 0;
  if(this!=NULL && id>=0)
  {
    this->ID_USUARIO = id;
    retorno = 1;
  }
  return retorno;
}
int set_eFeedNICK(eFeed* this,char* nick)
{
  int retorno = 0;
  if(this!=NULL && strlen(nick)>=3)
  {
    strcpy(this->NICK,nick);
    retorno = 1;
  }
  return retorno;
}
int set_eFeedFOLLOW(eFeed*this,int follow)
{
   int retorno = 0;
   if(this!=NULL && follow>=0)
   {
     this->POPU_USUARIO = follow;
     retorno = 1;
   }
   return retorno;
}
int set_eFeedID_MSJ(eFeed*this,int id)
{
  int retorno = 0;
  if(this!=NULL && id>=0)
  {
    this->ID_MENSAJE = id;
    retorno = 1;
  }
  return retorno;
}
int set_eFeedMSJ(eFeed* this,char* msj)
{
  int retorno = 0;
  if(this!=NULL && strlen(msj)>3)
  {
    strcpy(this->MENSAJE,msj);
    retorno = 1;
  }
  return retorno;
}
int set_eFeedLIKE(eFeed* this,int like)
{
  int retorno = 0;
  if(this!=NULL && like>=0)
  {
    this->POPU_MENSAJE = like;
    retorno = 1;
  }
  return retorno;
}
int get_eFeedID_USU(eFeed*this)
{
   int aux;
   if(this!=NULL)
   {
     aux = this->ID_USUARIO;
   }
   return aux;
}
char* get_eFeedNICK(eFeed*this)
{
  char* aux;
  if(this!=NULL)
  {
    aux = this->NICK;
  }
  return aux;
}
int get_eFeedFOLLOW(eFeed*this)
{
  int aux;
  if(this!=NULL)
  {
    aux = this->POPU_USUARIO;
  }
  return aux;
}
int get_eFeedID_MSJ(eFeed*this)
{
  int aux;
  if(this!=NULL)
  {
    aux = this->ID_MENSAJE;
  }
  return aux;
}
char* get_eFeedMSJ(eFeed*this)
{
  char* aux;
  if(this!=NULL)
  {
    aux = this->MENSAJE;
  }
  return aux;
}
int get_eFeedLIKE(eFeed*this)
{
  int aux;
  if(this!=NULL)
  {
   aux = this->POPU_MENSAJE;
  }
  return aux;
}
ArrayList* crear_Feed(ArrayList* lista, ArrayList* lista2)
{
  eFeed* miFeed;
  eUsuario* miUsuario;
  eMensaje* miMensaje;
  int i,j;
  ArrayList* newList;

  if(lista!=NULL && lista!=NULL)
  {
    newList = al_newArrayList();
    if(newList!=NULL)
    {
      for(i=0;i<al_len(lista);i++)
      {
        for(j=0;j<al_len(lista2);j++)
        {
          miUsuario = (eUsuario*)al_get(lista,i);
          miMensaje = (eMensaje*)al_get(lista2,j);
          if(miUsuario->ID_USUARIO == miMensaje->ID_USUARIO)
          {
             miFeed = new_feed();
             if(miFeed!=NULL)
             {
               set_eFeedID_MSJ(miFeed,get_eMensajeID(miMensaje));
               set_eFeedMSJ(miFeed,get_eMensajeMSJ(miMensaje));
               set_eFeedLIKE(miFeed,get_eMensajePOPU(miMensaje));
               set_eFeedID_USU(miFeed,get_eUsuarioID(miUsuario));
               set_eFeedNICK(miFeed,get_eUsuarioNICK(miUsuario));
               set_eFeedFOLLOW(miFeed,get_eUsuarioPOPU(miUsuario));

               al_add(newList,miFeed);
              }
          }
        }
      }

    }

   }
   return newList;
}
void mostrarFeed(ArrayList* this)
{
  eFeed* aux;
  int i;

  if(this!=NULL)
  {
    for(i=0;i<al_len(this);i++)
    {
      aux = (eFeed*)al_get(this,i);
      printf("ID\tUSUARIO\tFOLLOWERS\tLIKES\n");
      printf("%d\t%s\t%d\t%d\n",get_eFeedID_USU(aux),get_eFeedNICK(aux),get_eFeedFOLLOW(aux),get_eFeedLIKE(aux));
      printf("ID MSJ: %d\n",get_eFeedID_MSJ(aux));
      printf("%s\n",get_eFeedMSJ(aux));

    }
  }
}
int comparar_Feed(void* feed1 ,void* feed2)
{
   int retorno = 0;
   eFeed* f1;
   eFeed* f2;
   if(feed1!=NULL && feed2!=NULL)
   {
      f1 = (eFeed*)feed1;
      f2 = (eFeed*)feed2;
      if(get_eFeedFOLLOW(f1) < get_eFeedFOLLOW(f2))
      {
        retorno = -1;
      }
      if(get_eFeedFOLLOW(f1)== get_eFeedFOLLOW(f2))
      {
        if(get_eFeedLIKE(f1) < get_eFeedLIKE(f2))
        {
          retorno = -1;
        }
      }
    }
    return retorno;
}
void listarFeed(ArrayList* this)
{
  int i;
  eFeed* aux;
  FILE* lista;

  if(al_sort(this,comparar_Feed,0)==0)
  {

    lista = fopen("feed.csv","w");
    if(lista!=NULL)
    {
      fprintf(lista,"ID,USUARIO,FOLLOWERS,LIKES,ID MSJ,MENSAJE\n");
      for(i=0;i<al_len(this);i++)
      {
         aux = (eFeed*)al_get(this,i);
         fprintf(lista,"%d,%s,%d,%d,%d,%s\n",get_eFeedID_USU(aux),get_eFeedNICK(aux),get_eFeedFOLLOW(aux),get_eFeedLIKE(aux),get_eFeedID_MSJ(aux),get_eFeedMSJ(aux));
      }
      fclose(lista);
      printf("FEED CREADO CON EXITO....\n");
    }

  }
  else
  {
    printf("ERROR\n");
  }
}
