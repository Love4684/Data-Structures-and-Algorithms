
PLATFORM	= $(shell uname)
CXX			= g++
CXXFLAGS	= -Wall -ansi -pedantic

SOURCES:= $(wildcard *.cc)
TARGETS := $(SOURCES:.cc=)

all: $(TARGETS)


define template
$(1): $(1).cc
	@echo "Building $$@... "
	@$(CXX) $(1).cc $(CXXFLAGS) -o $$@
endef
$(foreach target,$(TARGETS),$(eval $(call template,$(target))))

clean:
	@-rm -f $(TARGETS)

distclean: clean
	@-rm -f *~
