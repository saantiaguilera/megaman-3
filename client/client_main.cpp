/*
 * client_main.h
 *
 *  Created on: May 14, 2016
 *      Author: santiago
 */

#include "client_Client.h"
#include "events/client_StartClientRunnable.h"


int main(int argc, char **argv) {
	//TODO. RUN THIS IN ANOTHER THREAD (ONLY THIS NOT THE CLIENT STUFF)
	Looper::getMainLooper().put(new StartClientRunnable());

	Client client;
	client.start();
}

/*

	GtkBuilder *builder;
	GtkWidget *window;
	GError *error = NULL;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();

	if (!gtk_builder_add_from_file(builder, LAYOUT_PATH, &error)) {
		g_warning("%s", error->message);
		g_free(error);

		return 1;
	}

	window = GTK_WIDGET(gtk_builder_get_object(builder, "client_home_screen_root_view"));

	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(G_OBJECT(builder));

	gtk_widget_show(window);

	gtk_main();

	return (0);
 */

/*
 Signal example:

#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
	g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Window");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

	button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add(GTK_CONTAINER(window), button_box);

	button = gtk_button_new_with_label("Hello World");
	g_signal_connect(button, "clicked", G_CALLBACK (print_hello), NULL);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK (gtk_widget_destroy),
			window);
	gtk_container_add(GTK_CONTAINER(button_box), button);

	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

 */
