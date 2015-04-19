CXXFLAGS =	-std=c++0x -O2 -g -Wall -fmessage-length=0

OBJS =		atom.o molekel_help.o

LIBS =

TARGET =	molekel_help.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
