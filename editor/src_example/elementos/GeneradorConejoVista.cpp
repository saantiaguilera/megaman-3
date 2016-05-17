/*
 * GeneradorConejoVista.cpp
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#include "GeneradorConejoVista.h"

GeneradorConejoVista::GeneradorConejoVista()
{
	this->elemento = new GeneradorConejo();
	this->imagen = new Gtk::Image();
	this->imagen->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "conejo.png");
}

void GeneradorConejoVista::copiarInformacion(Elemento* elemento)
{
	this->elemento->setearClaveImagenTransparente(elemento->obtenerClaveImagenTransparente());
	this->elemento->setearVerticeSupIzqAreaImagen(elemento->obtenerVerticeX(),
														elemento->obtenerVerticeY());
}

GeneradorConejoVista::~GeneradorConejoVista()
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


