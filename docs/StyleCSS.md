# GTK4/Adwaita-1
by Google Gemini

# CSS

No ambiente GTK4, especialmente quando utilizado em conjunto com o Adwaita (a folha de estilo padrão do GNOME e a biblioteca libadwaita), o CSS é a principal ferramenta para personalizar a aparência dos widgets. A libadwaita estende o GTK4 para oferecer widgets que seguem as diretrizes de interface humana (HIG) do GNOME e integra o estilo Adwaita, permitindo até mesmo a mudança de cores em tempo de execução via variáveis CSS.

Vamos detalhar como usar CSS em um aplicativo GTK4/Adwaita-1 na linguagem C:

### 1. Entendendo o GTK CSS e Adwaita

* **GTK CSS:** O GTK4 possui seu próprio subsistema de CSS que permite estilizar a interface do usuário de forma semelhante ao CSS web. Você pode definir cores, fontes, margens, preenchimentos, bordas e muito mais para os widgets GTK.
* **Adwaita:** É o tema padrão do GNOME. Quando você usa o GTK4, o Adwaita é o tema base que seus aplicativos herdam. A biblioteca `libadwaita` fornece widgets e funcionalidades adicionais que se integram perfeitamente com o estilo Adwaita. Embora o Adwaita seja projetado para ser consistente, você ainda pode aplicar CSS personalizado para ajustes finos ou para criar sua própria identidade visual.
* **Nós CSS e Classes de Estilo:** Assim como no HTML, os widgets GTK são representados por "nós CSS". Cada tipo de widget tem um nome de nó (por exemplo, `button`, `label`, `window`). Além disso, os widgets podem ter "classes de estilo" aplicadas a eles, que permitem segmentar grupos específicos de widgets para estilização. O GTK adiciona automaticamente algumas classes de estilo (como `text-button` para um botão com texto), e você pode adicionar suas próprias classes personalizadas.
* **Variáveis CSS (Custom Properties):** O GTK4 e Adwaita fazem uso extensivo de variáveis CSS (também chamadas de "custom properties" ou "propriedades personalizadas"). Estas são definidas com `--` no CSS (ex: `--my-color: red;`) e podem ser usadas em todo o seu CSS (`color: var(--my-color);`). O Adwaita define muitas variáveis para suas cores de tema, o que permite ajustes globais mais fáceis.

### 2. Carregando e Aplicando CSS em C

Para aplicar CSS em seu aplicativo GTK4 em C, você precisará usar as seguintes funções e conceitos:

* `GtkCssProvider`: Este objeto é responsável por carregar e gerenciar folhas de estilo CSS.
* `GtkStyleContext`: Cada widget GTK tem um `GtkStyleContext` associado a ele, que gerencia as informações de estilo do widget. Você adiciona `GtkCssProvider`s ao `GtkStyleContext` para aplicar estilos.
* `GdkDisplay`: Você normalmente aplica `GtkCssProvider`s ao `GdkDisplay` padrão para que os estilos sejam aplicados globalmente a todos os widgets na aplicação.

Aqui está um exemplo básico de como carregar um arquivo CSS e aplicá-lo:

```c
#include <adwaita.h>

// Função para aplicar um arquivo CSS
static void apply_css(GtkApplication *app, const char *css_file_path) {
    GtkCssProvider *provider;
    GdkDisplay *display;

    provider = gtk_css_provider_new();
    display = gdk_display_get_default();

    // Tenta carregar o arquivo CSS
    if (!gtk_css_provider_load_from_file(provider, g_file_new_for_path(css_file_path))) {
        g_warning("Falha ao carregar o arquivo CSS: %s", css_file_path);
        g_object_unref(provider);
        return;
    }

    // Adiciona o provedor CSS ao contexto de estilo padrão para o display
    // Isso aplica os estilos a todos os widgets da aplicação
    gtk_style_context_add_provider_for_display(display, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    g_object_unref(provider);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;

    // Aplica o CSS antes de criar a janela para garantir que os estilos sejam carregados
    apply_css(app, "style.css"); // Assumindo que style.css está no mesmo diretório

    window = adw_application_window_new(app); // Usando AdwApplicationWindow
    gtk_window_set_title(GTK_WINDOW(window), "GTK4 CSS Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    button = gtk_button_new_with_label("Hello Adwaita!");
    // Adicionando uma classe CSS personalizada para o botão
    gtk_widget_add_css_class(button, "my-custom-button");

    gtk_window_set_child(GTK_WINDOW(window), button);

    gtk_widget_show(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = adw_application_new("org.example.GtkCssExample", G_APPLICATION_DEFAULT_FLAGS); // Usando AdwApplication
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

```

### 3. Conteúdo do Arquivo `style.css`

Agora, vamos criar o arquivo `style.css` para estilizar os widgets:

```css
/* style.css */

/* Estilizando o botão com a classe personalizada */
.my-custom-button {
    background-color: @blue_5; /* Usando uma variável de cor Adwaita */
    color: white;
    padding: 15px 30px;
    border-radius: 8px;
    font-size: 1.2em;
    font-weight: bold;
    border: none;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
}

/* Estilo para quando o botão está pressionado */
.my-custom-button:active {
    background-color: @blue_7; /* Uma cor mais escura ao pressionar */
    box-shadow: inset 0 2px 4px rgba(0, 0, 0, 0.2);
}

/* Estilizando o rótulo (texto) dentro do botão */
button label {
    color: inherit; /* Herda a cor do texto do botão */
}

/* Exemplo de uso de variáveis CSS para recoloring em tempo de execução */
:root {
    --primary-color: @green_5; /* Define uma variável personalizada com uma cor Adwaita */
}

/* Altere o background da janela para usar a variável */
window {
    background-color: var(--primary-color);
}
```

