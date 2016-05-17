/*
 * TortugaRojaVista.cpp
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#include "GeneradorTortugaRojaVista.h"

GeneradorTortugaRojaVista::GeneradorTortugaRojaVista()
{
	this->elemento = new GeneradorTortugaRoja();
	this->imagen = new Gtk::Image();
	this->imagen->set(RUTA_SERVER_EDITOR_IMAGENES SEPARADOR_DIRECTORIOS "tortugaRoja.png");
}

GeneradorTortugaRojaVista::~GeneradorTortugaRojaVista()
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

