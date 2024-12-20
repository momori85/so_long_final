NAME = so_long

OBJDIR = .obj

CC = cc

FLAGS = -Wall -Wextra -Werror -g

FULLFLAGS = -g -Lmlx -lXext -lX11 -lbsd -Wall -Wextra -Werror

GET_NEXT_LINE = get_next_line/get_next_line_bonus.c \
				get_next_line/get_next_line_utils_bonus.c

SO_LONG =	so_long.c \
			verif_map.c \
			so_long_utils.c \
			bfs/ft_bfs.c \
			bfs/ft_bfs_utils.c

PRINTF =	ft_printf/ft_putchar_printf.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_itoa_printf.c \
			ft_printf/ft_itoa_long.c \
			ft_printf/ft_putnbr_base.c

GRAPH = graph/ft_graph.c \
		graph/ft_graph_util.c \
		graph/ft_game_img_init.c \
		graph/ft_game_status_menu.c \
		graph/ft_game_status_settings.c \
		graph/ft_game_status_play_bot.c \
		graph/ft_game_create_map.c \
		graph/ft_game_create_bot.c \
		graph/ft_game_status_see_wall.c \
		graph/ft_game_create_wall.c \
		graph/ft_game_img_del.c \
		graph/ft_game_status_game.c \
		graph/ft_create_map_vision.c \
		graph/ft_game_create_player_map.c \
		graph/ft_game_init_two.c \
		graph/ft_bot_move.c \
		graph/ft_create_game_echap.c \
		graph/ft_game_status_save.c \
		graph/ft_create_mini_map.c \
		graph/ft_game_status_save_two.c \
		graph/ft_create_game_echap_two.c \
		graph/ft_game_img_init_two.c

SRC = $(SO_LONG) $(PRINTF) $(GRAPH) $(GET_NEXT_LINE)

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	@make -C libft/ -s
	@make -C minilibx-linux/ -s -j
	@$(CC) -o $(NAME) $(OBJ) libft/libft.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a $(FULLFLAGS)
	
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@make clean -C libft/ -s
	@make clean -C minilibx-linux/ -s
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re : fclean all

transparency:
	@if test -e minilibx-linux/mlx_xpm.c.tmp; then \
		mv minilibx-linux/mlx_xpm.c minilibx-linux/mlx_xpm.c.ok; \
		mv minilibx-linux/mlx_xpm.c.tmp minilibx-linux/mlx_xpm.c; \
		echo transparency disable; \
	else \
		mv minilibx-linux/mlx_xpm.c minilibx-linux/mlx_xpm.c.tmp; \
		mv minilibx-linux/mlx_xpm.c.ok minilibx-linux/mlx_xpm.c; \
		echo transparency enable; \
	fi
bonus: all

.PHONY: all clean fclean re bonus transparency
