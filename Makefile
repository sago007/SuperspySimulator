CC=$(CROSS)gcc
CXX=$(CROSS)g++
LD=$(CROSS)ld
AR=$(CROSS)ar
PKG_CONFIG=$(CROSS)pkg-config


BASE_LIBS=$(shell $(CROSS)sdl2-config --libs) -lSDL2_ttf $(shell $(CROSS)pkg-config SDL2_image SDL2_mixer --libs) $(SAGO_BASE_LIBS)
BASE_CFLAGS=-c -g -O0 -Wall -std=c++17 $(shell $(CROSS)sdl2-config --cflags)

PROGRAMNAME=SuperspySimulator

O_FILES=./Platformer/Helpers.o \
./Platformer/SettingsMenu.o \
./Platformer/Spritesheet.o \
./Platformer/CollisionMap.o \
./Platformer/CharacterSelect.o \
./Platformer/Bonus.o \
./Platformer/Level.o \
./Platformer/SaveData.o \
./Platformer/Items.o \
./Platformer/Event.o \
./Platformer/Enemy.o \
./Platformer/Bestiary.o \
./Platformer/Settings.o \
./Platformer/main.o \
./Platformer/LevelSelect.o \
./Platformer/InputMapper.o \
./Platformer/AABB.o \
./Platformer/Customizer.o \
./Platformer/ResultsScreen.o \
./Platformer/StatsMenu.o \
./Platformer/Platformer.o \
./Platformer/ScriptedAction.o \
./Platformer/MainMenu.o \
./Platformer/UI.o \
./Platformer/Engine.o \
./Platformer/GameState.o \
./Platformer/Weapon.o \
./Platformer/Attack.o \
./Platformer/Vector2.o \
./Platformer/Player.o \
./Platformer/Spawner.o \
./Platformer/GameObject.o \
./Platformer/MovingPlatform.o


total: ${PROGRAMNAME}

clean:
	rm -f */*.o *.o *.P */*.P ${PROGRAMNAME}

${PROGRAMNAME}: $(O_FILES)
	$(CXX) -O -o ${PROGRAMNAME} $(O_FILES) $(BASE_LIBS)

%.o : %.cpp
	$(CXX) -MD ${BASE_CFLAGS} -o $@ $<
	@mkdir -p `dirname .$(CROSS)deps/$*.P` && cp $*.d .$(CROSS)deps/$*.P; \
             sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
                 -e '/^$$/ d' -e 's/$$/ :/' < $*.d >> .$(CROSS)deps/$*.P; \
             rm -f $*.d

-include */.$(CROSS)deps/*.P

SOURCE_FILES = $(O_FILES:.o=.cpp)

format:
	astyle -t -j -y -c -k1 -z2 -A2 --pad-header $(SOURCE_FILES)
