
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
               miFeed->ID_MENSAJE = miMensaje->ID_MENSAJE;
               strcpy(miFeed->MENSAJE,miMensaje->MENSAJE);
               miFeed->POPU_MENSAJE = miMensaje->POPULARIDAD;
               miFeed->ID_USUARIO = miUsuario->ID_USUARIO;
               strcpy(miFeed->NICK,miUsuario->NICK);
               miFeed->POPU_USUARIO = miUsuario->POPULARIDAD;

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
      printf("%d\t%s\t%d\t%d\n",aux->ID_USUARIO,aux->NICK,aux->POPU_USUARIO,aux->POPU_MENSAJE);
      printf("ID MSJ: %d\n",aux->ID_MENSAJE);
      printf("%s\n",aux->MENSAJE);

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
      if(f1->POPU_USUARIO < f2->POPU_USUARIO)
      {
        retorno = -1;
      }
      if(f1->POPU_USUARIO == f2->POPU_USUARIO)
      {
        if(f1->POPU_MENSAJE < f2->POPU_MENSAJE)
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
         fprintf(lista,"%d,%s,%d,%d,%d,%s\n",aux->ID_USUARIO,aux->NICK,aux->POPU_USUARIO,aux->POPU_MENSAJE,aux->ID_MENSAJE,aux->MENSAJE);
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
