#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "feed.h"
#include "mensaje.h"
#include "usuario.h"

int main()
{
  ArrayList* lista;
  ArrayList* lista2;
  ArrayList* lista3;
  FILE* archivo;
  FILE* archivo2;
  int todoOk;
  char seguir = 's';
  int opcion;
  int tam;

  lista = al_newArrayList();
  lista2 = al_newArrayList();


  if(lista!=NULL && lista2!=NULL)
  {
    archivo = fopen("mensajes.csv","r");
    archivo2 = fopen("usuarios.csv","r");

    todoOk = leer_Mensajes(archivo,lista) + leer_Usuarios(archivo2,lista2);

    if(todoOk==0)
    {
      printf("Datos cargados.......\n");

    }
    else
    {
      printf("ERROR!, al cargar los datos");
    }
    while(seguir == 's')
    {
      printf("1-Mostrar usuarios\n");
      printf("2-Mostrar publicaciones\n");
      printf("3-Mostrar feed\n");
      printf("4-Salir\n");

      scanf("%d",&opcion);

      switch(opcion)
      {
        case 1:
            mostrarUsuarios(lista2);
            break;
       case 2:
            mostrarMensajes(lista);
            break;
       case 3:
            lista3 = crear_Feed(lista2,lista);
            listarFeed(lista3);
            break;
       case 4:
            seguir = 'n';
            break;



      }


    }

  }

  return 0;
}
