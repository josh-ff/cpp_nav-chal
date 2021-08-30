VERSION=0x03
DATE=$(shell date '+%Y%m%d' )

TARGET=nav-challenge
LINK_TARGET = $@_$(DATE)_$(VERSION)
SRC_FILES = $(wildcard src/*.cpp)
INCLUDE = -Iinc


STANDARD_BUILD_OPTIONS= $(INCLUDE) -Wall -Werror -std=c++14 -O2 -o #
CC=g++
.PHONY : all
all : $(TARGET)

#%.dep : %.cpp
#	$(CC) -M $(FLAGS) $< > $@
#	include $(OBJDIR)/$(OBJS:.o=.dep)
#	@echo $@

#REBUILDABLES = $(OBJ_FILES) $(TARGET)

#$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
#	@echo $@
#	$(CC) -g -pthread  -std=c++14 -O2 -o $@ -c $<

$(TARGET): $(SRC_FILES)	
	@echo Jambox
	$(CC) $(STANDARD_BUILD_OPTIONS) $@ $^
	@echo
	@echo Build done, Make version $(VERSION)
	@echo $(shell date)

#-static
.PHONY : clean all
clean :
	rm -f $(REBUILDABLES) $(TARGET)
	@echo All done

