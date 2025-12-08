CXX := c++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror -Iinclude

TARGET := phonebook
BUILD_DIR := build
SRCS := PhoneBook.cpp
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

RM := rm -rf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o : %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@printf "Cleaning..."
	@$(RM) $(BUILD_DIR)
	@printf " done\n"

fclean: clean
	@printf "Removing executables..."
	@$(RM) $(TARGET)
	@printf " done\n"

re: fclean all

.PHONY: all clean fclean re