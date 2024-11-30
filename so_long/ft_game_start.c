#include "so_long.h"

typedef struct s_screen
{
    void *mlx;
    void *window_screen;
    void *img_start;
    void *img_settings;
    void *img_left;
    int i;
}               t_screen;

int ft_move(int keycode, t_screen *screen)
{
    if (keycode == 119 && screen->i != 0)
    {
        screen->i = 0;
        mlx_clear_window(screen->mlx, screen->window_screen);
        mlx_put_image_to_window(screen->mlx, screen->window_screen, screen->img_start, 0, 0);
    }
    if (keycode == 115 && screen->i == 0)
    {
        screen->i++;
        mlx_clear_window(screen->mlx, screen->window_screen);
        mlx_put_image_to_window(screen->mlx, screen->window_screen, screen->img_settings, 0, 0);
    }
    if (keycode == 100 && screen->i < 2)
    {
        screen->i++;
        mlx_clear_window(screen->mlx, screen->window_screen);
        mlx_put_image_to_window(screen->mlx, screen->window_screen, screen->img_left, 0, 0);
    }
    if (keycode == 97 && screen->i != 1)
    {
        screen->i--;
        mlx_clear_window(screen->mlx, screen->window_screen);
        mlx_put_image_to_window(screen->mlx, screen->window_screen, screen->img_settings, 0, 0);
    }
    if (keycode == 65307)
    {
        screen->i = -1;
        mlx_loop_end(screen->mlx);
    }
    if (keycode == 65293)
    {
        mlx_loop_end(screen->mlx);
    }
    return (1);
}

int ft_init_game_sreen(void)
{
    t_screen screen;
    int len;

    len = 100;
    screen.i = 0;
    screen.mlx = mlx_init();
    if (!screen.mlx)
    {
        fprintf(stderr, "Error initializing MiniLibX\n");
        return (0);
    }
    screen.window_screen = mlx_new_window(screen.mlx, 990, 990, "adventure_time");
    if (!screen.window_screen)
    {
        fprintf(stderr, "Error initializing MiniLibX\n");
        return (0);
    }
    screen.img_start = mlx_xpm_file_to_image(screen.mlx, ".img/start_screen.xpm", &len, &len);
    if (!screen.img_start)
    {
        fprintf(stderr, "Error loading start_screen.xpm\n");
        return (0);
    }
    screen.img_settings = mlx_xpm_file_to_image(screen.mlx, ".img/settings_screen.xpm", &len, &len);
    if (!screen.img_settings)
    {
        fprintf(stderr, "Error loading settings.xpm\n");
        return (0);
    }
    screen.img_left = mlx_xpm_file_to_image(screen.mlx, ".img/left_game.xpm", &len, &len);
    if (!screen.img_left)
    {
        fprintf(stderr, "Error loading left.xpm\n");
        return (0);
    }
    mlx_put_image_to_window(screen.mlx, screen.window_screen, screen.img_start, 0, 0);
    mlx_key_hook(screen.window_screen, ft_move, &screen);
	mlx_loop(screen.mlx);
    mlx_destroy_image(screen.mlx, screen.img_start);
    mlx_destroy_image(screen.mlx, screen.img_settings);
    mlx_destroy_image(screen.mlx, screen.img_left);
	mlx_clear_window(screen.mlx, screen.window_screen);
	mlx_destroy_window(screen.mlx, screen.window_screen);
	mlx_destroy_display(screen.mlx);
    return (screen.i);
}