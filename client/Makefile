SRCS := $(shell find . -name '*.cpp') $(shell find ../common -name '*.cpp')
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
CXXFLAGS := -std=c++11 -Wall -pipe $(shell pkg-config --cflags gtkmm-3.0 sdl2pp)
LDFLAGS := $(shell pkg-config --libs gtkmm-3.0 sdl2pp) -pthread -lX11

.PHONY: all clean
all: client

client: $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS) 

.o.c:
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) client deps

print:
	@echo $(SRCS)

deps: $(SRCS)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -MM $(SRCS) > deps

-include deps

