/*
 * FinDeNivel.h
 *
 *  Created on: 21/11/2015
 *      Author: nicolasdubiansky
 */

#ifndef COMMON_SRC_FINDENIVELVISTA_H_
#define COMMON_SRC_FINDENIVELVISTA_H_
#include "ElementoVista.h"
#include "../../../Common/src/FinDeNivel.h"

class FinDeNivelVista: public ElementoVista {
public:
	FinDeNivelVista();
	void copiarInformacion(Elemento* elemento);
	~FinDeNivelVista();
};

#endif /* COMMON_SRC_FINDENIVELVISTA_H_ */
