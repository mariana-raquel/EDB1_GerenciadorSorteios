PROGRAM=gerenciador_sorteios
COMPILER=gcc
CPPFLAGS=-I. -W
OBJDIR=obj
BINDIR=bin
SRCDIR=src
HEADER_CODE=$(wildcard include/*.h)
SOURCE_CODE=$(wildcard src/*.c)
OBJ_FILES=$(patsubst %.c, $(OBJDIR)/%.o, $(SOURCE_CODE))

$(PROGRAM): $(OBJ_FILES)
	$(COMPILER) $(CPPFLAGS) -o $(BINDIR)/$(PROGRAM) $(OBJ_FILES)

$(OBJDIR)/%.o: %.c $(HEADER_CODE)
	$(COMPILER) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/$(SRCDIR)/*.o $(BINDIR)/$(PROGRAM)