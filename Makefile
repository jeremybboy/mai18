INCLDIR	:= include
OBJDIR	:= obj
SRCDIR	:= src
BINDIR	:= bin

CC      := g++
VPATH	:=/usr/local/include
LDFLAGS := 
LIBRARY := gsl
CFLAGS  := -g -Wall -I $(INCLDIR) -std=c++11 -lgsl -lm -lgslcblas

#Source and object files (automatic)
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(subst $(SRCDIR)/,$(OBJDIR)/, $(subst .cpp,.o, $(SRCS)))

# Define here your main source files separated by spaces (without suffix!)
EXEC =  question1 question2 question3 question4 question5 question7 question6


#Phony = do not represent a file
#.PHONY: all
all : makedir $(EXEC)

# For multiple binaries
$(EXEC) : %: %.cpp $(OBJS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^ 

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 

#Clean: delete every binaries and object files
.PHONY: clean
clean :
	rm -rf $(OBJDIR)/*
	rm -rf $(BINDIR)/*
#Building folders (-p : no error if folder do not exist)
.PHONY: makedir
makedir :
	mkdir -p $(BINDIR)
	mkdir -p $(OBJDIR)

#For some debug
.PHONY: print
print :
	echo $(SRCS)
	echo $(OBJS)

#Remarks:
# $@ : filename representing the target
# $< : filename of the first prerequisite
# $^ : filenames of all prerequisites, separated by spaces. Dupplicated are removed.
# $? : names of all prerequisites that are newer than the target, separated by spaces
# $+ : similar to $^ but include dupplicates
# $* : stem of target file (filename without suffix)