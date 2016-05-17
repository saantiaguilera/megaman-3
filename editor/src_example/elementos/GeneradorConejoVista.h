/*
 * GeneradorConejoVista.h
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#ifndef EDITOR_SRC_ELEMENTOS_GENERADORCONEJOVISTA_H_
#define EDITOR_SRC_ELEMENTOS_GENERADORCONEJOVISTA_H_
#include "ElementoVista.h"
#include "../../../Common/src/GeneradorConejo.h"

class GeneradorConejoVista : public ElementoVista {
public:
	GeneradorConejoVista();
	void copiarInformacion(Elemento* elemento);
	~GeneradorConejoVista();
};

#endif /* EDITOR_SRC_ELEMENTOS_GENERADORCONEJOVISTA_H_ */
