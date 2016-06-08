SRCS := $(shell find . -name '*.cpp') $(shell find ../common -name '*.cpp')
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
CXXFLAGS := -std=c++11 -Wall -pipe $(shell pkg-config --cflags box2d)
LDFLAGS := -lglog $(shell pkg-config --libs box2d) -pthread

.PHONY: all clean
all: server

server: $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)

.o.c:
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) server deps

print:
	@echo $(SRCS)

deps: $(SRCS)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -MM $(SRCS) > deps

-include deps
