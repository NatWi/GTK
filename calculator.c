#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//global variables
double y, number1, number2, result;
int operation = 0;
bool input_check= false;


//use style.css-file for style-adjustments, further details:
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
	gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER(provider),  GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	gtk_css_provider_load_from_file(provider, css_fp, &error);

	g_object_unref(provider);
}

	
//callback-functions

//first button
void button_sum_clicked(GtkWidget* widget, gpointer data){
	operation = 1;
	gtk_label_set_text(GTK_LABEL(data), "+");
	}

//second button
void button_difference_clicked(GtkWidget* widget, gpointer data){
	operation = 2;
}

//third button
void button_clear_clicked(GtkWidget* widget, gpointer data){
	//gtk_label_set_text(GTK_LABEL(data),"Button is pressed");
}

//fourth button
void button_multiply_clicked(GtkWidget* widget, gpointer data){
	operation = 3;
}


//fifth button
void button_divide_clicked(GtkWidget* widget, gpointer data){
	operation = 4;
}

//sixth field, entry
//callback-function for typing enter in entry field
void entry_callback(GtkEntry *entry) {
	const gchar *text = gtk_entry_get_text(entry);
	g_print("Text = %s\n", text);
	y = atof(gtk_entry_get_text(GTK_ENTRY(entry))); 		//convert string to double
	g_print("Double multiplied by 3: %lf\n",3*y);
	gtk_entry_set_text(GTK_ENTRY(entry),"" );
}

//twelfth field, sixth button
void button_calculate_clicked(GtkWidget* widget, gpointer data){
	//gtk_label_set_text(GTK_LABEL(data),"Button is pressed");
}



//main-function
int main (int argc, char **argv) {
	gtk_init (&argc, &argv);					//Gtk start
	load_css();							//execute function for style adjustments

	//elements in window							
	
	GtkWidget *window, *grid;					
	
	// childs are single fields of the grid
	GtkWidget *child1, *child2, *child3, *child4, *child5;
	GtkWidget *child6, *child7, *child8, *child9, *child10;
	GtkWidget *child11, *child12, *child13;
	
	//buttons
	GtkWidget *button1, *button2, *button3, *button4, *button5, *button6;
	
	//entry
	GtkWidget *entry;
	
	//labels
	GtkWidget *label1, *label2, *label3, *label4, *label5, *label6;
	
	//window settings
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);			//define new window
	gtk_widget_set_size_request(window,800,400);			//set size of window
	gtk_window_set_title(GTK_WINDOW(window),"Calculator");		//set title of window
	
	//signal for close window, G_CALLBACK is a makro, last parameter: what is passed to the function, here NULL
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	
	

	//settings for grid
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid); 		//add grid to window
	gtk_container_set_border_width(GTK_CONTAINER(grid),30);		//size of outside border
	//gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);		//adjust to windowsize vertical
	//gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);	//adjust to windowsize horizontal
	gtk_grid_set_row_spacing(GTK_GRID(grid),3);			//spacing between rows
	gtk_grid_set_column_spacing(GTK_GRID(grid),3);			//spacing between columns


//first button for sum
	child1 = gtk_grid_new();					//creation
	gtk_widget_set_name(child1,"mychild");				//name
	gtk_widget_set_size_request(child1,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child1,0,0,1,1);			//position in grid
	
	button1 = gtk_button_new_with_label("+");			//creation
	gtk_container_add(GTK_CONTAINER(child1), button1);		//add button to grid-field
	gtk_widget_set_name(button1,"mybutton");			//name
	
	



	
//second button for difference		
	child2 = gtk_grid_new();					//creation
	gtk_widget_set_name(child2,"mychild");				//name
	gtk_widget_set_size_request(child2,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child2,1,0,1,1);			//position in grid
	
	button2 = gtk_button_new_with_label("-");			//creation
	gtk_container_add(GTK_CONTAINER(child2), button2);		//add button to grid-field
	gtk_widget_set_name(button2,"mybutton");			//name

	//signal for callback function for button
	g_signal_connect(button2, "clicked", G_CALLBACK(button_difference_clicked), NULL);
	
//third button for reset		
	child3 = gtk_grid_new();					//creation
	gtk_widget_set_name(child3,"mychild");				//name
	gtk_widget_set_size_request(child3,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child3,4,0,1,1);			//position in grid
	
	button3 = gtk_button_new_with_label("C");			//creation
	gtk_container_add(GTK_CONTAINER(child3), button3);		//add button to grid-field
	gtk_widget_set_name(button3,"mybutton");			//name

	//signal for callback function for button
	g_signal_connect(button3, "clicked", G_CALLBACK(button_clear_clicked), NULL);
	
//fourth button for multiplication		
	child4 = gtk_grid_new();					//creation
	gtk_widget_set_name(child4,"mychild");				//name
	gtk_widget_set_size_request(child4,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child4,0,1,1,1);			//position in grid
	
	button4 = gtk_button_new_with_label("*");			//creation
	gtk_container_add(GTK_CONTAINER(child4), button4);		//add button to grid-field
	gtk_widget_set_name(button4,"mybutton");			//name

	//signal for callback function for button
	g_signal_connect(button4, "clicked", G_CALLBACK(button_multiply_clicked), NULL);
	
