#include <adwaita.h>

// Estrutura para armazenar nossos widgets
typedef struct {
    GtkWidget *window;
    AdwToastOverlay *toast_overlay;
} AppData;

// Callback para o botão principal
static void on_button_clicked(GtkButton *button, AppData *data) {
    AdwToast *toast = adw_toast_new("Ação realizada!");
    adw_toast_overlay_add_toast(data->toast_overlay, toast);
}

// Callback para mostrar preferências (sem usar tipos obsoletos)
static void on_preferences_clicked(GtkButton *button, AppData *data) {
    // Cria a janela de preferências
    GtkWidget *prefs_window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(prefs_window), "Preferências");
    gtk_window_set_transient_for(GTK_WINDOW(prefs_window), GTK_WINDOW(data->window));
    gtk_window_set_default_size(GTK_WINDOW(prefs_window), 500, 400);

    // Cria um layout de preferências manualmente
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
    gtk_widget_set_margin_top(box, 12);
    gtk_window_set_child(GTK_WINDOW(prefs_window), box);

    // Adiciona um grupo de opções
    GtkWidget *frame = gtk_frame_new("Configurações");
    gtk_box_append(GTK_BOX(box), frame);

    GtkWidget *prefs_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_frame_set_child(GTK_FRAME(frame), prefs_box);

    // Adiciona um switch
    GtkWidget *switch_row = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    gtk_widget_set_margin_top(switch_row, 6);

    GtkWidget *label = gtk_label_new("Ativar recurso experimental");
    gtk_box_append(GTK_BOX(switch_row), label);

    GtkWidget *switcher = gtk_switch_new();
    gtk_widget_set_halign(switcher, GTK_ALIGN_END);
    gtk_widget_set_hexpand(switcher, TRUE);
    gtk_box_append(GTK_BOX(switch_row), switcher);

    gtk_box_append(GTK_BOX(prefs_box), switch_row);

    gtk_window_present(GTK_WINDOW(prefs_window));
}

static void activate(GtkApplication *app, gpointer user_data) {
    AppData *data = g_new0(AppData, 1);

    // Cria janela principal
    data->window = adw_window_new();
    gtk_window_set_application(GTK_WINDOW(data->window), app);
    gtk_window_set_title(GTK_WINDOW(data->window), "App Moderno");
    gtk_window_set_default_size(GTK_WINDOW(data->window), 400, 300);

    // Configura toast overlay
    data->toast_overlay = ADW_TOAST_OVERLAY(adw_toast_overlay_new());
    adw_window_set_content(ADW_WINDOW(data->window), GTK_WIDGET(data->toast_overlay));

    // Layout principal
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    adw_toast_overlay_set_child(data->toast_overlay, box);

    // Header bar
    GtkWidget *header = adw_header_bar_new();
    gtk_box_append(GTK_BOX(box), header);

    // Botão de menu
    GtkWidget *menu_btn = gtk_button_new_from_icon_name("open-menu-symbolic");
    gtk_widget_set_tooltip_text(GTK_WIDGET(menu_btn), "Preferências");
    adw_header_bar_pack_end(ADW_HEADER_BAR(header), menu_btn);
    g_signal_connect(menu_btn, "clicked", G_CALLBACK(on_preferences_clicked), data);

    // Conteúdo principal
    GtkWidget *content = adw_status_page_new();
    adw_status_page_set_icon_name(ADW_STATUS_PAGE(content), "dialog-information-symbolic");
    adw_status_page_set_title(ADW_STATUS_PAGE(content), "Exemplo Moderno");
    adw_status_page_set_description(ADW_STATUS_PAGE(content), "Sem APIs obsoletas");
    gtk_box_append(GTK_BOX(box), content);

    // Grade com widgets
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 12);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 12);
    gtk_widget_set_margin_top(grid, 24);
    adw_status_page_set_child(ADW_STATUS_PAGE(content), grid);

    // Botão principal
    GtkWidget *button = gtk_button_new_with_label("Clique aqui");
    gtk_widget_add_css_class(button, "suggested-action");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), data);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

    gtk_window_present(GTK_WINDOW(data->window));

    // Configura cleanup
    g_object_weak_ref(G_OBJECT(data->window), (GWeakNotify)g_free, data);
}

int main(int argc, char **argv) {
    // Cria e executa a aplicação
    g_autoptr (AdwApplication) app = NULL;
    app = adw_application_new("com.example.modern.adwaita", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    gint status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
