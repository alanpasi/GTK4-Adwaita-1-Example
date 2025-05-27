#include <adwaita.h>
#include "window.h"

void load_css(void) {
    GtkCssProvider *provider;
    GdkDisplay *display;

    provider = gtk_css_provider_new();
    display = gdk_display_get_default();

    gtk_style_context_add_provider_for_display(display,
                                                GTK_STYLE_PROVIDER(provider),
                                                GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_file(provider, g_file_new_for_path("style/main.css"));

    g_object_unref(provider);
}
