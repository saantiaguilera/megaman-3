/*
 * ElementoVista.h
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#ifndef EDITOR_SRC_ELEMENTOS_ELEMENTOVISTA_H_
#define EDITOR_SRC_ELEMENTOS_ELEMENTOVISTA_H_
#include "../../../Common/src/Elemento.h"
#include <gtkmm.h>
#include <string>

class ElementoVista{
protected:
	Gtk::Image* imagen;
	std::string rutaImagen;
	Elemento* elemento;
public:
	ElementoVista();
	//indica si un punto esta contenido dentro del area de la imagen
	ElementoVista* areaDeImagenContieneACoordenada(const int& coordX,const int& coordY);
	Gtk::Image* obtenerImagen();
	Elemento* obtenerElemento();
	virtual void copiarInformacion(Elemento* elemento) = 0;
	virtual ~ElementoVista(){}
};

#endif /* EDITOR_SRC_ELEMENTOS_ELEMENTOVISTA_H_ */
