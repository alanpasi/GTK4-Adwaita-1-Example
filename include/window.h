#include <adwaita.h>

/* Struct of Widgets */
typedef struct {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    GtkWidget *lbl_headerbar_title;
    GtkWidget *button;
} WidgetData;

// Prototypes
void load_css(void);
