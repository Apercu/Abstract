# ========================================================================== #
#                                                                            #
#    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                      #
#    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                      #
#    ███████║ █████╔╝ ███████║██║   ██║    created by: bgronon               #
#    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝            at: 2015-01-31 11:31:42   #
#         ██║███████╗ ██║  ██║ ╚████╔╝                                       #
#         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                        #
#                                                                            #
# ========================================================================== #

NAME		= avm
CC			= g++
FLAGS		= -Wall -Werror -Wextra -pedantic -std=c++11
LIBS		=
INC			= -I . -I Instruction -I IOperand -I Operand -I Parser -I Vm

SRC			=	main.cpp \
				Instruction/Instruction.cpp \
				Vm/Vm.cpp \
				Parser/Parser.cpp \

DIR_OBJ		= .obj
DIR_LIST	= Operand Vm Parser Instruction IOperand

OBJ			= $(addprefix $(DIR_OBJ)/, $(SRC:.cpp=.o))

all: $(NAME)

$(addprefix $(DIR_OBJ)/, %.o): %.cpp **/*.hpp *.hpp
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@printf "\e[32m[✔]\e[0m\n"

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

$(DIR_OBJ) :
	@/bin/mkdir $(DIR_OBJ); \
		for DIR in $(DIR_LIST); \
		do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
		done

clean:
	@/bin/rm -rf $(DIR_OBJ);
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

.PHONY: clean fclean re
