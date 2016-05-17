/*
 * TortugaVerdeVista.cpp
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */
#include "GeneradorTortugaVerdeVista.h"

GeneradorTortugaVerdeVista::GeneradorTortugaVerdeVista()
{
	this->elemento = new GeneradorTortugaVerde();
	this->imagen=new Gtk::Image();
	this->imagen->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "tortugaVerde.png");
}

GeneradorTortugaVerdeVista::~GeneradorTortugaVerdeVista()
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

