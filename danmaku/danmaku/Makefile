ProjectName			:=DanMaku
Files				:=$(basename $(notdir $(wildcard src/*.cpp)))
Compiler			:=g++

IncludePath			:=-I
LibPath				:=-L

Libs				:=-lsfml-graphics -lsfml-window -lsfml-system
CompFlags			:=-w -Wall -fpermissive -std=c++0x

SourcesDir			:=src/
ObjectsDir			:=obj/
SourcesSuffix			:=.cpp
ObjectSuffix			:=.o
MDir				:=mkdir -p

Sources				:=$(addprefix $(SourcesDir), $(addsuffix $(SourcesSuffix), $(Files)))
Objects				:=$(addprefix $(ObjectsDir), $(addsuffix $(ObjectSuffix),  $(Files)))
OutputFile			:=$(ProjectName)

##
## Main Build Targets
##
$(OutputFile): $(Objects)
	$(Compiler) $(CompFlags) -o $(OutputFile) $(Objects) $(IncludePath) $(LibPath) $(Libs)

##
## Objects
##
$(ObjectsDir)%$(ObjectSuffix): $(SourcesDir)%$(SourcesSuffix)
	@$(MDir) $(ObjectsDir)
	$(Compiler) $(CompFlags) -c $< -o $@

##
## Clean
##
clean:
	-rm -r -f $(ObjectsDir)
	-rm -f $(ProjectName)
