ProjectName		:=DanMaku
#Files			:=Application ConnectState GameState mainfile MenuState SplashState State StateManager TextureManager
Files			:$(wildcard $(SourcesDir)/*.cpp)
Compiler		:=g++

MKDIR_P = mkdir -p

#IncludePath						:=-I
#LibPath							:=-L

Libs						:=-lsfml-graphics -lsfml-window -lsfml-system
CompFlagsDebug				:=-g -fpermissive -std=c++0x
CompFlagsRelease			:=-fpermissive -std=c++0x
CompFlagsWarning			:=-w -Wall

SourcesDir						:=src/
ObjectsDir						:=${MKDIR_P} obj/
SourcesSuffix					:=.cpp
ObjectSuffix					:=.o
MakeDirCommand					:=mkdir -p

# Define variables according to configuration of compilation (debug or release)
ifeq ($(MAKECMDGOALS),debug)
CompFlags 						:=$(CompFlagsWarning) $(CompFlagsDebug)
IntermediateDirectory	:=./
else
CompFlags 						:=$(CompFlagsWarning) $(CompFlagsRelease)
IntermediateDirectory	:=./
endif

Sources								:=$(addprefix $(SourcesDir), $(addsuffix $(SourcesSuffix), $(Files)))
Objects								:=$(addprefix $(ObjectsDir), $(addsuffix $(ObjectSuffix),  $(Files)))
OutputFile							:=$(IntermediateDirectory)/$(ProjectName)

##
## Main Build Targets
##
.PHONY: debug release clean

debug  :	$(OutputFile)
release:	$(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(IntermediateDirectory)
	$(Compiler) $(CompFlags) -o $(OutputFile) $(Objects) $(IncludePath) $(LibPath) $(Libs)

##
## Objects
##
$(ObjectsDir)%$(ObjectSuffix): $(SourcesDir)%$(SourcesSuffix)
	$(Compiler) $(CompFlags) -c $< $(IncludePath) -o $@

##
## Clean
##
clean:
	-rm -f $(ObjectsDir)*$(ObjectSuffix)
	-rm -f $(IntermediateDirectory)/$(ProjectName)
