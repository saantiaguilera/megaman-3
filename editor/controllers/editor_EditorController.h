/*
 * EditorController.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_CONTROLLERS_EDITOR_EDITORCONTROLLER_H_
#define EDITOR_CONTROLLERS_EDITOR_EDITORCONTROLLER_H_

#include "../../common/common_MapViewParser.h"
#include "../views/editor_MainWindow.h"
#include "../views/editor_MapWindow.h"

class EditorController {
public:
	EditorController(int argc, char *argv[]);
	virtual ~EditorController();
	void begin();

	void presentMainWindowSavingMap(MapView *map);
	void presentMainWindowWithoutSavingMap();
	void presentMapWindowWithMap(MapView *map);

private:
	Glib::RefPtr<Gtk::Builder> builder;
	Glib::RefPtr<Gtk::Application> gtkmm_main;

	MainWindow *mainWindow = NULL;
	MapWindow *mapWindow = NULL;

	void showMainWindow();
	void showMapWindow();
};

#endif /* EDITOR_CONTROLLERS_EDITOR_EDITORCONTROLLER_H_ */
