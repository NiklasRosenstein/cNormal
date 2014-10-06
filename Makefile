
include Platform.mak

BuildDir = build
Sources = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp)
Objects = $(addprefix $(BuildDir)/,$(Sources:.cpp=$(ObjSuffix)))
Dirs = $(sort $(dir $(Objects)))
Target = $(BuildDir)/cNormal$(ExeSuffix)

all: $(Target)

$(Dirs):
	mkdir -p $(Dirs)

$(Target): $(Dirs) $(Objects)
	$(Linker) $(Objects) $(call LinkerOut,$@)

$(BuildDir)/%$(ObjSuffix): %.cpp
	$(Compiler) $(Debug) $< $(call CompilerOut,$@)
