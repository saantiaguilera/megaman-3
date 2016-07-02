/*
 * MapWindowValidator.h
 *
 *  Created on: Jul 2, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_EDITOR_MAPWINDOWVALIDATOR_H_
#define EDITOR_MODELS_EDITOR_MAPWINDOWVALIDATOR_H_

class MapWindowValidator {
public:
	MapWindowValidator();
	virtual ~MapWindowValidator();
	void setMegaman();
	void setBoss();
	void setBosschamber();
	void removeMegaman();
	void removeBoss();
	void removeBosschamber();

	bool didSetMegaman();
	bool didSetBoss();
	bool didSetBosschamber();

private:
	bool isMegamanSet;
	bool isBossSet;
	bool isBosschamberSet;
};

#endif /* EDITOR_MODELS_EDITOR_MAPWINDOWVALIDATOR_H_ */
