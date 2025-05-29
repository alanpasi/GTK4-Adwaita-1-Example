# GTK4/Adwaita-1
by Alanpasi (27/05/2025)

Learning GTK4 and Adwaita-1 (C language)

GtkGrid
  data->grid = gtk_grid_new();
  gtk_widget_set_name(data->grid, "grid");
  gtk_window_set_child(GTK_WINDOW(data->window), data->grid);
  gtk_grid_set_row_homogeneous(GTK_GRID(data->grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(data->grid), TRUE);
  gtk_grid_set_row_spacing(GTK_GRID(data->grid), 30);
  gtk_grid_set_column_spacing(GTK_GRID(data->grid), 30);
  gtk_widget_set_margin_start(GTK_WIDGET(data->grid), 50);
  gtk_widget_set_margin_end(GTK_WIDGET(data->grid), 50);
  gtk_widget_set_margin_top(GTK_WIDGET(data->grid), 50);
  gtk_widget_set_margin_bottom(GTK_WIDGET(data->grid), 50);
