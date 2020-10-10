EXECUTABLE := ex05circlelist
CATCH2_RUNNER := Catch2TestRunner
SRC_DIR := .
OBJ_DIR := .
LDFLAGS := 
CPPFLAGS :=
CXXFLAGS :=

# Build executable
all: CircleList.o CircleListMain.o
	g++ -o $(EXECUTABLE) $^

# Compile into an obj file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<


# Delete dependent files
clean:
	rm -f $(EXECUTABLE)
	rm -f ex05circlelist.exe
	rm -f *.o
	rm -f *out.txt

# Default target: Link obj.files to get executable
catch2-runner: CircleList.o  Catch2TestRunner.o
	g++ -o $(CATCH2_RUNNER) $^
	./$(CATCH2_RUNNER)

