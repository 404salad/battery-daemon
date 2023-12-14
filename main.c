#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <string.h>

void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("exit on button press\n");
    exit(0);
}

int main(int argc, char* argv) {
    FILE *fp = popen("bash check.sh", "r");
    if (fp == NULL) {
        perror("popen error");
        exit(EXIT_FAILURE);
    }

    int c;
    char percent[2] = "";
    while ((c = fgetc(fp)) != EOF) {
        char charStr[2];
        sprintf(charStr, "%c", c);
        strcat(percent, charStr);    
    }
    if (pclose(fp) == -1) {
        perror("pclose error");
        exit(EXIT_FAILURE);
    }

    int battery = atoi(percent);
    battery = 13;
    if(battery>20) {
        puts("suffient battery");
        exit(EXIT_SUCCESS);
    }
    else {
        puts("charge now");
        gtk_init(&argc, &argv);
        GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "battery alert");
        gtk_container_set_border_width(GTK_CONTAINER(window), 100);
        GtkWidget *button = gtk_button_new_with_label("BATTERY LOW");
        // callback function
        g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
        gtk_container_add(GTK_CONTAINER(window), button);
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
        gtk_widget_show_all(window);
        gtk_main();
    }

    return 0;
}

