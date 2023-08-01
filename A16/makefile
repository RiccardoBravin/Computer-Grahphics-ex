CFLAGS = -std=c++17 -O2

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I./headers -I.

FILENAME = A16.cpp
OUTNAME = ex16

VulkanTest: $(FILENAME)
	glslc shaders/Mesh.frag -o shaders/MeshFrag.spv
	glslc shaders/Mesh.vert -o shaders/MeshVert.spv
	glslc shaders/Overlay.frag -o shaders/OverlayFrag.spv
	glslc shaders/Overlay.vert -o shaders/OverlayVert.spv
	glslc shaders/VColor.frag -o shaders/VColorFrag.spv
	glslc shaders/VColor.vert -o shaders/VColorVert.spv
	g++ $(CFLAGS) -o $(OUTNAME) $(FILENAME)  $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./$(OUTNAME)

clean:
	rm -f $(OUTNAME)
