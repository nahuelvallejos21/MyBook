
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
int set_eUsuarioID(eUsuario* this,int id)
{
  int retorno = 0;
  if(this!=NULL && id>=0)
  {
    this->ID_USUARIO = id;
    retorno = 1;
  }
  return retorno;
}
int set_eUsuarioNICK(eUsuario* this,char* nick)
{
  int retorno = 0;
  if(this!=NULL && strlen(nick)>=3)
  {
    strcpy(this->NICK,nick);
    retorno = 1;
  }
  return retorno;
}
int set_eUsuarioPOPU(eUsuario* this,int follow)
{
   int retorno = 0;
   if(this!=NULL && follow>=0)
   {
     this->POPULARIDAD = follow;
     retorno = 1;
   }
   return retorno;
}
int get_eUsuarioID(eUsuario* this)
{
   int aux;
   if(this!=NULL)
   {
     aux = this->ID_USUARIO;
   }
   return aux;
}
char* get_eUsuarioNICK(eUsuario*this)
{
  char* aux;
  if(this!=NULL)
  {
    aux = this->NICK;
  }
  return aux;
}
int get_eUsuarioPOPU(eUsuario*this)
{
  int aux;
  if(this!=NULL)
  {
    aux = this->POPULARIDAD;
  }
  return aux;
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
         set_eUsuarioID(miUsuario,atoi(auxId));
         set_eUsuarioNICK(miUsuario,auxNick);
         set_eUsuarioPOPU(miUsuario,atoi(auxPopu));
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
      printf("%d\t%s\t%d\n",get_eUsuarioID(auxUsu),get_eUsuarioNICK(auxUsu),get_eUsuarioPOPU(auxUsu));
    }
   }
}
