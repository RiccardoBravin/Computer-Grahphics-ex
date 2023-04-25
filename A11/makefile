CFLAGS = -std=c++17 -O2

LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I./headers -I.

FILENAME = A11.cpp
OUTNAME = ex11

VulkanTest: $(FILENAME)
	glslc shaders/BlinnShader1.frag -o shaders/BlinnFrag1.spv
	glslc shaders/BlinnShader2.frag -o shaders/BlinnFrag2.spv
	glslc shaders/BlinnShader3.frag -o shaders/BlinnFrag3.spv
	g++ $(CFLAGS) -o $(OUTNAME) $(FILENAME)  $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	./$(OUTNAME)

clean:
	rm -f $(OUTNAME)
