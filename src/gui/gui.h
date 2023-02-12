#ifndef _GUI_H_
#define _GUI_H_

#include <gtk/gtk.h>


void on_buttonSave_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonReload_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonExit_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonOpenDB_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonUpdateDB_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonRepairDB_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonThreads_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonTimeout_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonInternetStatus_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonProjectTeam_activate(GtkWidget *widget, gpointer *userdata);

void on_buttonWebsite_activate(GtkWidget *widget, gpointer *userdata);
 
void on_inputSearch_activate(GtkWidget *widget, gpointer *userdata);

#endif  