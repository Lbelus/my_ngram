
# set default compiler
CC = gcc

# CFLAGS variable 
# -g
# -Wall give verbose compiler warnings
# -o0 do not optimize generated code
# -std=c99 use the c99 standard language defintion
# -Wextra enables extra warnings flag
# -Werror male all warning into error
CFLAGS = -Wall -Wextra -Werror

# LDFLAGS sets flags for linker
#-1m says to link in libm
#LDFLAGS = -1m

# list files that are parts of the project 
SOURCES = my_ngram.c

OBJECTS = $(SOURCES:.c)
TARGET = my_ngram

# first target defined in Makefile is the one
# used when makefile file is invoked with no argument. given the defintions.
#above, this Makefile will build the one named TARGET and 
# assume that it depend on all the named objects files. 

$(TARGET) :
	$(CC) $(SOURCES) -o $@ $^  

#phony means not a real target, it doesn't build anything
#the phony target clean is used to remove all compiled object files.

.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) core 

#OBJECTS = $(SOURCES:.c=.o)
#$(TARGET) : $(OBJECTS)
#	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

INTRO = "\n|B\n|y        ┌────────────────────────────────────────────────────────────9─────────────────────────────────────┐\n|         |abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst|\n|L        |1┌─────────────────────6───────────────────────────────5────────────────────────────────────────┐9|\n|U        |2|   b           r                l                                4                 7       u  |8|\n|L        |3|    2       ███╗   ███╗██╗   ██╗    ███╗   ██╗ ██████╗ ██████╗  █████╗ ███╗   ███╗   g        |7|\n|O        |4|            ████╗ ████║╚██╗ ██╔╝    ████╗  ██║██╔════╝ ██╔══██╗██╔══██╗████╗ ████║        n   |6|\n|         |5|       5    ██╔████╔██║ ╚████╔╝  4  ██╔██╗ ██║██║ 3███╗██████╔╝███████║██╔████╔██║            |5|\n|2        |6| x          ██║╚██╔╝██║  ╚██╔╝      ██║╚██╗██║██║   ██║██╔══██╗██╔══██║██║╚██╔╝██║      6     |4|\n|0        |7|         y  ██║ ╚═╝ ██║   ██║  h    ██║ ╚████║╚██████╔╝██║8 ██║██║  ██║██║ ╚═╝ ██║        i   |3|\n|2        |8|  t         ╚═╝  0  ╚═╝   ╚═╝       ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝ j   ╚═╝  z         |2|\n|2        |9└──────────────────────────────────────────────────────────────────────────p───────────────────┘1|\n|         |abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst|\n|         └─────────────────────────────────────────────1────────────────────────────────────────────────────┘\n|"
BODY = "\nAnalysis result: \n"
TAILS = "\nEnd of process...\n"
catngram : 
	@echo $(INTRO)
	@echo $(BODY)
	@./my_cat -a "test03.txt"
	@echo $(TAILS)
	