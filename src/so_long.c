#include "../inc/so_long.h"
#include "../minilibx-linux/mlx.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>


int main() {
    void *mlx_ptr;
    void *win_ptr;

    // Initialisation de la connexion avec le serveur X
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL) {
        // Gestion de l'erreur si l'initialisation échoue
        return 1;
    }

    // Création d'une fenêtre de taille 500x500 avec le titre "Hello, Minilibx!"
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello, Minilibx!");
    if (win_ptr == NULL) {
        // Gestion de l'erreur si la création de la fenêtre échoue
        mlx_destroy_display(mlx_ptr); // Fermeture de la connexion avec le serveur X
        return 1;
    }

    // Boucle pour garder la fenêtre ouverte
    mlx_loop(mlx_ptr);

    return 0;
}