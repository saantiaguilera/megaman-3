/*
 * ElementoVista.cpp
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#include "ElementoVista.h"

ElementoVista::ElementoVista()
{
	this->imagen = NULL;
	this->elemento = NULL;
}

ElementoVista* ElementoVista::areaDeImagenContieneACoordenada(const int& coordX,const int& coordY)
{
	ElementoVista* contieneACoordenada=NULL;
	int coordXMaxima= this->obtenerElemento()->obtenerVerticeX()+this->imagen->get_width();
	int coordYMaxima= this->obtenerElemento()->obtenerVerticeY()+this->imagen->get_height();
	if( (this->obtenerElemento()->obtenerVerticeX()<=coordX)&&(coordXMaxima>=coordX)
			&&(this->obtenerElemento()->obtenerVerticeY()<=coordY)&&(coordYMaxima>=coordY))
	{
		contieneACoordenada = this;
	}
	return contieneACoordenada;
}

Elemento* ElementoVista::obtenerElemento()
{
	return this->elemento;
}

Gtk::Image* ElementoVista::obtenerImagen()
{
	return this->imagen;
}

