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
#define SAVE_DIALOG_SECONDARY_TEXT "Are you sure you want to save this map? changes are irreversible!"

#define MUST_HAVE_MEGAMAN_DIALOG_PRIMARY_TEXT "Validation"
#define MUST_HAVE_MEGAMAN_DIALOG_SECONDARY_TEXT "Map must have a megaman spawner to be saved"

#define MUST_HAVE_BOSS_DIALOG_PRIMARY_TEXT "Validation"
#define MUST_HAVE_BOSS_DIALOG_SECONDARY_TEXT "Map must have a boss to be saved"

#define MUST_HAVE_BOSSCHABER_DIALOG_PRIMARY_TEXT "Validation"
#define MUST_HAVE_BOSSCHABER_DIALOG_SECONDARY_TEXT "Map must have a bosschamber to be saved"

#define BACK_DIALOG_PRIMARY_TEXT "Back withous saving"
#define BACK_DIALOG_SECONDARY_TEXT "Are you sure you whant to go back without saving this map? changes will loose permanently!"



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
		  if (bossType == ObstacleViewTypeMegaman) {
			  presentingWindow->saveMap();
		  } else {
			  presentingWindow->saveMapWithBossType(bossType);
		  }
	  }
}

void DialogManager::showSaveDialogWithBossType(ObstacleViewType aBossType) {
	bossType = aBossType;
	showSaveDialog();
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

void DialogManager::showMustHaveBossDialog() {
	  Gtk::MessageDialog dialog(*presentingWindow, MUST_HAVE_BOSS_DIALOG_PRIMARY_TEXT,
	          false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);

	  dialog.set_secondary_text(
			  MUST_HAVE_BOSS_DIALOG_SECONDARY_TEXT);

	  dialog.run();
}

void DialogManager::showMustHaveBosschamberDialog() {
	  Gtk::MessageDialog dialog(*presentingWindow, MUST_HAVE_BOSSCHABER_DIALOG_PRIMARY_TEXT,
	          false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);

	  dialog.set_secondary_text(
			  MUST_HAVE_BOSSCHABER_DIALOG_SECONDARY_TEXT);

	  dialog.run();
}

void DialogManager::showMustHaveMegamanDialog() {
	  Gtk::MessageDialog dialog(*presentingWindow, MUST_HAVE_MEGAMAN_DIALOG_PRIMARY_TEXT,
	          false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);

	  dialog.set_secondary_text(
			  MUST_HAVE_MEGAMAN_DIALOG_SECONDARY_TEXT);

	  dialog.run();
}

