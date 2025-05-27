# GTK4/Adwaita-1
by Google Gemini

# Gtk_Grid

No GTK4, o `GtkGrid` tem um conjunto de propriedades que permitem controlar seu comportamento de layout e espaçamento. Estas propriedades podem ser definidas tanto programaticamente em C (ou outras linguagens com bindings GTK) quanto em arquivos UI (XML) usando `GtkBuilder`.

Aqui estão as principais propriedades disponíveis para `GtkGrid`:

1.  **`baseline-row`**
    * **Tipo:** `gint` (inteiro)
    * **Descrição:** Define qual linha na grade deve ser usada como a linha de base global para o alinhamento de base. Isso é relevante quando widgets dentro de uma linha têm diferentes alinhamentos de base e você quer que a grade como um todo se alinhe com a linha de base de um de seus filhos.
    * **Funções de C:**
        * `gtk_grid_set_baseline_row(GtkGrid* grid, int row)`
        * `gtk_grid_get_baseline_row(GtkGrid* grid)`

2.  **`column-homogeneous`**
    * **Tipo:** `gboolean` (booleano)
    * **Descrição:** Se `TRUE`, todas as colunas na grade terão a mesma largura. A largura será determinada pela coluna mais larga para garantir que todo o conteúdo caiba. Se `FALSE` (o padrão), cada coluna terá apenas a largura necessária para acomodar seu conteúdo mais largo.
    * **Funções de C:**
        * `gtk_grid_set_column_homogeneous(GtkGrid* grid, gboolean homogeneous)`
        * `gtk_grid_get_column_homogeneous(GtkGrid* grid)`

3.  **`column-spacing`**
    * **Tipo:** `gint` (inteiro)
    * **Descrição:** Define a quantidade de espaço em pixels entre colunas consecutivas na grade.
    * **Funções de C:**
        * `gtk_grid_set_column_spacing(GtkGrid* grid, int spacing)`
        * `gtk_grid_get_column_spacing(GtkGrid* grid)`

4.  **`row-homogeneous`**
    * **Tipo:** `gboolean` (booleano)
    * **Descrição:** Se `TRUE`, todas as linhas na grade terão a mesma altura. A altura será determinada pela linha mais alta para garantir que todo o conteúdo caiba. Se `FALSE` (o padrão), cada linha terá apenas a altura necessária para acomodar seu conteúdo mais alto.
    * **Funções de C:**
        * `gtk_grid_set_row_homogeneous(GtkGrid* grid, gboolean homogeneous)`
        * `gtk_grid_get_row_homogeneous(GtkGrid* grid)`

5.  **`row-spacing`**
    * **Tipo:** `gint` (inteiro)
    * **Descrição:** Define a quantidade de espaço em pixels entre linhas consecutivas na grade.
    * **Funções de C:**
        * `gtk_grid_set_row_spacing(GtkGrid* grid, int spacing)`
        * `gtk_grid_get_row_spacing(GtkGrid* grid)`

**Propriedades Herdadas:**

Além das propriedades específicas de `GtkGrid`, ele herda propriedades de suas classes parentes na hierarquia de objetos do GTK. As mais relevantes são as propriedades de `GtkWidget` (como `width-request`, `height-request`, `halign`, `valign`, `hexpand`, `vexpand`, `margin-start`, `margin-end`, `margin-top`, `margin-bottom`, etc.).

**Propriedades de Layout por Filho (`GtkGridLayoutChild`):**

É importante notar que, quando você adiciona um widget a uma `GtkGrid` usando `gtk_grid_attach()`, as informações de posicionamento e abrangência (`column`, `row`, `width`, `height`) são, na verdade, propriedades do objeto `GtkGridLayoutChild` que representa o widget dentro da grade. Embora você as defina diretamente na chamada `attach`, elas são conceitualmente propriedades do "layout" do filho.

* `column`: A coluna inicial do filho.
* `row`: A linha inicial do filho.
* `column-span`: Quantas colunas o filho abrange.
* `row-span`: Quantas linhas o filho abrange.

Essas propriedades de layout do filho podem ser especificadas em arquivos UI da seguinte forma:

