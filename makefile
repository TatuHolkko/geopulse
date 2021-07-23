CPPFILES = $(wildcard *.cpp)
OBJFILES = $(CPPFILES:.cpp=.o)
OUT      = geopulse

INCLUDES += -I/usr/include/GL

CXXFLAGS += -Wall $(INCLUDES)

LDFLAGS  += -L/usr/lib/x86_64-linux-gnu
LDFLAGS  += -L/usr/lib/libGL
LDFLAGS  += -L/usr/local/lib

LDLIBS   += -lGL -lGLU -lglut

$(OUT): $(OBJFILES)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)


.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OUT)
