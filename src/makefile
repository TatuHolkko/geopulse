# Set project directory one level above of Makefile directory. $(CURDIR) is a GNU make variable containing the path to the current working directory
PROJDIR := $(realpath $(CURDIR)/..)
SOURCEDIR := $(PROJDIR)/src
BUILDDIR := $(PROJDIR)/build

# Name of the final executable
TARGET = geopulse

# Decide whether the commands will be shwon or not
VERBOSE = FALSE

# Create the list of directories
DIRS = scene dynamic color shape utility filehandler test performance
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(SOURCEDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir)))

# Generate the GCC includes parameters by adding -I before each source folder
INCLUDES = $(foreach dir, $(SOURCEDIRS), $(addprefix -I, $(dir)))

INCLUDES += -I/usr/include/GL

# Add this list to VPATH, the place make will look for the source files
VPATH = $(SOURCEDIRS)

# Create a list of *.cpp sources in DIRS
SOURCES = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.cpp))
SOURCES += $(wildcard *.cpp)

# Define objects for all sources
OBJS := $(subst $(SOURCEDIR),$(BUILDDIR),$(SOURCES:.cpp=.o))

# Define dependencies files for all objects
DEPS = $(OBJS:.o=.d)

# Compile flags
CXXFLAGS += -Wall -g

# Libraries
LDFLAGS  += -L/usr/lib/x86_64-linux-gnu
LDFLAGS  += -L/usr/lib/libGL
LDFLAGS  += -L/usr/local/lib

LDLIBS   += -lGL -lGLU -lglut

# OS specific part
ifeq ($(OS),Windows_NT)
	RM = del /F /Q 
	RMDIR = -RMDIR /S /Q
	MKDIR = -mkdir
	ERRIGNORE = 2>NUL || true
	SEP=\\
else
	RM = rm -rf 
	RMDIR = rm -rf 
	MKDIR = mkdir -p
	ERRIGNORE = 2>/dev/null
	SEP=/
endif

# Remove space after separator
PSEP = $(strip $(SEP))

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
	HIDE =  
else
	HIDE = @
endif

# Define the function that will generate each rule
define generateRules
$(1)/%.o: %.cpp
	@echo Building $$@
	$(HIDE)$$(CXX) $$(CXXFLAGS) -c $$(INCLUDES) -o $$(subst /,$$(PSEP),$$@) $$(subst /,$$(PSEP),$$<) -MMD
endef

main.o: main.cpp
	@echo Building $@
	$(HIDE)$(CXX) $(CXXFLAGS) -c $(INCLUDES) -o $(subst /,$(PSEP),$@) $(subst /,$(PSEP),$<) -MMD

.PHONY: all clean directories 

all: directories $(TARGET)

$(TARGET): $(OBJS)
	$(HIDE)echo Linking $@
	$(HIDE)$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

# Include dependencies
-include $(DEPS)

# Generate rules
$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories: 
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)

# Remove all objects, dependencies and executable files generated during the build
clean:
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	$(HIDE)$(RM) main.o $(ERRIGNORE)
	$(HIDE)$(RM) main.d $(ERRIGNORE)
	@echo Cleaning done ! 