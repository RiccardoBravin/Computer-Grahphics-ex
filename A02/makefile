CFLAGS = -std=c++17 -O2

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I./headers -I.

VulkanTest: A02.cpp
	g++ $(CFLAGS) -o ex02 A02.cpp  $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./ex02

clean:
	rm -f ex02
