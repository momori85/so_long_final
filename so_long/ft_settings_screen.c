#include "so_long.h"

typedef struct s_settings
{
    void *mlx;
    void *window_settings;
    void *img_480;
    void *img_720;
    void *img_1080;
    void *img_exit;
    int i;
}               t_settings;

int ft_settings(int keycode, t_settings *settings)
{
    if (keycode == 119 && settings->i > 0)
    {
        settings->i--;
        mlx_clear_window(settings->mlx, settings->window_settings);
        if (settings->i == 0)
            mlx_put_image_to_window(settings->mlx, settings->window_settings, settings->img_1080, 0, 0);
        if (settings->i == 1)
            mlx_put_image_to_window(settings->mlx, settings->window_settings, settings->img_720, 0, 0);
        if (settings->i == 2)
            mlx_put_image_to_window(settings->mlx, settings->window_settings, settings->img_480, 0, 0);
        if (settings->i == 3)
            mlx_put_image_to_window(settings->mlx, settings->window_settings, settings->img_exit, 0, 0);
    }
    if (keycode == 115 && settings->i < 3)
    {
        settings->i++;
        mlx_clear_window(settings->mlx, settings->window_settings);
        if (settings->i == 0)
            mlx_put_image_to_window(settings->mlx, settings->window_settings, settings->img_1080, 0, 0);
        if (settings->i == 1)
            mlx_put_image_to_window(settings->mlx, settings->window_settings, settings->img_720, 0, 0);
        if (settings->i == 2)
            mlx_put_image_to_window(settings->mlx, settings->window_settings, settings->img_480, 0, 0);
        if (settings->i == 3)
            mlx_put_image_to_window(settings->mlx, settings->window_settings, settings->img_exit, 0, 0);
    }
    if (keycode == 65307)
    {
        settings->i = -1;
        mlx_loop_end(settings->mlx);
    }
    if (keycode == 65293)
    {
        mlx_loop_end(settings->mlx);
    }
    return (1);
}

int ft_init_settings_sreen(void)
{
    t_settings settings;
    int len;

    len = 100;
    settings.i = 0;
    settings.mlx = mlx_init();
    if (!settings.mlx)
    {
        fprintf(stderr, "Error initializing MiniLibX\n");
        return (0);
    }
    settings.window_settings = mlx_new_window(settings.mlx, 990, 990, "adventure_time");
    if (!settings.window_settings)
    {
        fprintf(stderr, "Error initializing MiniLibX\n");
        return (0);
    }
    settings.img_480 = mlx_xpm_file_to_image(settings.mlx, ".img/settings_480p.xpm", &len, &len);
    if (!settings.img_480)
    {
        fprintf(stderr, "Error loading start_settings.xpm\n");
        return (0);
    }
    settings.img_720 = mlx_xpm_file_to_image(settings.mlx, ".img/settings_720p.xpm", &len, &len);
    if (!settings.img_720)
    {
        fprintf(stderr, "Error loading settings.xpm\n");
        return (0);
    }
    settings.img_1080 = mlx_xpm_file_to_image(settings.mlx, ".img/settings_1080p.xpm", &len, &len);
    if (!settings.img_1080)
    {
        fprintf(stderr, "Error loading left.xpm\n");
        return (0);
    }
    settings.img_exit = mlx_xpm_file_to_image(settings.mlx, ".img/settings_exit.xpm", &len, &len);
    if (!settings.img_exit)
    {
        fprintf(stderr, "Error loading left.xpm\n");
        return (0);
    }
    mlx_put_image_to_window(settings.mlx, settings.window_settings, settings.img_1080, 0, 0);
    mlx_key_hook(settings.window_settings, ft_settings, &settings);
	mlx_loop(settings.mlx);
    mlx_destroy_image(settings.mlx, settings.img_480);
    mlx_destroy_image(settings.mlx, settings.img_720);
    mlx_destroy_image(settings.mlx, settings.img_1080);
    mlx_destroy_image(settings.mlx, settings.img_exit);
	mlx_clear_window(settings.mlx, settings.window_settings);
	mlx_destroy_window(settings.mlx, settings.window_settings);
	mlx_destroy_display(settings.mlx);
    return (settings.i);
}