```xml
<object class="GtkGrid" id="my_grid">
  <child>
    <object class="GtkButton" id="button1">
      <property name="label">Botão 1</property>
      <layout>
        <property name="column">0</property>
        <property name="row">0</property>
        <property name="column-span">1</property>
        <property name="row-span">1</property>
      </layout>
    </object>
  </child>
  <child>
    <object class="GtkButton" id="button2">
      <property name="label">Botão 2 (span)</property>
      <layout>
        <property name="column">1</property>
        <property name="row">0</property>
        <property name="column-span">2</property> <property name="row-span">1</property>
      </layout>
    </object>
  </child>
</object>
```

Ao utilizar essas propriedades, você pode criar layouts complexos e responsivos com o `GtkGrid`, adaptando o espaçamento e o dimensionamento das células às suas necessidades de design.

Para definir a propriedade `row-homogeneous` de um `GtkGrid` no GTK4, você pode usar a função `gtk_grid_set_row_homogeneous()`.

**Propósito da Propriedade `row-homogeneous`:**

Quando `row-homogeneous` é definida como `TRUE`, todas as linhas na `GtkGrid` terão a mesma altura. O GTK calculará a altura máxima necessária para acomodar o conteúdo de todas as linhas e aplicará essa altura a todas elas. Se for `FALSE` (o padrão), cada linha terá apenas a altura necessária para acomodar seu conteúdo mais alto.

**Assinatura da Função:**

```c
void gtk_grid_set_row_homogeneous(GtkGrid* grid, gboolean homogeneous);
```

**Parâmetros Detalhados:**

* `grid`: Um ponteiro para a instância de `GtkGrid` na qual você deseja definir a propriedade.
* `homogeneous`: Um valor booleano (`TRUE` ou `FALSE`).
    * `TRUE`: Torna todas as linhas homogêneas (mesma altura).
    * `FALSE`: Torna as linhas não homogêneas (altura baseada no conteúdo).

**Exemplo de Uso:**

Aqui está um exemplo de como você pode usar `gtk_grid_set_row_homogeneous()`:

```c
#include <gtk/gtk.h>

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button1, *button2, *button3, *button4;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "GtkGrid com Row-Homogeneous");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);

  grid = gtk_grid_new ();
  // Define a propriedade row-homogeneous para TRUE
  gtk_grid_set_row_homogeneous (GTK_GRID (grid), TRUE);
  // Opcional: Para colunas homogêneas também
  // gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

  gtk_window_set_child (GTK_WINDOW (window), grid);

  button1 = gtk_button_new_with_label ("Botão Curto");
  button2 = gtk_button_new_with_label ("Botão com Conteúdo Mais Longo\npara Testar Altura");
  button3 = gtk_button_new_with_label ("Outro Botão");
  button4 = gtk_button_new_with_label ("Final");

  // Adiciona os botões à grade
  gtk_grid_attach (GTK_GRID (grid), button1, 0, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), button2, 0, 1, 1, 1); // Este botão terá mais texto, testando a altura da linha
  gtk_grid_attach (GTK_GRID (grid), button3, 1, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), button4, 1, 1, 1, 1);

  gtk_widget_show (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
```

**Como Observar a Diferença:**

Ao executar o código acima:

* Se você **não** chamar `gtk_grid_set_row_homogeneous (GTK_GRID (grid), TRUE);`, você notará que a segunda linha (onde o "Botão com Conteúdo Mais Longo" está) será mais alta que a primeira linha (onde o "Botão Curto" está), porque ela precisa acomodar o texto mais longo.
* Se você **chamar** `gtk_grid_set_row_homogeneous (GTK_GRID (grid), TRUE);`, ambas as linhas terão a mesma altura, que será a altura necessária para acomodar o "Botão com Conteúdo Mais Longo". Isso é útil para manter um alinhamento visual uniforme entre as linhas, mesmo que o conteúdo varie em altura.

**Em Resumo:**

`gtk_grid_set_row_homogeneous()` é uma ferramenta útil para controlar o layout vertical de seus widgets dentro de um `GtkGrid`, garantindo que todas as linhas mantenham uma altura consistente para uma aparência mais organizada.
