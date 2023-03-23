CFLAGS = -std=c++17 -O2

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I./headers -I.

VulkanTest: A01.cpp
	g++ $(CFLAGS) -o ex01 A01.cpp  $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./ex01

clean:
	rm -f ex01
