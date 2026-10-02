CXX = g++ # program for compiling
CFLAGS = -g 
SRC ?= morse.cc # daca nu am primit argumet fallback la ata
EXEC = $(basename $(SRC))
# $(echo "$SRC" | cut -d '.' -f 1)

# PT a evita sa faca confuzie cu nume de fisiere dir
.PHONY: all clean

# in caz aca dau doar make simplu regula fallback pe implicit
all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	find . -executable -type f | xargs rm
