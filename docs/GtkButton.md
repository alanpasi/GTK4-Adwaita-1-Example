# GTK4/Adwaita-1
by Google Gemini

# Gtk_Button

No GTK4, o `GtkButton` possui as seguintes propriedades diretas, além de herdar diversas outras de suas classes parentes na hierarquia de objetos (principalmente `GtkWidget`).

**Propriedades Específicas de `GtkButton`:**

1.  **`can-shrink`**
    * **Tipo:** `gboolean` (booleano)
    * **Descrição:** Se `TRUE`, permite que o tamanho do botão seja menor que o tamanho natural de seu conteúdo. Para botões de texto, isso pode permitir que o rótulo seja truncado com reticências (ellipsizing). Se o conteúdo do botão for um ícone ou um widget personalizado, essa propriedade pode não ter efeito.
    * **Funções de C:**
        * `gtk_button_set_can_shrink(GtkButton* button, gboolean can_shrink)`
        * `gtk_button_get_can_shrink(GtkButton* button)`
    * **Desde:** GTK 4.12

2.  **`child`**
    * **Tipo:** `GtkWidget*` (ponteiro para `GtkWidget`)
    * **Descrição:** O widget filho contido dentro do botão. Um botão pode conter apenas um widget filho.
    * **Funções de C:**
        * `gtk_button_set_child(GtkButton* button, GtkWidget* child)`
        * `gtk_button_get_child(GtkButton* button)`

3.  **`has-frame`**
    * **Tipo:** `gboolean` (booleano)
    * **Descrição:** Se `TRUE` (o padrão), o botão terá um "frame" visual (uma borda ou fundo que o faz parecer um botão). Se `FALSE`, o botão será "plano" (flat), sem a aparência de um frame, útil para botões que se parecem mais com links ou itens de menu.
    * **Funções de C:**
        * `gtk_button_set_has_frame(GtkButton* button, gboolean has_frame)`
        * `gtk_button_get_has_frame(GtkButton* button)`

4.  **`icon-name`**
    * **Tipo:** `const char*` (string)
    * **Descrição:** O nome de um ícone a ser usado para preencher automaticamente o botão. O ícone será procurado no tema de ícones atual. Se um `label` também for definido, o ícone e o label aparecerão juntos.
    * **Funções de C:**
        * `gtk_button_set_icon_name(GtkButton* button, const char* icon_name)`
        * `gtk_button_get_icon_name(GtkButton* button)`

5.  **`label`**
    * **Tipo:** `const char*` (string)
    * **Descrição:** O texto do rótulo dentro do botão, se o botão contiver um widget `GtkLabel`. Isso é uma conveniência; internamente, o GTK cria um `GtkLabel` como filho do botão.
    * **Funções de C:**
        * `gtk_button_set_label(GtkButton* button, const char* label)`
        * `gtk_button_get_label(GtkButton* button)`

6.  **`use-underline`**
    * **Tipo:** `gboolean` (booleano)
    * **Descrição:** Se `TRUE`, um sublinhado no texto do `label` indica que o caractere seguinte deve ser usado como mnemônico (atalho de teclado). Por exemplo, se o `label` for "_Sair", pressionar `Alt+S` ativará o botão.
    * **Funções de C:**
        * `gtk_button_set_use_underline(GtkButton* button, gboolean use_underline)`
        * `gtk_button_get_use_underline(GtkButton* button)`

**Propriedades Herdadas (de `GtkWidget` e `GtkAccessible`):**

Além das propriedades acima, `GtkButton` herda um grande número de propriedades de suas classes base, que afetam seu tamanho, alinhamento, visibilidade, sensibilidade e comportamento de acessibilidade. Algumas das mais comuns e úteis incluem:

* **De `GtkWidget`:**
    * `width-request`: Largura mínima desejada do widget.
    * `height-request`: Altura mínima desejada do widget.
    * `halign`: Alinhamento horizontal (`GTK_ALIGN_START`, `GTK_ALIGN_END`, `GTK_ALIGN_CENTER`, `GTK_ALIGN_FILL`).
    * `valign`: Alinhamento vertical (`GTK_ALIGN_START`, `GTK_ALIGN_END`, `GTK_ALIGN_CENTER`, `GTK_ALIGN_FILL`).
    * `hexpand`: Se o widget deve expandir horizontalmente para preencher o espaço disponível.
    * `vexpand`: Se o widget deve expandir verticalmente para preencher o espaço disponível.
    * `margin-start`, `margin-end`, `margin-top`, `margin-bottom`: Margens ao redor do widget.
    * `sensitive`: Se o widget pode receber eventos de entrada do usuário (cliques, teclado).
    * `visible`: Se o widget está visível ou oculto.
    * `css-classes`: Classes CSS para estilização personalizada.
    * `cursor`: O cursor do mouse a ser exibido sobre o widget.
    * `tooltip-text`: Texto da dica de ferramenta.
    * `focus-on-click`: Se o widget deve ganhar o foco do teclado ao ser clicado.
    * `receives-default`: Se o widget pode ser o widget padrão em sua janela (ativado com Enter).

* **De `GtkAccessible`:**
    * `accessible-role`: O papel de acessibilidade do widget para tecnologias assistivas.
    * `label` (herdada, mas `GtkButton` tem sua própria `label` para conveniência do conteúdo).

Você pode explorar a documentação oficial do GTK4 para obter a lista completa e os detalhes mais recentes de todas as propriedades de `GtkButton` e suas classes base. A documentação é a fonte mais precisa para informações detalhadas.
