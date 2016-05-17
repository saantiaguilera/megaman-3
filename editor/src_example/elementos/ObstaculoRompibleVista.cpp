/*
 * ObstaculoRompibleVista.cpp
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#include "ObstaculoRompibleVista.h"

ObstaculoRompibleVista::ObstaculoRompibleVista()
{
	this->elemento = new ObstaculoRompible();
	this->imagen=new Gtk::Image();
	this->imagen->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "obstaculoRomp.png");
}

void ObstaculoRompibleVista::copiarInformacion(Elemento* elemento)
{
	this->elemento->setearClaveImagenTransparente(elemento->obtenerClaveImagenTransparente());
	this->elemento->setearVerticeSupIzqAreaImagen(elemento->obtenerVerticeX(),elemento->obtenerVerticeY());
}

ObstaculoRompibleVista::~ObstaculoRompibleVista()
{
	if(this->imagen)
	{
		delete this->imagen;
	}
	if(this->elemento)
	{
		delete this->elemento;
	}
}

