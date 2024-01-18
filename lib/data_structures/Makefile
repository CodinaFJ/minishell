#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: data_structures														#\
#########################################################################################

NAME = $(BIN_DIR)data_structures.a
TEST = $(BIN_DIR)test.out

CC	= cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ../libft/bin/
FT_PRINTF_PATH = ../ft_printf/
LIBFT = $(LIBFT_PATH)libft.a
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a
AR = ar rcs
RM = rm -rf

########################################################################################\
Directories
########################################################################################

HDR_DIR	=	./lib/
BIN_DIR = 	./bin/
OBJ_DIR =	$(BIN_DIR)obj/
SRC_DIR	=	./src/

########################################################################################\
Sources & objects
########################################################################################

FILES	=	stack					\
			stack_info				\
			stack_operations		\
			stack_arithmetic

SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

########################################################################################\
Sources & objects - Test
########################################################################################

FILES_TEST	=	main				\
				btree				\
				btree_operations


SRCS_TEST	=	$(addsuffix .c, $(FILES_TEST))
OBJS_TEST	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_TEST)))

########################################################################################\
Colors
########################################################################################

DEF_COLOR = \033[0;39m
CUT = 		\033[K
R = 		\033[31;1m
G = 		\033[32;1m
Y = 		\033[33;1m
B = 		\033[34;1m
P = 		\033[35;1m
GR = 		\033[30;1m
END = 		\033[0m

########################################################################################\
Rules
########################################################################################

all: libft ft_printf $(NAME)

libft: $(LIBFT)

ft_printf: $(FT_PRINTF)

test:libft ft_printf $(TEST)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_PATH)

$(TEST): $(OBJS_TEST)
	@$(CC) $(OBJS_TEST) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "\n$(G)Test compilation finished!$(DEF_COLOR)-> $(TEST)\n"

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\n$(G)Library compiled!$(DEF_COLOR)-> $@\n"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(R)[$(NAME)] All $(OBJ_DIR)*.o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Stack.a binary removed$(DEF_COLOR)\n"

clean_libs:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)

fclean_libs:
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)

re: fclean all

norminette:
	norminette $(SRC_DIR)

.PHONY: all bonus clean fclean re server client norminette