//fifth button for division		
	child5 = gtk_grid_new();					//creation
	gtk_widget_set_name(child5,"mychild");				//name
	gtk_widget_set_size_request(child5,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child5,1,1,1,1);			//position in grid
	
	button5 = gtk_button_new_with_label(":");			//creation
	gtk_container_add(GTK_CONTAINER(child5), button5);		//add button to grid-field
	gtk_widget_set_name(button5,"mybutton");			//name

	//signal for callback function for button
	g_signal_connect(button5, "clicked", G_CALLBACK(button_divide_clicked), NULL);
	
//sixth field for entry
	child6 = gtk_grid_new();					//creation
	gtk_widget_set_name(child6,"mychild");				//name
	gtk_widget_set_size_request(child6,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child6,2,2,1,1);			//position in grid
	
	entry = gtk_entry_new();					//creation
	gtk_container_add(GTK_CONTAINER(child6), entry);		//add entry to grid-field
	gtk_widget_set_name(entry,"myentry");				//name
	gtk_entry_set_text(GTK_ENTRY(entry), "Type with comma");	//display initial text
	const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));	//display input in console
	g_print("Text = %s\n", text);
	
	//signal for callback function for entry
	g_signal_connect_swapped(entry, "activate", G_CALLBACK(entry_callback), entry);
	
//seventh field for label1, display Number1		
	child7 = gtk_grid_new();					//creation
	gtk_widget_set_name(child7,"mychild");				//name
	gtk_widget_set_size_request(child7,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child7,0,3,1,1);			//position in grid
	
	label1 = gtk_label_new("Number1");				//creation
	gtk_container_add(GTK_CONTAINER(child7), label1);		//add button to grid-field
	gtk_widget_set_name(label1,"mylabel");				//name
	
//eigth field for label2, display Number2		
	child8 = gtk_grid_new();					//creation
	gtk_widget_set_name(child8,"mychild");				//name
	gtk_widget_set_size_request(child8,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child8,2,3,1,1);			//position in grid
	
	label2 = gtk_label_new("Number2");				//creation
	gtk_container_add(GTK_CONTAINER(child8), label2);		//add button to grid-field
	gtk_widget_set_name(label2,"mylabel");				//name

//ninth field for label3, display value of Number1		
	child9 = gtk_grid_new();					//creation
	gtk_widget_set_name(child9,"mychild");				//name
	gtk_widget_set_size_request(child9,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child9,0,4,1,1);			//position in grid
	
	label3 = gtk_label_new("value of Number1");			//creation
	gtk_container_add(GTK_CONTAINER(child9), label3);		//add button to grid-field
	gtk_widget_set_name(label3,"mylabel");				//name
	
//tenth field for label4, display of operation		
	child10 = gtk_grid_new();					//creation
	gtk_widget_set_name(child10,"mychild");				//name
	gtk_widget_set_size_request(child10,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child10,1,4,1,1);		//position in grid
	
	label4 = gtk_label_new("+-*:");					//creation
	gtk_container_add(GTK_CONTAINER(child10), label4);		//add button to grid-field
	gtk_widget_set_name(label4,"mylabel");				//name
	
//eleventh field for label5, display value of Number2		
	child11 = gtk_grid_new();					//creation
	gtk_widget_set_name(child11,"mychild");				//name
	gtk_widget_set_size_request(child11,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child11,2,4,1,1);		//position in grid
	
	label5 = gtk_label_new("value of Number2");			//creation
	gtk_container_add(GTK_CONTAINER(child11), label5);		//add button to grid-field
	gtk_widget_set_name(label5,"mylabel");				//name
	
//twelfth field for button6 for equal-operation		
	child12 = gtk_grid_new();					//creation
	gtk_widget_set_name(child12,"mychild");				//name
	gtk_widget_set_size_request(child12,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child12,3,4,1,1);		//position in grid
	
	button6 = gtk_button_new_with_label("=");			//creation
	gtk_container_add(GTK_CONTAINER(child12), button6);		//add button to grid-field
	gtk_widget_set_name(button6,"mybutton");			//name

	//signal for callback function for button
	g_signal_connect(button6, "clicked", G_CALLBACK(button_calculate_clicked), NULL);	
	
//thirteenth field for label6, display result		
	child13 = gtk_grid_new();					//creation
	gtk_widget_set_name(child13,"mychild");				//name
	gtk_widget_set_size_request(child13,100,50);			//seize in grid
	gtk_grid_attach(GTK_GRID(grid),child13,4,4,1,1);		//position in grid
	
	label6 = gtk_label_new("result");				//creation
	gtk_container_add(GTK_CONTAINER(child13), label6);		//add button to grid-field
	gtk_widget_set_name(label6,"mylabel");				//name
	

//	gtk_label_set_text(GTK_LABEL(label), "World hello");		 //recast
	
//signals
	//signal for callback function for button1
	g_signal_connect(button1, "clicked", G_CALLBACK(button_sum_clicked), label4);						 



	gtk_widget_show_all(window);					//make the window visible
	gtk_main();							//endless loop, Gtk end
	return 0;
}

