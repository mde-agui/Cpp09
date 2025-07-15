NAME = btc
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)
	@/bin/echo -e "$(GREEN)BitcoinExchange is ready to process!$(RESET)"

$(NAME): $(OBJ)
	@/bin/echo -ne "$(BLUE)Linking.$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Linking..$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Linking...$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Linking....$(RESET)\r"
	@sleep 0.14
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@/bin/echo -ne "$(BLUE)Compiling.$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Compiling..$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Compiling...$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Compiling....$(RESET)\r"
	@sleep 0.14
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@/bin/echo -ne "$(BLUE)Cleaning objects.$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Cleaning objects..$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Cleaning objects...$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Cleaning objects....$(RESET)\r"
	@sleep 0.14
	@rm -f $(OBJ)

fclean: clean
	@/bin/echo -ne "$(BLUE)Cleaning logs.$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Cleaning logs..$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Cleaning logs...$(RESET)\r"
	@sleep 0.14
	@/bin/echo -ne "$(BLUE)Cleaning logs....$(RESET)\r"
	@sleep 0.14
	@rm -f $(NAME)
	@/bin/echo -e "$(GREEN)Everything is clean! 🧼$(RESET)"

re: fclean all

.PHONY: all clean fclean re
