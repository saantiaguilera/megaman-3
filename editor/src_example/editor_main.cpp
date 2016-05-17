#include <string>
#include <stdio.h>
#include <iostream>
#define SALIDA_EXITOSA 0
#define ERROR 1
#define PARAMETROS 1
#include "../../Common/src/constantes.h"
#include "editor_EditorDeNiveles.h"

int main(int argc, char **argv) {
	//Empecemos ya usando bien los archivos. mandemos todo por argv asi no tenemos problemas despues
	if(argc != PARAMETROS) return ERROR;
	EditorDeNiveles editor;
	Gtk::Main kit(argc, argv);
	std::string rutaVentana = RUTA_SERVER_EDITOR "/Editor.glade";//Poner el original
	editor.iniciarInterfaz(rutaVentana.c_str());
	return SALIDA_EXITOSA;
}

