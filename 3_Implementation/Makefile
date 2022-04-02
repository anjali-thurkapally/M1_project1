# Name of the project
PROJECT_NAME = ToDo

# Output directory
BUILD = build

# All source code files
SRC = src/add.c\
src/delete.c\
src/display.c\
src/mark.c\

#test
TEST_SRC = ${SRC}\
test/todo_test.c\
unity/unity.c\

# All include folders with header files
INC	= -Iinc\
-Iunity\

#Library Inlcudes
INCLUDE_LIBS = 

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME)

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc main.c $(SRC) $(INC) -o $(PROJECT_OUTPUT).out -fcommon

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out

# Document the code using Doxygen
doc:
	make -C ./documentation

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS) -fcommon
	./$(TEST_OUTPUT)

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT) todos.bin

# Create new build folder if not present
$(BUILD):
	mkdir build