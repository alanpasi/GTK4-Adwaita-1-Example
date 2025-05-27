#include <adwaita.h>

/* Struct of Widgets */
typedef struct {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    GtkWidget *button;
} WidgetData;

// Prototypes
void load_css(void);
