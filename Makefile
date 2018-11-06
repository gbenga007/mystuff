# References
# [1] http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/
# [2] https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html

# Dependencies
DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

# C++ compile
CXXFLAGS := -std=c++11 -O0 -ggdb -Wall
COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

# Post-compile
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

CXXSOURCES := $(wildcard *.cpp)
CXXHEADERS := $(wildcard *.h)
CXXOBJS := $(CXXSOURCES:.cpp=.o)

PROGRAM := lab09


.phony : all
all : $(PROGRAM)

$(PROGRAM) : $(CXXOBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)


# Cancel make's implicit rule for .cpp -> .o, and replace
# it with the one below.
%.o : %.cpp

# See reference [2] for $(OUTPUT_OPTION) == `-o $@'
%.o : %.cpp $(DEPDIR)/%.d
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

# Include the automatically-generated dependency rules from $(DEPDIR)
include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS))))

.phony : clean
clean :
	rm -f $(CXXOBJS) $(PROGRAM)
	rm -fr $(DEPDIR)

