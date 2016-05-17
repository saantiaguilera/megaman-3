/*
 * GeneradorTortugaVista.h
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#ifndef EDITOR_SRC_ELEMENTOS_GENERADORTORTUGAVISTA_H_
#define EDITOR_SRC_ELEMENTOS_GENERADORTORTUGAVISTA_H_
#include "ElementoVista.h"
#include "../../../Common/src/GeneradorTortuga.h"
class GeneradorTortugaVista : public ElementoVista {
public:
	void copiarInformacion(Elemento* elemento);
	virtual ~GeneradorTortugaVista(){}
};

#endif /* EDITOR_SRC_ELEMENTOS_GENERADORTORTUGAVISTA_H_ */
