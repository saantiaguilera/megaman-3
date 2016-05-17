/*
 * ObstaculoIrrompibleVista.h
 *
 *  Created on: 25/11/2015
 *      Author: matiaskamien
 */

#ifndef EDITOR_SRC_ELEMENTOS_OBSTACULOIRROMPIBLEVISTA_H_
#define EDITOR_SRC_ELEMENTOS_OBSTACULOIRROMPIBLEVISTA_H_
#include "ElementoVista.h"
#include "../../../Common/src/ObstaculoIrrompible.h"

class ObstaculoIrrompibleVista:public ElementoVista {
public:
	ObstaculoIrrompibleVista();
	void copiarInformacion(Elemento* elemento);
	~ObstaculoIrrompibleVista();
};

#endif /* EDITOR_SRC_ELEMENTOS_OBSTACULOIRROMPIBLEVISTA_H_ */
