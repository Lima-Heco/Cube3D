vpath %.c %.o %.h %.a ./libft ./mlx ./Start_Game ./game_display
VPATH = . : ./libft ./Start_Game:
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = ./libft/
LIBS = -L./libft -lft -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

HEADERS = cube3d.h ./mlx/mlx.h

SRCS =	start_game.c open_map.c screen.c
OBJDIR = ./object/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

NAME = cube3D

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) mlx
	@echo "\033[2m\033[31mStart to make $(NAME)\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) $(LIBS) ./mlx/libmlx.a -o $(NAME) -lm
	@echo "\033[32m\t$(NAME) is done !\033[0m"

$(OBJDIR)%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(<D) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

libft:
	@echo "\033[2m\033[31mCooking the LIBFT\033[0m"
	@$(MAKE) -s -C ./libft
	@echo "\033[32m\tLIBFT is done!\033[0m"

mlx: libft
	@echo "\033[2m\033[31mCuting the MLX\033[0m"
	@$(MAKE) -s -C ./mlx/
	@echo "\033[32m\tMLX done!\033[0m"

clean:
	@echo "\033[2m\033[31mStart to CLEAN\033[0m"
	@rm -f $(OBJS)
	@$(MAKE) -s -C ./libft clean
	@$(MAKE) -s -C ./mlx clean
	@echo "\033[32m\tCLEAN is done!\033[0m"

fclean: clean
	@clear
	@echo "\033[2m\033[31mStart to FCLEAN\033[0m"
	@rm -f $(NAME)
	@$(MAKE) -s -C ./libft fclean
	@rm -rf ./mlx/libmlx.a
	@rm -rf $(OBJDIR)    # remove Object directory
	@echo "\033[32m\tFCLEAN is done!\033[0m"

re: fclean all


norme:
	norminette $(SRCS) $(HEADERS)

debug: $(OBJS)
	@clear
	@$(CC) $(CFLAGS) -g $(OBJS) -L$(LIB_DIR) $(LIBS) -o debug
	colour-valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 \
	./debug

.PHONY: all clean fclean re debug libft