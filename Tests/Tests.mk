##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Tests
ConfigurationName      :=Release
WorkspacePath          :=/home/jacek/CLP/Ecosystem
ProjectPath            :=/home/jacek/CLP/Ecosystem/Tests
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jacek Wójcik
Date                   :=09/03/20
CodeLitePath           :=/home/jacek/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="Tests.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./../Production 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O2 -Wall $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/organism_test.cpp$(ObjectSuffix) $(IntermediateDirectory)/catch_main.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/organism_test.cpp$(ObjectSuffix): organism_test.cpp $(IntermediateDirectory)/organism_test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Ecosystem/Tests/organism_test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/organism_test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/organism_test.cpp$(DependSuffix): organism_test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/organism_test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/organism_test.cpp$(DependSuffix) -MM organism_test.cpp

$(IntermediateDirectory)/organism_test.cpp$(PreprocessSuffix): organism_test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/organism_test.cpp$(PreprocessSuffix) organism_test.cpp

$(IntermediateDirectory)/catch_main.cpp$(ObjectSuffix): catch_main.cpp $(IntermediateDirectory)/catch_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/Ecosystem/Tests/catch_main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/catch_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/catch_main.cpp$(DependSuffix): catch_main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/catch_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/catch_main.cpp$(DependSuffix) -MM catch_main.cpp

$(IntermediateDirectory)/catch_main.cpp$(PreprocessSuffix): catch_main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/catch_main.cpp$(PreprocessSuffix) catch_main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


