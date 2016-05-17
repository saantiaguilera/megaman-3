/*
 * GeneradorTortugaVista.cpp
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */
#include "GeneradorTortugaVista.h"

void GeneradorTortugaVista::copiarInformacion(Elemento* elemento)
{
	this->elemento->setearClaveImagenTransparente(elemento->obtenerClaveImagenTransparente());
	this->elemento->setearVerticeSupIzqAreaImagen(elemento->obtenerVerticeX(),
														elemento->obtenerVerticeY());
	GeneradorTortuga* generador = (GeneradorTortuga*)elemento;
	GeneradorTortuga* elementoAtributo = (GeneradorTortuga*)this->elemento;
	elementoAtributo->setCantidadMaxima(generador->obtenerCantidadMaxima());
	elementoAtributo->setFrecuenciaGeneracion(generador->obtenerFrecuenciaGeneracion());
}
