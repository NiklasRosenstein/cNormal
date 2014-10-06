
ifeq ($(OS),Windows_NT)
    ExeSuffix = .exe
    ifndef USE_COMPILER
    	USE_COMPILER = MSVC
    endif
else
    ExeSuffix =
endif

ifndef USE_COMPILER
	USE_COMPILER = Clang
endif

ifeq ($(USE_COMPILER),MSVC)
	Compiler = cl /nologo /c /EHsc
	CompilerOut = /Fo"$1"
    OptimizeMax = /Ox
    Debug = /Od /Zi
	Linker = link /nologo
	LinkerOut = /OUT:"$1"
	ObjSuffix = .obj
else ifeq ($(USE_COMPILER),Clang)
	Compiler = clang++ -c
	CompilerOut = -o "$1"
    OptimizeMax = -Ox
    Debug = -O0 -g
	Linker = clang++
	LinkerOut = -o "$1"
	ObjSuffix = .o
else
	$(error Unknown compiler $(USE_COMPILER))
endif
