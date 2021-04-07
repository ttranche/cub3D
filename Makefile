SRC = 	parser/cub_file.c \
		parser/cub_map_parser.c \
		parser/cub_map_setter.c \
		parser/cub_parser.c \
		parser/cub_setter.c \
		pathfinder/cub_astar.c \
		pathfinder/cub_node.c \
		pathfinder/cub_path.c \
		pathfinder/cub_pathfinder.c \
		pathfinder/cub_star_cardinal.c \
		render/cub_bitmap.c \
		render/cub_blur.c \
		render/cub_floor.c \
		render/cub_hud.c \
		render/cub_minimap.c \
		render/cub_raycast.c \
		render/cub_raycast2.c \
		render/cub_raycast3.c \
		render/cub_texture.c \
		render/cub_xquartz_layer.c \
		sprites/cub_doors.c \
		sprites/cub_goomba.c \
		sprites/cub_sprite_list.c \
		sprites/cub_sprites.c \
		utils/cub_checker.c \
		utils/cub_cleaner.c \
		utils/cub_error.c \
		utils/cub_keybinds.c \
		utils/cub_line_reader.c \
		utils/cub_rot.c \
		utils/cub_setup.c \
		utils/cub_utils.c \
		utils/cub_utils2.c \
		utils/cub_utils3.c \
		utils/cub_utils4.c \
		utils/cub_utils5.c \
		utils/cub_vec.c \
		utils/cub_vec2.c \
		world/cub_cardinal.c \
		world/cub_collide.c \
		world/cub_map.c \
		world/cub_player.c \
		world/cub_portal.c \
		world/cub_portal2.c \
		world/cub_portal_list.c \
		main.c
SRC_B = bonus/cub_sound_bonus.c \
		bonus/cub_other_bonus.c
SRC_N =	other/cub_other.c \
		other/cub_sound.c \

UNAME := $(shell uname)

PATH_DELAY = delay
PATH_MLX = mlx

OBJS_DEFAULT	= ${SRC:.c=.o}

OBJS_BONUS		= ${SRC_B:.c=.o}
OBJS_NOBONUS	= ${SRC_N:.c=.o}

CFLAGS = -Wall -Wextra -Werror

ifeq ($(UNAME), Darwin)
PATH_MLX = mlxmac
FLAGS = -Imlx -L${PATH_MLX} -lmlx -framework OpenGL -framework AppKit
FLAGS_BONUS = -Lbass -lbass -ldelay -Ldelay ${FLAGS}
LINUX = false
MACH_EXTRA = install_name_tool -change @loader_path/libbass.dylib @loader_path/bass/libbass.dylib $(NAME) \
				&& install_name_tool -change libmlx.dylib @loader_path/${PATH_MLX}/libmlx.dylib $(NAME)
else
FLAGS= -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/
FLAGS_BONUS = -Ibass -Lbass -lbass -Idelay -Ldelay -ldelay ${FLAGS}
LINUX = true
endif

NAME = cub3D
CC = gcc
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o} -D LINUX=${LINUX}

$(NAME): $(OBJS_DEFAULT) $(OBJS_NOBONUS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS_DEFAULT) $(OBJS_NOBONUS) $(FLAGS)
			${MACH_EXTRA}

bonus: $(OBJS_DEFAULT) $(OBJS_BONUS)
			make -C $(PATH_MLX)
			make -C $(PATH_DELAY)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS_DEFAULT) $(OBJS_BONUS) $(FLAGS_BONUS)
			${MACH_EXTRA}

clean:
			make -C $(PATH_MLX) clean
			make -C $(PATH_DELAY) clean
			${RM} ${OBJS_DEFAULT} ${OBJS_BONUS} ${OBJS_NOBONUS}

fclean: clean
			make -C $(PATH_DELAY) fclean
			${RM} ${NAME}

re: fclean all

.PHONY:		bonus all clean fclean re
