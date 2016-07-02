/*
 * DialogManager.h
 *
 *  Created on: Jun 10, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_EDITOR_DIALOGMANAGER_H_
#define EDITOR_MODELS_EDITOR_DIALOGMANAGER_H_

#include <gtkmm.h>

#include "../../../common/common_MapConstants.h"

class SaveDelegate;
class BackDelegate;
class MapWindow;

class DialogManager {
public:
	//Constructors
	DialogManager(MapWindow *aPresentingWindow);
	DialogManager();

	//Destructors
	virtual ~DialogManager();

	//Actions
	void showSaveDialog();
	void showSaveDialogWithBossType(ObstacleViewType aBossType);
	void showBackDialog();
	void showMustHaveBossDialog();
	void showMustHaveBosschamberDialog();
	void showMustHaveMegamanDialog();



private:
	SaveDelegate *saveDelegate;
	BackDelegate *backDelegate;

	MapWindow *presentingWindow;
	ObstacleViewType bossType = ObstacleViewTypeMegaman;

};

#endif /* EDITOR_MODELS_EDITOR_DIALOGMANAGER_H_ */
