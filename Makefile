#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: minishell																#\
#########################################################################################

NAME = $(BIN_DIR)minishell

CC	= cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./lib/libft/bin/
DATA_STR_PATH = ./lib/data_structures_C/bin/
LIBFT = $(LIBFT_PATH)libft.a
DATA_STR = $(DATA_STR_PATH)data_structures.a
AR = ar rcs
RM = rm -rf

########################################################################################\
Directories
########################################################################################

HDR_DIR	=	./lib/
BIN_DIR = 	./bin/
SRC_DIR	=	./src/

MS_DIR =		./
LEXER_DIR =		lexer/
AUTOMATA_DIR =	automata/
BUILTINS_DIR =	builtins/
SIGNALS_DIR = 	signals/

BIN_DIRS	=	$(addprefix $(BIN_DIR), $(MS_DIR))			\
				$(addprefix $(BIN_DIR), $(BUILTINS_DIR))	\
				$(addprefix $(BIN_DIR), $(SIGNALS_DIR))		\
				$(addprefix $(BIN_DIR), $(AUTOMATA_DIR))	\
				$(addprefix $(BIN_DIR), $(LEXER_DIR))

########################################################################################\
Sources & objects
########################################################################################

MS_FILES	=	main			\
				minishell_init	\

LEXER_FILES	=	lexer			\
				token			\
				token_args		\
				operator		\
				command			\
				command_args	\
				token_btree

BUILTINS_FILES	=	builtin			\
					builtins_array	\
					ft_cd			\
					ft_echo			\
					ft_env			\
					ft_exit			\
					ft_export		\
					ft_pwd			\
					ft_unset	

AUTOMATA_FILES	=	automata					\
					automata_evaluate			\
					automata_lexer_actions		\
					automata_lexer_init			\
					automata_lexer_transitions	\
					automata_exp_actions		\
					automata_exp_init			\
					automata_exp_transitions

SIGNALS_FILES	=	signals

FILES	=	$(addprefix $(MS_DIR), $(MS_FILES))				\
			$(addprefix $(AUTOMATA_DIR), $(AUTOMATA_FILES))	\
			$(addprefix $(LEXER_DIR), $(LEXER_FILES))   	\
			$(addprefix $(SIGNALS_DIR), $(SIGNALS_FILES))  	\
			$(addprefix $(BUILTINS_DIR), $(BUILTINS_FILES))

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(BIN_DIR), $(addsuffix .o, $(FILES)))

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

all: libft data_str $(NAME)

libft: $(LIBFT)

data_str: $(FT_PRINTF)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(DATA_STR):
	@make -C $(DATA_STR_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(DATA_STR) -o $@
	@echo "\n$(G)[MINISHELL] Compilation finished!$(DEF_COLOR)-> $(NAME)\n"

$(BIN_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(BIN_DIRS)
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c $< -o $@

debug: CFLAGS += -g3
debug: all

clean:
	@$(RM) $(OBJS)
	@echo "$(R)[$(NAME)] All $(OBJ_DIR)*.o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)[MINISHELL] binary removed$(DEF_COLOR)\n"

clean_libs:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(DATA_STR_PATH)

fclean_libs:
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(DATA_STR_PATH)

re: fclean all

norminette:
	norminette $(SRC_DIR)

run:
	@$(NAME) && ([ $$? -eq 0 ] && echo "") || echo "" 		

.PHONY: all clean fclean re norminette
