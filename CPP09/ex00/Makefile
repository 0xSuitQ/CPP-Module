NAME := BitcoinExchange
CC := g++
CFLAGS := -std=c++98 -Wall -Wextra -Werror
SRC_DIR := .
HSRCS := .
OBJ_DIR := obj

SRC = main.cpp \
	BitcoinExchange.cpp \

OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(HSRCS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re