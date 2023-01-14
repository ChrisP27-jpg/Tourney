COURSE = cs240
SEMESTER = spring2022

# Update the CP_NUMBER if you adapt this makefile for future assignments
CP_NUMBER = 3

# Change the following to your own information
LASTNAME = Painter
GITUSERID = ChrisP27-jpg

# The name of the executable
EXE = madness

# Name files according to CS240 naming conventions
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

# Store executables in a subdirectory
all: $(BIN)/$(EXE)

# Reflects how the files may have been named in CP0
$(BIN)/$(EXE): $(OBJ)/Team.o $(OBJ)/Madness.o
	$(CC) $(FLAGS) $(OBJ)/Team.o $(OBJ)/Madness.o -o $@

$(OBJ)/Madness.o: Madness.cpp Team.h Parser.h
	$(CC) $(FLAGS) -c Madness.cpp -o $@

# Update to add targets for your other .o files, following the Play.o sample
	
$(OBJ)/Team.o: Team.cpp Team.h
	$(CC) $(FLAGS) -c Team.cpp -o $@

# Run make tar to build a .tar.gz file appropriate for uploading to Brightspace
tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
