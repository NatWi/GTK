#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//use file for style-adjustments, further details:
//https://www.youtube.com/watch?v=1LppFd7dTMI&list=PLN_MPJUQgPVpkVVSJ8qrzk65FHnUtO6BF&index=3
void load_css(void){
	GtkCssProvider *provider;
	GdkDisplay *display;
	GdkScreen *screen;
	const gchar *css_style_file = "style.css";
	GFile *css_fp = g_file_new_for_path(css_style_file);
	GError *error = 0;
	provider = gtk_css_provider_new();
	display = gdk_display_get_default();
	screen = gdk_display_get_default_screen (display);
	//attributes above are for these two functions
	gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	gtk_css_provider_load_from_file(provider, css_fp, &error);

	g_object_unref(provider);
}

	

void button_clicked(GtkWidget* widget, gpointer data){
	gtk_label_set_text(GTK_LABEL(data),"Button is pressed");
}

//global variables
double y, number1, number2;
int operation = 0;
bool input_check= false;

//callback-function for typing enter in entry field
void entry_callback(GtkEntry *entry) {
	const gchar *text = gtk_entry_get_text(entry);
	g_print("Text = %s\n", text);
	y = atof(gtk_entry_get_text(GTK_ENTRY(entry))); //convert string to double
	g_print("Double multiplied by 3: %lf\n",3*y);
//	const gchar * testtext =(y);
	gtk_entry_set_text(GTK_ENTRY(entry),"" );
}


int main (int argc, char **argv) {
	gtk_init (&argc, &argv);					//Gtk start
	load_css();							//execute function for style adjustments
	GtkWidget *window, *label, *grid;				//hbox = horizontal box
	GtkWidget *button, *button1;
	GtkWidget *entry;
	// childs are single fields of the grid
	GtkWidget *child, *child1, *child2, *child3, *child4;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);			//define new window
	gtk_widget_set_size_request(window,640,480);			//set size of window
	gtk_window_set_title(GTK_WINDOW(window),"Calculator");		//set title of window

	grid = gtk_grid_new();
	gtk_container_set_border_width(GTK_CONTAINER(grid),30);
	gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);		//adjust to windowsize vertical
	gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);		//adjust to windowsize horizontal
	gtk_grid_set_row_spacing(GTK_GRID(grid),3);
	gtk_grid_set_column_spacing(GTK_GRID(grid),3);

	label = gtk_label_new("Hello world");				
	gtk_label_set_text(GTK_LABEL(label), "World hello");		 //recast
									 
	button = gtk_button_new_with_label("Click me");			
	button1 = gtk_button_new_with_label("Click1 me");			

	child = gtk_grid_new();
	gtk_widget_set_name(child,"mychild");
	gtk_widget_set_name(label,"mylabel");
	gtk_widget_set_size_request(child,100,100);
	gtk_grid_attach(GTK_GRID(grid),child,0,0,1,1);
	gtk_container_add(GTK_CONTAINER(child), label);

	child1 = gtk_grid_new();
	gtk_widget_set_name(child1,"mychild1");
	gtk_widget_set_size_request(child1,100,100);
	gtk_grid_attach(GTK_GRID(grid),child1,1,1,1,1);

	child2 = gtk_grid_new();
	entry = gtk_entry_new();
	gtk_widget_set_name(child2,"mychild");
	gtk_widget_set_name(entry,"myentry");
	gtk_widget_set_size_request(child2,100,100);
	gtk_grid_attach(GTK_GRID(grid),child2,2,2,1,1);
	gtk_container_add(GTK_CONTAINER(child2), entry);
	gtk_entry_set_text(GTK_ENTRY(entry), "Type with comma");
	const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
	g_print("Text = %s\n", text);

	child3 = gtk_grid_new();
	gtk_widget_set_name(child3,"mychild");
	gtk_widget_set_size_request(child3,100,100);
	gtk_grid_attach(GTK_GRID(grid),child3,3,0,1,1);

	child4 = gtk_grid_new();
	gtk_widget_set_name(child4,"mychild");
	gtk_widget_set_size_request(child4,100,100);
	gtk_grid_attach(GTK_GRID(grid),child4,4,0,1,1);

//	hbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);			//2nd parameter is spacing	
//	gtk_box_pack_start(GTK_BOX(hbox), label, 0, 0, 0);		//order from start
//	gtk_box_pack_start(GTK_BOX(hbox), button, 0, 0, 0);		//order from start

//callback-functions
	//close window, G_CALLBACK is a makro, last parameter: what is passed to the function, here NULL
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

	//callback function for button
	g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), label);
	
	gtk_container_add(GTK_CONTAINER(window), grid); 		//add grid to window
	
	g_signal_connect_swapped(entry, "activate", G_CALLBACK(entry_callback), entry);


	gtk_widget_show_all(window);					//make the window visible
	gtk_main();							//endless loop, Gtk end
	return 0;
}
