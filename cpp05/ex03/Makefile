CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98 -g3

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
Intern.cpp
SRC_DIR = ./srcs
INCLUDE_DIR = ./include

OBJS_DIR = .objets
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

DIR_DUP = mkdir -p $(@D)
NAME = Form

all: $(NAME)
# @rm -rf $(OBJS_DIR) // supprimer le dossier .o mais empeche de gerer le relink 

$(NAME): $(OBJS)
	@$(CC) $(C_FLAGS) $^ -o $@

# $(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
$(OBJS_DIR)/%.o: %.cpp
	@$(DIR_DUP)
	@$(CC) $(C_FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJS_DIR)/main.o: main.cpp
	@$(DIR_DUP)
	@$(CC) $(C_FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re