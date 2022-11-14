NAME = miniRT

FSANITIZE = -g3 -fsanitize=address

SRCSPATH = srcs

OBJ_PATH = objs

ERR_PATH = error

VECT_PATH = vectors

SPHERE_PATH = sphere

PLANE_PATH = plane

FT_PATH = libft

HEADERS = includes \

SRCS = 	main.c				\
		dot.c				\
		vect_operations.c	\
		vect_product.c 		\
		init_sphere.c		\
		intersphere.c		\
		get_intersection_point.c \


		
CC = gcc #$(FSANITIZE)

CFLAGS = -MMD -Wall -Werror -Wextra -g3

RM = rm -rf

OBJS =  $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

SUPPR		=	\033[00m
GRAS		=	\033[01m
CLIGNO		=	\033[05m
GREEN		=	\033[32m
YELLOW		=	\033[33m
RED			=	\033[31m
WHITE		=	\033[37m

vpath %.h $(HEADERS)
vpath %.c $(SRCSPATH)			\
 	$(SRCSPATH)/$(VECT_PATH) 	\
 	$(SRCSPATH)/$(SPHERE_PATH) 	\
 	$(SRCSPATH)/$(PLANE_PATH) 	\


vpath %.o $(OBJ_PATH)

all: $(NAME)

$(NAME):		$(OBJS)
			@make -C $(FT_PATH)
			@$(CC) $(CFLAGS) $(OBJS) -I $(HEADERS) -I libft/include -L$(FT_PATH) -lft -lm -o $(NAME)
			@echo "$(WHITE)Compilation $(GRAS)miniRT $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)"

$(OBJ_PATH)/%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -I libft/include -I/usr/include -lm -c $< -o $@

$(OBJS):	| $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@make clean -C $(FT_PATH)
	@${RM} $(OBJ_PATH)

fclean:
	@make fclean -C $(FT_PATH)
	@make clean
	@${RM} ${NAME}

re:
	@make fclean
	@make all

-include $(DEPS)

.PHONY:			all clean fclean re