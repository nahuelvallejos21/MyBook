
#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "usuario.h"
#include "string.h"
#include "conio.h"

eUsuario* new_usuario()
{
  eUsuario* auxUsu;
  auxUsu = (eUsuario*)malloc(sizeof(eUsuario));
  return auxUsu;
}
int leer_Usuarios(FILE* archivo,ArrayList* this)
{
   char auxId[50];
   char auxNick[50];
   char auxPopu[50];
   eUsuario* miUsuario;
   int retorno;
   if(archivo==NULL || this==NULL)
   {
     retorno = -1;
   }
   while(!feof(archivo))
   {
     fscanf(archivo,"%[^,],%[^,],%s\n",auxId,auxNick,auxPopu);
     miUsuario = new_usuario();
     if(miUsuario!=NULL)
     {
       if(strcmp(auxId,"id")!=0 && strcmp(auxNick,"nick")!=0 && strcmp(auxPopu,"followers")!=0)
       {
         miUsuario->ID_USUARIO = atoi(auxId);
         strcpy(miUsuario->NICK,auxNick);
         miUsuario->POPULARIDAD = atoi(auxPopu);
         al_add(this,miUsuario);
         retorno = 0;
       }

     }
    }

   return retorno;
}
void mostrarUsuarios(ArrayList* this)
{
  eUsuario* auxUsu;
  int i;
  if(this!=NULL)
  {
    printf("ID\tNICK\tFOLLOWERS\n");
    for(i=0;i<al_len(this);i++)
    {
      auxUsu = (eUsuario*)al_get(this,i);
      printf("%d\t%s\t%d\n",auxUsu->ID_USUARIO,auxUsu->NICK,auxUsu->POPULARIDAD);
    }
   }
}
