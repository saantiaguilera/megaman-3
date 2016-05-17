/*
 * ObstaculoIrrompibleVista.cpp
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#include "ObstaculoIrrompibleVista.h"

ObstaculoIrrompibleVista::ObstaculoIrrompibleVista()
{
	this->elemento = new ObstaculoIrrompible();
	this->imagen=new Gtk::Image();
	this->imagen->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "obstaculoIrrompible.png");
}

void ObstaculoIrrompibleVista::copiarInformacion(Elemento* elemento)
{
	this->elemento->setearClaveImagenTransparente(elemento->obtenerClaveImagenTransparente());
	this->elemento->setearVerticeSupIzqAreaImagen(elemento->obtenerVerticeX(),elemento->obtenerVerticeY());
}

ObstaculoIrrompibleVista::~ObstaculoIrrompibleVista()
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

