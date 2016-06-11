/*
 * DialogManager.cpp
 *
 *  Created on: Jun 10, 2016
 *      Author: santi
 */

#include "editor_DialogManager.h"

#include <iostream>
#include "../../views/editor_MapWindow.h"

#define SAVE_DIALOG_PRIMARY_TEXT "Save"
#define SAVE_DIALOG_SECONDARY_TEXT "Are you sure you whant to save this map? changes are irreversible"

#define BACK_DIALOG_PRIMARY_TEXT "Back withous saving"
#define BACK_DIALOG_SECONDARY_TEXT "Are you sure you whant to go back withowt saving this map? changes will loose permanently"


DialogManager::DialogManager(MapWindow *aPresentingWindow) {
	presentingWindow = aPresentingWindow;
}


DialogManager::DialogManager() {
}

DialogManager::~DialogManager() {
}


void DialogManager::showSaveDialog() {
	  Gtk::MessageDialog dialog(*presentingWindow, SAVE_DIALOG_PRIMARY_TEXT,
	          false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);

	  dialog.set_secondary_text(
			  SAVE_DIALOG_SECONDARY_TEXT);

	  int result = dialog.run();

	  if (result == Gtk::RESPONSE_OK) {
		  presentingWindow->saveMap();
	  }
}
void DialogManager::showBackDialog() {
	  Gtk::MessageDialog dialog(*presentingWindow, BACK_DIALOG_PRIMARY_TEXT,
	          false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);

	  dialog.set_secondary_text(
			  BACK_DIALOG_SECONDARY_TEXT);

	  int result = dialog.run();

	  if (result == Gtk::RESPONSE_OK) {
		  presentingWindow->back();
	  }
}
