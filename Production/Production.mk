##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Production
ConfigurationName      :=Release
WorkspacePath          :=/home/jacek/CLP/Ecosystem
ProjectPath            :=/home/jacek/CLP/Ecosystem/Production
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jacek
Date                   :=10/03/20
CodeLitePath           :=/home/jacek/.codelite
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Production.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -O2 -std=c++14 -Wall $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/main_module.cpp$(ObjectSuffix) $(IntermediateDirectory)/organism.cpp$(ObjectSuffix) $(IntermediateDirectory)/bacteria.cpp$(ObjectSuffix) $(IntermediateDirectory)/mushroom.cpp$(ObjectSuffix) $(IntermediateDirectory)/alga.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Ecosystem/Production/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/main_module.cpp$(ObjectSuffix): main_module.cpp $(IntermediateDirectory)/main_module.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Ecosystem/Production/main_module.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main_module.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main_module.cpp$(DependSuffix): main_module.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main_module.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main_module.cpp$(DependSuffix) -MM main_module.cpp

$(IntermediateDirectory)/main_module.cpp$(PreprocessSuffix): main_module.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main_module.cpp$(PreprocessSuffix) main_module.cpp

$(IntermediateDirectory)/organism.cpp$(ObjectSuffix): organism.cpp $(IntermediateDirectory)/organism.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Ecosystem/Production/organism.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/organism.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/organism.cpp$(DependSuffix): organism.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/organism.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/organism.cpp$(DependSuffix) -MM organism.cpp

$(IntermediateDirectory)/organism.cpp$(PreprocessSuffix): organism.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/organism.cpp$(PreprocessSuffix) organism.cpp

$(IntermediateDirectory)/bacteria.cpp$(ObjectSuffix): bacteria.cpp $(IntermediateDirectory)/bacteria.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Ecosystem/Production/bacteria.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bacteria.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bacteria.cpp$(DependSuffix): bacteria.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bacteria.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bacteria.cpp$(DependSuffix) -MM bacteria.cpp

$(IntermediateDirectory)/bacteria.cpp$(PreprocessSuffix): bacteria.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bacteria.cpp$(PreprocessSuffix) bacteria.cpp

$(IntermediateDirectory)/mushroom.cpp$(ObjectSuffix): mushroom.cpp $(IntermediateDirectory)/mushroom.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Ecosystem/Production/mushroom.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mushroom.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mushroom.cpp$(DependSuffix): mushroom.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mushroom.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mushroom.cpp$(DependSuffix) -MM mushroom.cpp

$(IntermediateDirectory)/mushroom.cpp$(PreprocessSuffix): mushroom.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mushroom.cpp$(PreprocessSuffix) mushroom.cpp

$(IntermediateDirectory)/alga.cpp$(ObjectSuffix): alga.cpp $(IntermediateDirectory)/alga.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Ecosystem/Production/alga.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/alga.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/alga.cpp$(DependSuffix): alga.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/alga.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/alga.cpp$(DependSuffix) -MM alga.cpp

$(IntermediateDirectory)/alga.cpp$(PreprocessSuffix): alga.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/alga.cpp$(PreprocessSuffix) alga.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


