/*
 * MainWindow.h
 *
 *  Created on: May 17, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_EDITOR_MAINWINDOW_H_
#define EDITOR_VIEWS_EDITOR_MAINWINDOW_H_

#include <gtkmm.h>

#include "../../common/common_MapConstants.h"

class EditorController;

class MainWindow : public Gtk::Window {
public:
	//Constructors
    MainWindow();
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);//constructor

    //Setters
    void setDelegate(EditorController *aDelegate);

	//Destructors
	virtual ~MainWindow();

	void presentMapWithBossType(ObstacleViewType aBossType);

protected:
	//Needed to upload xml from GLADE
    Glib::RefPtr<Gtk::Builder> builder;

    //Delegate
    EditorController *delegate;

    //Different Buttons
    Gtk::Button *level1Button;
    Gtk::Button *level2Button;
    Gtk::Button *level3Button;
    Gtk::Button *level4Button;
    Gtk::Button *level5Button;

    Gtk::Button *bossChamber1Button;
    Gtk::Button *bossChamber2Button;
    Gtk::Button *bossChamber3Button;
    Gtk::Button *bossChamber4Button;
    Gtk::Button *bossChamber5Button;

   	//signal handlers
    void level1ButtonWasTapped();
    void level2ButtonWasTapped();
    void level3ButtonWasTapped();
    void level4ButtonWasTapped();
    void level5ButtonWasTapped();

    void bossChamber1ButtonWasTapped();
    void bossChamber2ButtonWasTapped();
    void bossChamber3ButtonWasTapped();
    void bossChamber4ButtonWasTapped();
    void bossChamber5ButtonWasTapped();

private:
    void presentMapWindowWithMapName(std::string mapName);
};


#endif /* EDITOR_VIEWS_EDITOR_MAINWINDOW_H_ */
