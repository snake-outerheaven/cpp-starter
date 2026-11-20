CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror
SRC      = *.cpp
OUT      = a.out

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)

clean_build: clean
	rm -f *~ *.o *.core

.PHONY: all run clean clean_build
