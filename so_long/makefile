NAME = so_long
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SO_LONG = so_long.c verif_map.c so_long_utils.c bfs/ft_bfs.c bfs/ft_bfs_utils.c
PRINTF = ft_printf/ft_putchar_printf.c ft_printf/ft_printf.c ft_printf/ft_itoa_printf.c ft_printf/ft_itoa_long.c ft_printf/ft_putnbr_base.c
GRAPH = graph/ft_graph.c graph/ft_graph_util.c graph/ft_game_img_init.c graph/ft_game_status_menu.c graph/ft_game_status_settings.c graph/ft_game_status_play_bot.c graph/ft_game_create_map.c graph/ft_game_create_bot.c graph/ft_game_status_see_wall.c graph/ft_game_create_wall.c graph/ft_game_img_del.c

all: $(NAME)
	make re -C libft/
	make re -C minilibx-linux/
$(NAME):
	cc -o $(NAME) $(GET_NEXT_LINE) $(SO_LONG) $(PRINTF) $(GRAPH) libft/libft.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -g -Lmlx -lXext -lX11 -Wall -Wextra -Werror
clean:
	rm $(NAME)
re : clean all
