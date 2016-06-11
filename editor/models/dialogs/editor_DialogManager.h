/*
 * DialogManager.h
 *
 *  Created on: Jun 10, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_EDITOR_DIALOGMANAGER_H_
#define EDITOR_MODELS_EDITOR_DIALOGMANAGER_H_

#include <gtkmm.h>

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
	void showBackDialog();

private:
	SaveDelegate *saveDelegate;
	BackDelegate *backDelegate;

	MapWindow *presentingWindow;

};

#endif /* EDITOR_MODELS_EDITOR_DIALOGMANAGER_H_ */
