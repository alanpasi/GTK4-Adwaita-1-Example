#include <adwaita.h>
#include "gtk/gtk.h"
#include "window.h"

static void btn_click(GtkButton *button) {
    g_print("Button click!!!\n");
};

/* adw_application Callback Function */
static void activate_cb (GtkApplication *app) {
    WidgetData *data= g_new0(WidgetData, 1);

    GtkBuilder *builder;

    // builder = gtk_builder_new_from_file("ui/adwaita_window.ui");
    builder = gtk_builder_new_from_file("ui/window_adwaita.ui");

    load_css();

    // GtkWindow
    data->window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_window_set_application(GTK_WINDOW(data->window), app);
    // gtk_window_set_title (GTK_WINDOW (data->window), "Adwaita - set_title");
    gtk_window_set_default_size (GTK_WINDOW (data->window), 400, 700);

    // GtkLabel
    data->lbl_headerbar_title = GTK_WIDGET(gtk_builder_get_object(builder, "title-headerbar"));
    gtk_widget_set_name(data->lbl_headerbar_title, "title-headerbar");
    gtk_label_set_label(GTK_LABEL(data->lbl_headerbar_title), "Título alterado!!!");

    // GtkButton
    // data->button = gtk_button_new_with_label("_Button");
    // gtk_button_set_use_underline(GTK_BUTTON(data->button), TRUE);
    // gtk_widget_set_name(GTK_WIDGET(data->button), "button");
    // g_signal_connect(data->button, "clicked", G_CALLBACK(btn_click), NULL);

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
