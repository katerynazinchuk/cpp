CXX := c++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror -Iinclude

TARGET := megaphone
BUILD_DIR := build
SRCS := megaphone.cpp
OBJS := $(BUILD_DIR)/megaphone.o
#OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

RM := rm -rf


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/megaphone.o : megaphone.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c megaphone.cpp -o $(BUILD_DIR)/megaphone.o

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