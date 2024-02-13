/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:31:53 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 15:08:46 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"
#include "../minilibx-linux/mlx.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>


int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
	{
		map_test(argv);
		if(open_window() == 1)
			return(1);
	}
	return (0);
}

int open_window(void)
{
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