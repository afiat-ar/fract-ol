
NAME = fractol.a

FILES = main/main								\
		includes/get_next_line/get_next_line	\
		srcs/check_and_init/check_input			\
		srcs/check_and_init/init				\
		srcs/fractal/start_fract				\
		srcs/fractal/mandelbrot					\
		srcs/fractal/mandelbar					\
		srcs/fractal/burning_ship				\
		srcs/fractal/buffalo					\
		srcs/fractal/julia						\
		srcs/key_events/key_hook				\
		srcs/key_events/key_events				\
		srcs/key_events/mouse_events			\
		srcs/check_and_init/printf_colors		\
		srcs/check_and_init/printf_colors2		\
		srcs/check_and_init/launch_header		\
		srcs/errors/initial_errors				\

RM = rm -rf
CC = clang
CFLAGS =
CFLAGS += -fsanitize=address -g3
FFLAGS = -lm -lmlx -lXext -lX11
#-framework OpenGL -framework AppKit

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(MAKE) -C ./includes/minilibx-linux/
	$(MAKE) -C ./includes/libft/
	mv ./includes/minilibx-linux/libmlx.a .
	mv ./includes/libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) -L . libft.a -lmlx $(FFLAGS) -o $(NAME)

clean:
	$(MAKE) -C ./includes/minilibx-linux/ clean
	$(MAKE) -C ./includes/libft/ clean
	$(RM) $(OBJS)

all: $(NAME)

re: clean all

fclean: clean
	$(RM) $(NAME)
	$(RM) libmlx.a
	$(RM) libft.a

.PHONY:
	all:
	$(CC) $(CFLAGS) $(OBJS) -I includes/*.h -L . -lmlx $(FFLAGS) -o $(NAME)
	re, fclean