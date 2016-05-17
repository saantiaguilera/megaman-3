/*
 * StartClientRunnable.h
 *
 *  Created on: May 16, 2016
 *      Author: santi
 */

#ifndef CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_
#define CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_

#include <iostream>
#include "../../Constants.h"
#include <gtk-3.0/gtk/gtk.h>

#define LAYOUT_PATH "res/layout/home_screen.glade"
#define VIEW_ROOT "client_home_screen_root_view"
#define VIEW_EDIT_TEXT "client_home_screen_edit_text"

class StartClientRunnable : public Runnable {
public:
	StartClientRunnable() { /* DO SMTH */ }
	virtual ~StartClientRunnable() { /* DO SMTH */ }

	virtual void operator() () {
		GtkBuilder *builder;
		GtkWidget *window;
		GError *error = NULL;

		gtk_init(0, 0);

		builder = gtk_builder_new();

		if (!gtk_builder_add_from_file(builder, LAYOUT_PATH, &error)) {
			g_warning("%s", error->message);
			g_free(error);
			return;
		}

		window = GTK_WIDGET(gtk_builder_get_object(builder, VIEW_ROOT));

		gtk_builder_connect_signals(builder, NULL);

		g_object_unref(G_OBJECT(builder));

		gtk_widget_show(window);

		gtk_main();
	}
};



#endif /* CLIENT_EVENTS_CLIENT_STARTCLIENTRUNNABLE_H_ */
