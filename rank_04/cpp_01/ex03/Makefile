CXX := c++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror

NAME := weapon
BUILD_DIR := build
SRCS := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(BUILD_DIR)/%.o : %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@printf "Cleaning..."
	@$(RM) $(BUILD_DIR)
	@printf " done\n"

fclean: clean
	@printf "Removing executables..."
	@$(RM) $(NAME)
	@printf " done\n"

re: fclean all

.PHONY: all clean fclean re