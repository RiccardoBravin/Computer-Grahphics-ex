CFLAGS = -std=c++17 -O2

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I./headers -I.

FILENAME = A12.cpp
OUTNAME = ex12

VulkanTest: $(FILENAME)
	glslc shaders/PhongShader.frag -o shaders/PhongFrag.spv
	glslc shaders/OrenNayarShader.frag -o shaders/OrenNayarFrag.spv
	glslc shaders/BlinnNormMapShader.frag -o shaders/BlinnNormMapFrag.spv
	glslc shaders/GGXNormMapShader.frag -o shaders/GGXNormMapFrag.spv
	g++ $(CFLAGS) -o $(OUTNAME) $(FILENAME)  $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./$(OUTNAME)

clean:
	rm -f $(OUTNAME)