**Pontos importantes sobre o CSS:**

* **Seletores:**
    * `button`: Aplica o estilo a todos os botões.
    * `.my-custom-button`: Aplica o estilo apenas a widgets que têm a classe CSS `my-custom-button` (adicionada com `gtk_widget_add_css_class()`).
    * `:active`: Um pseudoclasse para o estado de "ativo" (pressionado) do botão.
    * `button label`: Seleciona o `label` (o texto) dentro de um `button`.
    * `window`: Seleciona a janela principal.
    * `:root`: Semelhante ao seletor `html` em CSS web, permite definir variáveis globais que podem ser usadas em todo o CSS.
* **Variáveis Adwaita:** O Adwaita define diversas variáveis de cor (como `@blue_5`, `@green_5`, `@red_5`, etc.) que você pode usar para garantir consistência com o tema do sistema. Essas variáveis são exportadas e podem ser consultadas no código-fonte da libadwaita para uma lista completa.
* **Propriedades CSS:** As propriedades são semelhantes às do CSS web (ex: `background-color`, `color`, `padding`, `font-size`, `border-radius`, `box-shadow`). O GTK suporta muitas propriedades CSS padrão, além de algumas específicas para GTK.
* **Sistema de Prioridade:** Se houver regras CSS conflitantes, o GTK usa um sistema de prioridade para determinar qual estilo será aplicado. A prioridade `GTK_STYLE_PROVIDER_PRIORITY_APPLICATION` é geralmente uma boa escolha para estilos específicos da sua aplicação.

### 4. Compilando e Executando

Para compilar este código C, você precisará ter o GTK4 e a libadwaita instalados. Um `meson.build` típico seria algo assim:

```meson
project('gtk-css-example', 'c',
  version: '0.1.0',
  license: 'LGPL-3.0-or-later')

gtk4_dep = dependency('gtk4')
adw_dep = dependency('libadwaita-1')

executable('gtk-css-example',
  'main.c',
  dependencies: [gtk4_dep, adw_dep],
  install: true)
```

**Passos para compilar e executar:**

1.  Salve o código C como `main.c` e o CSS como `style.css` no mesmo diretório.
2.  Crie um arquivo `meson.build` no mesmo diretório.
3.  Abra um terminal no diretório do projeto.
4.  Crie um diretório de build e configure o projeto:
    ```bash
    meson setup build
    ```
5.  Compile o projeto:
    ```bash
    meson compile -C build
    ```
6.  Execute o aplicativo:
    ```bash
    ./build/gtk-css-example
    ```

### 5. Dicas e Considerações Adicionais

* **GTK Inspector (Ctrl + Shift + D):** Esta é uma ferramenta indispensável para depurar seus estilos CSS. Pressione `Ctrl + Shift + D` enquanto seu aplicativo GTK4 está em foco para abrir o inspetor. Ele permite que você veja a árvore de widgets, inspecione seus `GtkStyleContext`s, adicione e edite CSS em tempo real e veja como ele afeta a aparência.
* **Classes de Estilo Dinâmicas:** Você pode adicionar e remover classes CSS dinamicamente em tempo de execução usando `gtk_widget_add_css_class()` e `gtk_widget_remove_css_class()`. Isso é útil para mudar a aparência de um widget com base em seu estado ou interação do usuário.
* **Temas do Sistema:** O GTK4 e Adwaita são projetados para respeitar as preferências de tema do usuário (claro/escuro). Ao usar as variáveis de cor do Adwaita, você garante que seu aplicativo se adapte automaticamente a essas preferências. Evite "hardcodar" cores que não se ajustam ao modo claro/escuro.
* **Arquivos de Recursos (GResource):** Para aplicativos maiores, é uma boa prática incorporar seus arquivos CSS (e outros recursos como ícones) em um arquivo de recurso GResource. Isso simplifica a distribuição do aplicativo, pois todos os recursos são empacotados em um único binário. Você pode carregar CSS de um GResource usando `gtk_css_provider_load_from_resource()`.
* **Migração do GTK3 para GTK4:** Se você estiver migrando de um aplicativo GTK3, esteja ciente de que houve algumas mudanças na API do `GtkCssProvider`. As funções de carregamento de CSS não retornam mais um `GError` diretamente; em vez disso, você pode conectar-se ao sinal `GtkCssProvider::parsing-error` para rastrear erros.
* **Estilização de Subnós:** Widgets complexos no GTK são compostos por vários "subnós" CSS. Por exemplo, um `GtkButton` pode ter subnós para o seu conteúdo (rótulo, imagem) e sua área de preenchimento. O GTK Inspector ajuda a identificar esses subnós para uma estilização mais precisa.

Ao dominar o uso de CSS com GTK4 e Adwaita em C, você terá um controle poderoso sobre a aparência e a sensação dos seus aplicativos GNOME, garantindo uma experiência de usuário polida e consistente.
