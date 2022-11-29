NAME		= miniRT

FSANITIZE	= -g3 -fsanitize=address

SRCSPATH 	= srcs

OBJ_PATH	= objs

ERR_PATH	= error

PARS_PATH	= parsing

PLANE_PATH	= plane

VECT_PATH	= vectors

SPHERE_PATH	= sphere

CYL_PATH 	= cylinder

GRAPHIC_PATH = graphic

<<<<<<< HEAD
FT_PATH = libft

HEADERS = includes \

SRCS = 	main.c						\
		dot.c						\
		init_vect.c					\
		vect_operations.c			\
		vect_product.c 				\
		vect_dist.c					\
		rgb_to_hex.c				\
		hex_to_rgb.c				\
		init_sphere.c				\
		intersphere.c				\
		init_plane.c				\
		interplane.c				\
		get_intersection_point.c	\
		intercylinder.c 			\
		init_cylinder.c				\
		inter_cylinder_bot_top.c	\
		init_ray.c					\
		error_print.c				\
		check_args.c				\
		parsing.c					\
		
=======
FT_PATH		= libft

HEADERS		= includes \

SRCS		=	main.c						\
				init_vect.c					\
				vect_dist.c					\
				rgb_to_hex.c				\
				init_plane.c				\
				interplane.c				\
				intercylinder.c 			\
				init_cylinder.c				\
				inter_cylinder_bot_top.c	\
				init_ray.c					\
				ambiant.c					\
				camera.c					\
				check_args.c				\
				check_line.c				\
				check_line2.c				\
				cylinder.c					\
				dot.c						\
				error_print.c				\
				free_exit.c					\
				get_intersection_point.c	\
				get_parameter.c				\
				get_parameter2.c			\
				init.c						\
				init_sphere.c				\
				intersphere.c				\
				light.c						\
				line.c						\
				list.c						\
				parsing.c					\
				plane.c						\
				range.c						\
				struct_spe.c				\
				struct_spe2.c				\
				sphere.c					\
				utils.c						\
				vect_operations.c			\
				vect_product.c 				\

>>>>>>> main
CC			= gcc #$(FSANITIZE)

CFLAGS		= -MMD -Wall -Werror -Wextra -g3

RM			= rm -rf

OBJS		=  $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

DEPS		= $(OBJS:.o=.d)

SUPPR		=	\033[00m
GRAS		=	\033[01m
CLIGNO		=	\033[05m
GREEN		=	\033[32m
YELLOW		=	\033[33m
RED			=	\033[31m
WHITE		=	\033[37m

vpath %.h $(HEADERS)
vpath %.c $(SRCSPATH)				\
 	$(SRCSPATH)/$(VECT_PATH) 		\
 	$(SRCSPATH)/$(SPHERE_PATH) 		\
 	$(SRCSPATH)/$(PLANE_PATH) 		\
 	$(SRCSPATH)/$(CYL_PATH) 		\
 	$(SRCSPATH)/$(ERR_PATH) 		\
 	$(SRCSPATH)/$(PARS_PATH) 		\
 	$(SRCSPATH)/$(GRAPHIC_PATH) 	\


vpath %.o $(OBJ_PATH)

all				: $(NAME)

$(NAME)			: $(OBJS)
			@make -C $(FT_PATH)
			@$(CC) $(CFLAGS) $(OBJS) -I $(HEADERS) -I libft/include -L$(FT_PATH) -lft -lm -o $(NAME)
			@echo "$(WHITE)Compilation $(GRAS)miniRT $(GREEN)$(GRAS)$(CLIGNO)OK$(SUPPR)"

$(OBJ_PATH)/%.o	: %.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -I libft/include -I/usr/include -lm -c $< -o $@

$(OBJS)			: | $(OBJ_PATH)

$(OBJ_PATH)		:
	@mkdir -p $(OBJ_PATH)

clean			:
	@make clean -C $(FT_PATH)
	@${RM} $(OBJ_PATH)

fclean			:
	@make fclean -C $(FT_PATH)
	@make clean
	@${RM} ${NAME}

re				:
	@make fclean
	@make all

-include $(DEPS)

.PHONY			: all clean fclean re
