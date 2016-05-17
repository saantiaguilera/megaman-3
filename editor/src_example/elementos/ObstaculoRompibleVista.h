/*
 * ObstaculoRompibleVista.h
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#ifndef EDITOR_SRC_ELEMENTOS_OBSTACULOROMPIBLEVISTA_H_
#define EDITOR_SRC_ELEMENTOS_OBSTACULOROMPIBLEVISTA_H_
#include "ElementoVista.h"
#include "../../../Common/src/ObstaculoRompible.h"

class ObstaculoRompibleVista: public ElementoVista {
public:
	ObstaculoRompibleVista();
	void copiarInformacion(Elemento* elemento);
	~ObstaculoRompibleVista();
};

#endif /* EDITOR_SRC_ELEMENTOS_OBSTACULOROMPIBLEVISTA_H_ */
