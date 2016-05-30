/*
 * EditorController.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_CONTROLLERS_EDITOR_EDITORCONTROLLER_H_
#define EDITOR_CONTROLLERS_EDITOR_EDITORCONTROLLER_H_

#include "../models/editor_EditorMap.h"
#include "../views/editor_MainWindow.h"
#include "../views/editor_MapWindow.h"

class EditorController {
public:
	EditorController();
	virtual ~EditorController();

	void begin();

	void presentMainWindowSavingMap(EditorMap *map);
	void presentMainWindowWithoutSavingMap();
	void presentMapWindowWithMap(EditorMap *map);

private:
	Glib::RefPtr<Gtk::Builder> builder;


	MainWindow *mainWindow;
	MapWindow *mapWindow;

	void showMainWindow();
	void showMapWindow();
};

#endif /* EDITOR_CONTROLLERS_EDITOR_EDITORCONTROLLER_H_ */
