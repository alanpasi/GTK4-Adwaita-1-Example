#include <adwaita.h>
#include "gtk/gtk.h"
#include "window.h"

/* Struct of Widgets */
typedef struct {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    GtkWidget *button;
} WidgetData;

/* adw_application Callback Function */
static void activate_cb (GtkApplication *app) {
    WidgetData *data= g_new0(WidgetData, 1);

    load_css();

    // GtkWindow
    data->window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (data->window), "Hello");
    gtk_window_set_default_size (GTK_WINDOW (data->window), 400, 400);

    // GtkGrid
    data->grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(data->window), data->grid);
    // gtk_grid_set_row_homogeneous(GTK_GRID(data->grid), TRUE);
    // gtk_grid_set_column_homogeneous(GTK_GRID(data->grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(data->grid), 30);
    gtk_grid_set_column_spacing(GTK_GRID(data->grid), 30);
    gtk_widget_set_margin_start(GTK_WIDGET(data->grid), 50);
    gtk_widget_set_margin_end(GTK_WIDGET(data->grid), 50);
    gtk_widget_set_margin_top(GTK_WIDGET(data->grid), 50);
    gtk_widget_set_margin_bottom(GTK_WIDGET(data->grid), 50);

    // GtkLabel
    data->label = gtk_label_new("Label1");
    gtk_widget_set_name(data->label, "label");

    // GtkButton
    data->button = gtk_button_new_with_label("_Button");
    gtk_button_set_use_underline(GTK_BUTTON(data->button), TRUE);
    gtk_widget_set_name(data->button, "button");

    // Attach Widgets children to GtkGrid
    gtk_grid_attach(GTK_GRID(data->grid), data->label, 0, 0, 1, 1); // Label at column 0, row 0
    gtk_grid_attach(GTK_GRID(data->grid), data->button, 0, 1, 1, 1); // Button at column 0, row 1

    gtk_window_present (GTK_WINDOW (data->window));

    g_object_weak_ref(G_OBJECT(data->window), (GWeakNotify)g_free, data);
}

int main (int argc, char *argv[]) {

    g_autoptr (AdwApplication) app = NULL;
    gint status = 0;

    app = adw_application_new ("com.alanpasi.adwaita", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate_cb), NULL);

    status = g_application_run (G_APPLICATION (app), argc, argv);

    return status;
}
