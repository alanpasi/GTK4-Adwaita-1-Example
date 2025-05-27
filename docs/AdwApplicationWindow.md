# GTK4/Adwaita-1
by Google Gemini

# AdwApplicationWindow

A `AdwApplicationWindow` é uma subclasse de `GtkApplicationWindow` que estende suas funcionalidades para fornecer uma experiência de usuário mais alinhada com as diretrizes de design do GNOME/Adwaita. Ela herda muitas propriedades de `GtkApplicationWindow` e `GtkWidget`, além de adicionar algumas próprias.

Aqui estão as propriedades específicas da `AdwApplicationWindow` (e algumas das mais comumente usadas de suas classes parentes) com exemplos em C:

**Propriedades específicas de `AdwApplicationWindow`:**

* **`content` (GtkWidget *)**: O widget principal que a janela contém. É o "corpo" da janela.
    * **Descrição:** Define o widget que será exibido como conteúdo principal da `AdwApplicationWindow`. `AdwApplicationWindow` não permite `gtk_window_set_child()`, então você deve usar esta propriedade.
    * **Desde:** libadwaita 1.0
    * **Exemplo:**

    ```c
    #include <adwaita.h>

    static void
    activate(GtkApplication *app, gpointer user_data)
    {
        AdwApplicationWindow *window = ADW_APPLICATION_WINDOW(adw_application_window_new(GTK_APPLICATION(app)));
        GtkWidget *label = gtk_label_new("Olá, mundo!");

        // Definir o conteúdo da janela
        adw_application_window_set_content(window, label);

        gtk_window_set_title(GTK_WINDOW(window), "Minha AdwApplicationWindow");
        gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
        gtk_widget_show(GTK_WIDGET(window));
    }

    int
    main(int argc, char *argv[])
    {
        GtkApplication *app = gtk_application_new("org.example.AdwAppWindowExample", G_APPLICATION_FLAGS_NONE);
        g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
        return g_application_run(G_APPLICATION(app), argc, argv);
    }
    ```

* **`visible-dialog` (AdwAlertDialog *)**: O `AdwAlertDialog` atualmente visível na janela.
    * **Descrição:** Esta propriedade é usada para obter ou definir o `AdwAlertDialog` que está sendo exibido na janela. É útil para gerenciar múltiplos diálogos ou para saber qual diálogo está ativo.
    * **Desde:** libadwaita 1.5
    * **Exemplo (conceptual, pois `AdwAlertDialog` é geralmente usado com `adw_alert_dialog_present()`):**

    ```c
    // Esta propriedade é mais usada para observar qual diálogo está visível
    // ou para definir um diálogo via UI file.
    // Para mostrar um diálogo programaticamente, você usaria adw_alert_dialog_present().

    // Exemplo de obtenção do diálogo visível:
    AdwAlertDialog *current_dialog = adw_application_window_get_visible_dialog(window);
    if (current_dialog != NULL) {
        g_print("Um diálogo está visível.\n");
    }
    ```

* **`dialogs` (GListModel *)**: Uma lista de todos os `AdwAlertDialog`s atualmente abertos na janela.
    * **Descrição:** Permite acessar uma lista (modelo de lista) de todos os diálogos `AdwAlertDialog` que estão abertos na `AdwApplicationWindow`.
    * **Desde:** libadwaita 1.5
    * **Exemplo (conceptual):**

    ```c
    // Obter o modelo de lista de diálogos
    GListModel *dialog_model = adw_application_window_get_dialogs(window);

    // Iterar sobre os diálogos (exemplo)
    guint n_dialogs = g_list_model_get_n_items(dialog_model);
    for (guint i = 0; i < n_dialogs; i++) {
        AdwAlertDialog *dialog = ADW_ALERT_DIALOG(g_list_model_get_item(dialog_model, i));
        g_print("Diálogo aberto: %p\n", (gpointer)dialog);
        g_object_unref(dialog); // Liberar a referência obtida
    }
    g_object_unref(dialog_model);
    ```

