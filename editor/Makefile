SRCS := $(shell find . -name '*.cpp') $(shell find ../common -name '*.cpp')
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
CXXFLAGS := -std=c++11 -Wall -pipe $(shell pkg-config --cflags gtkmm-3.0)
LDFLAGS := $(shell pkg-config --libs gtkmm-3.0) -pthread

.PHONY: all clean
all: editor

editor: $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

.o.c:
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) editor deps

print:
	@echo $(SRCS)

deps: $(SRCS)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -MM $(SRCS) > deps

-include deps
