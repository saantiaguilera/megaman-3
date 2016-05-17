/*
 * FinDeNivel.cpp
 *
 *  Created on: 21/11/2015
 *      Author: nicolasdubiansky
 */

#include "FinDeNivelVista.h"

FinDeNivelVista::FinDeNivelVista()
{
	this->elemento = new FinDeNivel();
	this->imagen=new Gtk::Image();
	this->imagen->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "finDeNivel.png");
}

void FinDeNivelVista::copiarInformacion(Elemento* elemento)
{
	this->elemento->setearClaveImagenTransparente(elemento->obtenerClaveImagenTransparente());
	this->elemento->setearVerticeSupIzqAreaImagen(elemento->obtenerVerticeX(),elemento->obtenerVerticeY());
}

FinDeNivelVista::~FinDeNivelVista()
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