* **`current-breakpoint` (AdwBreakpoint *)**: O ponto de interrupção (breakpoint) atualmente ativo.
    * **Descrição:** `AdwApplicationWindow` suporta o conceito de "breakpoints" para adaptar o layout da janela a diferentes larguras, como em um design responsivo. Esta propriedade indica qual `AdwBreakpoint` está ativo com base na largura da janela.
    * **Desde:** libadwaita 1.0
    * **Exemplo (conceptual):**

    ```c
    // Você não define diretamente esta propriedade, ela é determinada pela largura da janela
    // e pelos AdwBreakpoints configurados.
    // Você pode obter o breakpoint atual:
    AdwBreakpoint *current_breakpoint = adw_application_window_get_current_breakpoint(window);
    if (current_breakpoint != NULL) {
        g_print("Breakpoint atual ativo: %s\n", adw_breakpoint_get_name(current_breakpoint));
    }
    ```

* **`adaptive-preview` (bool)**: Se a prévia adaptativa está atualmente aberta.
    * **Descrição:** Usado internamente para indicar se a janela está exibindo uma prévia do seu comportamento adaptativo. Raramente usada diretamente pelo desenvolvedor da aplicação.
    * **Desde:** libadwaita 1.7
    * **Exemplo (conceptual):**

    ```c
    gboolean is_adaptive_preview = adw_application_window_get_adaptive_preview(window);
    if (is_adaptive_preview) {
        g_print("A prévia adaptativa está ativa.\n");
    }
    ```

**Propriedades herdadas de `GtkApplicationWindow` e `GtkWidget` (comuns e importantes para `AdwApplicationWindow`):**

* **`application` (GtkApplication *)**: O `GtkApplication` ao qual a janela pertence.
    * **Exemplo:**

    ```c
    GtkApplication *app_ref = gtk_application_window_get_application(GTK_APPLICATION_WINDOW(window));
    // ...
    ```

* **`show-menubar` (bool)**: Se a barra de menu deve ser mostrada.
    * **Exemplo:**

    ```c
    gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), TRUE);
    ```

* **`default-width` (int)**: A largura padrão da janela.
    * **Exemplo:**

    ```c
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    ```

* **`default-height` (int)**: A altura padrão da janela.
    * **Exemplo:** (veja `default-width`)

* **`title` (const char *)**: O título da janela.
    * **Exemplo:**

    ```c
    gtk_window_set_title(GTK_WINDOW(window), "Minha Aplicação Adwaita");
    ```

* **`resizable` (bool)**: Se a janela pode ser redimensionada pelo usuário.
    * **Exemplo:**

    ```c
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE); // Torna a janela não redimensionável
    ```

* **`decorated` (bool)**: Se a janela deve ter decorações de borda (barra de título, botões de minimizar/maximizar/fechar).
    * **Exemplo:**

    ```c
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE); // Remove as decorações da janela
    ```

* **`modal` (bool)**: Se a janela é modal (bloqueia interações com outras janelas da aplicação).
    * **Exemplo:**

    ```c
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    ```

* **`visible` (bool)**: Se o widget está visível.
    * **Exemplo:**

    ```c
    gtk_widget_set_visible(GTK_WIDGET(window), TRUE); // Geralmente você usa gtk_widget_show()
    ```

* **`hexpand` (bool)** e **`vexpand` (bool)**: Se o widget deve se expandir horizontal ou verticalmente dentro de seu contêiner.
    * **Exemplo:** (mais comum para widgets dentro da janela, não para a janela em si)

    ```c
    // Para um widget dentro da janela:
    gtk_widget_set_hexpand(some_child_widget, TRUE);
    gtk_widget_set_vexpand(some_child_widget, TRUE);
    ```

**Como encontrar mais propriedades:**

A melhor forma de encontrar todas as propriedades, sinais e métodos de uma classe GObject (como `AdwApplicationWindow`) é consultar a documentação oficial da biblioteca.

Para `libadwaita`, você pode encontrar a documentação da `AdwApplicationWindow` aqui: [https://gnome.pages.gitlab.gnome.org/libadwaita/doc/1.7/class.ApplicationWindow.html](https://gnome.pages.gitlab.gnome.org/libadwaita/doc/1.7/class.ApplicationWindow.html) (substitua `1.0` pela sua versão da libadwaita se for diferente).

Na documentação, procure pela seção "Properties" para uma lista completa. Lembre-se que `AdwApplicationWindow` herda de `GtkApplicationWindow`, que por sua vez herda de `GtkWindow` e `GtkWidget`, então você também deve consultar as documentações dessas classes para entender todas as propriedades disponíveis.

Ao usar C, você geralmente interage com as propriedades através de funções `getter` e `setter` (por exemplo, `adw_application_window_get_content()` e `adw_application_window_set_content()`) ou, em casos mais genéricos, com `g_object_get()` e `g_object_set()`.
