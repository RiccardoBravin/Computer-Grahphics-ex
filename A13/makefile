CFLAGS = -std=c++17 -O2

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I./headers -I.

FILENAME = A13.cpp
OUTNAME = ex13

VulkanTest: $(FILENAME)
	glslc shaders/BlinnShader.frag -o shaders/BlinnFrag.spv
	g++ $(CFLAGS) -o $(OUTNAME) $(FILENAME)  $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./$(OUTNAME)

clean:
	rm -f $(OUTNAME)
