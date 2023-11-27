vpath %.c %.o %.h %.a ./libft ./mlx
VPATH = . : ./libft :
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = ./libft/
LIBS = -lft -lreadline -lncurses -lhistory

HEADERS = cube3d.h

SRCS =	start_game.c
OBJDIR = ./object/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

NAME = cube3D

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) libft mlx
	@echo "\033[2m\033[31mStart to make $(NAME)\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) $(LIBS) -o $(NAME) -lm
	@echo "\033[32m\t$(NAME) is done !\033[0m"

$(OBJDIR)%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(<D) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

libft:
	@echo "\033[2m\033[31mCooking the LIBFT\033[0m"
	@$(MAKE) -s -C ./libft
	@echo "\033[32m\tLIBFT is done!\033[0m"

mlx:
	@echo "\033[2m\033[31mCuting the MLX\033[0m"
	@$(MAKE) -s -C ./mlx
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
	@$(MAKE) -s -C ./mlx fclean
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