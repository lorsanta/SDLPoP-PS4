# Project: SDLPoP

CC = clang
RM = rm -f

HFILES = common.h config.h data.h proto.h types.h ps4_debug.h
OBJ = main.o ps4_debug.o data.o seg000.o seg001.o seg002.o seg003.o seg004.o seg005.o seg006.o seg007.o seg008.o seg009.o seqtbl.o replay.o options.o lighting.o screenshot.o menu.o midi.o opl3.o stb_vorbis.o
BIN = ../prince

OS      := $(shell uname)

CPPFLAGS += -Wall -D_GNU_SOURCE=1 -DHOSTDEBUG=1
CFLAGS += -std=gnu99 -g -I/usr/include/SDL2

LIBS := $(shell pkg-config --libs sdl2 SDL2_image)
CFLAGS += $(shell pkg-config --cflags sdl2 SDL2_image)

ifeq ($(OS),Darwin)
CPPFLAGS += -D_THREAD_SAFE -DOSX
endif

all: $(BIN)

clean:
	$(RM) $(OBJ) $(BIN)

install:
	./install.sh

uninstall:
	./uninstall.sh

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LIBS) -lm

%.o: %.c $(HFILES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -c $<

%.o: %.cpp $(HFILES)
	clang++ $(CPPFLAGS) $(LDFLAGS) -I/usr/include/SDL2 -c $<

.PHONY: all clean

