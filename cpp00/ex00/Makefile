
CC = c++

C_FLAGS = -Wall -Werror -Wextra -std=c++98 -g3

SRCS = megaphone.cpp

SRCS_DIR = .

OBJS_DIR = .objets/

SRCS := $(SRCS:%=$(SRCS_DIR)/%)

OBJS = $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

DIR_DUP     = mkdir -p $(@D)

NAME = megaphone

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(C_FLAGS) $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re