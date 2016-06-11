/*
 * MapWindow.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_VIEWS_EDITOR_MAPWINDOW_H_
#define EDITOR_VIEWS_EDITOR_MAPWINDOW_H_

#include <gtkmm.h>

#include "editor_MapFixedWindow.h"
#include "../../common/common_MapConstants.h"
#include "../../common/common_MapView.h"

class EditorController;


class MapWindow : public Gtk::Window {
public:
	//Constructors
    MapWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);

	MapWindow();
	virtual ~MapWindow();

    //Setters
    void setMapView(MapView *aMapView);
    void setDelegate(EditorController *aDelegate);

    void saveMap();
    void back();

protected:
	//Needed to upload xml from GLADE
    Glib::RefPtr<Gtk::Builder> builder;

    //Delegate
    EditorController *delegate;

    Gtk::Image *draggingImage;
    ObstacleViewContainer *draggingImageContainer;

    //Navigation Buttons
    Gtk::Button *backButton;
    Gtk::Button *saveButton;

    //Add Buttons
    Gtk::Button *ladderButton;
    Gtk::Button *blockButton;
    Gtk::Button *block1Button;
    Gtk::Button *block2Button;
    Gtk::Button *block3Button;

    Gtk::Button *needleButton;
    Gtk::Button *precipiceButton;
    Gtk::Button *bossChamberButton;

    //Spawns
    Gtk::Button *megamanSpawnButton;
    Gtk::Button *bumpySpawnButton;
    Gtk::Button *jumpingSniperSpawnButton;
    Gtk::Button *metSpawnButton;
    Gtk::Button *normalSniperSpawnButton;

    //Powerups
    Gtk::Button *lifeButton;
    Gtk::Button *energySmallButton;
    Gtk::Button *energyBigButton;
    Gtk::Button *bigAmmoButton;
    Gtk::Button *smallAmmoButton;

    std::vector<Gtk::Button *> *addButtonVector;
    void addButtonWithName(Gtk::Button *aButton, std::string aName);

    //Window Buttons
    Gtk::EventBox *eventBox;
    Gtk::ScrolledWindow *scrolledWindow;
    MapFixedWindow *fixedWindow;

    // Override mouse events
    bool on_button_press_event(GdkEventButton *event);
	bool on_motion_notify_event(GdkEventMotion*event);

   	//Signal handlers
    void backButtonWasTapped();
    void saveButtonWasTapped();

        //Add Button Signals
    void ladderButtonWasTapped();
    void blockButtonWasTapped();
    void block1ButtonWasTapped();
    void block2ButtonWasTapped();
    void block3ButtonWasTapped();

    void needleButtonWasTapped();
    void precipiceButtonWasTapped();
    void bossChamberButtonWasTapped();

        //Spawns
    void megamanSpawnButtonWasTapped();
    void bumpySpawnButtonWasTapped();
    void jumpingSniperSpawnButtonWasTapped();
    void metSpawnButtonWasTapped();
    void normalSniperSpawnButtonWasTapped();

        //Powerups
    void lifeButtonWasTapped();
    void energySmallButtonWasTapped();
    void energyBigButtonWasTapped();
    void bigAmmoButtonWasTapped();
    void smallAmmoButtonWasTapped();

    //Size
    void sizeDidModify();

private:
    bool draggingImageIsMoving = false;
    void draggingBegin();
    void draggingEnd();

    void addDraggingImageWithType(ObstacleViewType obstacleViewType);
    void dropDraggingImage(int aX, int aY);
    void dragImage(int aX, int aY);

    void deleteDraggingImage();
	void deleteImage(int aX, int aY);
	void resizeFixView();

};

#endif /* EDITOR_VIEWS_EDITOR_MAPWINDOW_H_ */
