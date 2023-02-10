# Puedes amar 🐧 sin odiar a Microsoft

## Instalar GTK4 en una distribución basada en Debian

_Para instalar el paquete binario_

```
sudo apt install libgtk-4-1
```
_Para instalar el paquete de desarrollo_

```
sudo apt install libgtk-4-dev
```

_Para instalar ejemplos(opcional)_

```
sudo apt install gtk-4-examples
```

![GTK-PreWork](/00.-Sources/gtkprework.gif)

## Usando GTK4 en Ubuntu 21.10

_Una vez instalado necesitas probar que los paquetes funcionan, copia y pega en un archivo llamado Hola-mundo.c el código de un tradicional "Hola mundo" en GTK4_

```c
#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hola mundo en GTK4\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

  gtk_window_set_child (GTK_WINDOW (window), box);

  button = gtk_button_new_with_label ("Hello World");

  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);

  gtk_box_append (GTK_BOX (box), button);

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

_Compila usando el siguiente comando_
```
gcc $( pkg-config --cflags gtk4 ) -o Hola-mundo Hola-mundo.c $( pkg-config --libs gtk4 )
```

_gcc es el compilador que va a utilizar, etc._

_Todo esto nos crea un ejecutable llamado Hola-mundo, ejecutalo de la siguiente manera_

```
./Hola-mundo
```
![GTK-PreWork](/00.-Sources/ejecutable.gif)
