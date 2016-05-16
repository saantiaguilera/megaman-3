/*
 * client_main.h
 *
 *  Created on: May 14, 2016
 *      Author: santiago
 */

#include <iostream>
#include "../Constants.h"
#include <gtk-3.0/gtk/gtk.h>

#define LAYOUT_PATH "res/layout/home_screen.glade"

#include <gtk/gtk.h>

int main(int argc, char **argv) {
	GtkBuilder *builder;
	GtkWidget *window;
	GError *error = NULL;

	/* Init GTK+ */
	gtk_init(&argc, &argv);

	/* Create new GtkBuilder object */
	builder = gtk_builder_new();

	/* Load UI from file. If error occurs, report it and quit application.
	 * Replace "tut.glade" with your saved project. */
	if (!gtk_builder_add_from_file(builder, LAYOUT_PATH, &error)) {
		g_warning("%s", error->message);
		g_free(error);
		return (1);
	}

	/* Get main window pointer from UI */
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));

	/* Connect signals */
	gtk_builder_connect_signals(builder, NULL);

	/* Destroy builder, since we don't need it anymore */
	g_object_unref(G_OBJECT(builder));

	/* Show window. All other widgets are automatically shown by GtkBuilder */
	gtk_widget_show(window);

	/* Start main loop */
	gtk_main();

	return (0);
}
