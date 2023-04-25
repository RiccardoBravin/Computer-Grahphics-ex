CFLAGS = -std=c++17 -O2

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I./headers -I.

FILENAME = A10.cpp
OUTNAME = ex10

VulkanTest: $(FILENAME)
	glslc shaders/PhongShader.frag -o shaders/PhongFrag.spv
	glslc shaders/PhongShader.vert -o shaders/PhongVert.spv
	g++ $(CFLAGS) -o $(OUTNAME) $(FILENAME)  $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./$(OUTNAME)

clean:
	rm -f $(OUTNAME)
