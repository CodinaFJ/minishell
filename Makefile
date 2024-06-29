#########################################################################################\
#		-MAKEFILE-																		#\
#		PROJECT: minishell																#\
#########################################################################################

NAME = $(BIN_DIR)minishell

CC	= cc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -lreadline
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

MS_DIR =			./
LEXER_DIR =			lexer/
INTERPRETER_DIR =	interpreter/
AUTOMATA_EXP_DIR =	automata/expander/
AUTOMATA_LEX_DIR =	automata/lexer/
BUILTINS_DIR =		builtins/
SIGNALS_DIR = 		signals/
ENV_DIR =			environment/
TEST_DIR =			test/

BIN_DIRS	=	$(addprefix $(BIN_DIR), $(MS_DIR))			\
				$(addprefix $(BIN_DIR), $(BUILTINS_DIR))	\
				$(addprefix $(BIN_DIR), $(SIGNALS_DIR))		\
				$(addprefix $(BIN_DIR), $(ENV_DIR))			\
				$(addprefix $(BIN_DIR), $(AUTOMATA_EXP_DIR))	\
				$(addprefix $(BIN_DIR), $(AUTOMATA_LEX_DIR))	\
				$(addprefix $(BIN_DIR), $(TEST_DIR))	\
				$(addprefix $(BIN_DIR), $(INTERPRETER_DIR))	\
				$(addprefix $(BIN_DIR), $(LEXER_DIR))

########################################################################################\
Sources & objects
########################################################################################

MS_FILES	=	main			\
				minishell_init	\

LEXER_FILES	=	token			\
				token_args		\
				operator		\
				command			\
				command_args	\
				token_btree

INTERPRETER_FILES	=	interpreter			\
						interpreter_expand

BUILTINS_FILES	=	builtin			\
					builtins_array	\
					ft_cd			\
					ft_echo			\
					ft_env			\
					ft_exit			\
					ft_export		\
					ft_pwd			\
					ft_unset	

AUTOMATA_EXP_FILES	=	automata_exp_evaluate		\
						automata_exp_actions		\
						automata_exp_init			\
						automata_exp_utils			\
						automata_exp_transitions

AUTOMATA_LEX_FILES	=	automata_lexer_evaluate		\
						automata_lexer_actions		\
						automata_lexer_init			\
						automata_lexer_transitions

ENV_FILES =		environment			\
				environment_vars

SIGNALS_FILES	=	signals


TEST_FILES	=	test				\
				test_automata_exp	\
				test_environment	\
				test_automata_lexer

FILES	=	$(addprefix $(MS_DIR), $(MS_FILES))				\
			$(addprefix $(AUTOMATA_EXP_DIR), $(AUTOMATA_EXP_FILES))	\
			$(addprefix $(AUTOMATA_LEX_DIR), $(AUTOMATA_LEX_FILES))	\
			$(addprefix $(LEXER_DIR), $(LEXER_FILES))   	\
			$(addprefix $(INTERPRETER_DIR), $(INTERPRETER_FILES))   	\
			$(addprefix $(SIGNALS_DIR), $(SIGNALS_FILES))  	\
			$(addprefix $(ENV_DIR), $(ENV_FILES))  	\
			$(addprefix $(BUILTINS_DIR), $(BUILTINS_FILES)) \
			$(addprefix $(TEST_DIR), $(TEST_FILES))

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
	@$(CC) $(OBJS) $(LIBFT) $(DATA_STR) $(FLAGS) -o $@
	@echo "\n$(G)[MINISHELL] Compilation finished!$(DEF_COLOR)-> $(NAME)\n"

bear:
	@bear -- make

run:
	$(NAME)

test: debug $(NAME)
	@$(NAME) test

$(BIN_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(BIN_DIRS)
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c $< -o $@

$(TEST_DIR)%.o:$(TEST_DIR)%.c
	@mkdir -p $(BIN_DIR)
	@echo "$(Y)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c $< -o $@

debug: CFLAGS += -g3
#debug: CFLAGS += -w
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

.PHONY: all clean fclean re norminette
