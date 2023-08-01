
void Assignment14::createCubeMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
/*	vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.5f, 0.0f, 0.866f}});	// vertex 0 - Position and Normal
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{1.0f, 1.0f, 0.1f}, {-0.5f, 0.0f, 0.866f}});// vertex 3 - Position and Normal

	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
	
	// The primitive built here is a cube centered in the origin, whose edge lenght is 2.
*/	

	int count = 0; 

	for(int i = -1; i < 2; i += 2){
		vDef.push_back({{1.0f, i, 1.0f}, {0.0f, i, 0.0f}});	// vertex 0 - Position and Normal
		vDef.push_back({{1.0f, i, -1.0f}, {0.0f, i, 0.0f}});	// vertex 1 - Position and Normal
		vDef.push_back({{-1.0f, i, 1.0f}, {0.0f, i, 0.0f}});	// vertex 3 - Position and Normal
		vDef.push_back({{-1.0f, i, -1.0f}, {0.0f, i, 0.0f}});	// vertex 2 - Position and Normal

		vIdx.push_back(count + 0); vIdx.push_back(count + 1); vIdx.push_back(count + 2);	// First triangle
		vIdx.push_back(count + 1); vIdx.push_back(count + 2); vIdx.push_back(count + 3);	// Second triangle
		count += 4;
	}
	
	for(int i = -1; i < 2; i += 2){
		vDef.push_back({{i, 1.0f, 1.0f}, {i, 0.0f, 0.0f}});	// vertex 0 - Position and Normal
		vDef.push_back({{i, 1.0f, -1.0f}, {i, 0.0f, 0.0f}});	// vertex 1 - Position and Normal
		vDef.push_back({{i, -1.0f, 1.0f}, {i, 0.0f, 0.0f}});	// vertex 3 - Position and Normal
		vDef.push_back({{i, -1.0f, -1.0f}, {i, 0.0f, 0.0f}});	// vertex 2 - Position and Normal

		vIdx.push_back(count + 0); vIdx.push_back(count + 1); vIdx.push_back(count + 2);	// First triangle
		vIdx.push_back(count + 1); vIdx.push_back(count + 2); vIdx.push_back(count + 3);	// Second triangle
		count += 4;
	}

	for(int i = -1; i < 2; i += 2){
		vDef.push_back({{1.0f, 1.0f, i}, {0.0f, 0.0f, i}});	// vertex 0 - Position and Normal
		vDef.push_back({{1.0f, -1.0f, i}, {0.0f, 0.0f, i}});	// vertex 1 - Position and Normal
		vDef.push_back({{-1.0f, 1.0f, i}, {0.0f, 0.0f, i}});	// vertex 3 - Position and Normal
		vDef.push_back({{-1.0f, -1.0f, i}, {0.0f, 0.0f, i}});	// vertex 2 - Position and Normal

		vIdx.push_back(count + 0); vIdx.push_back(count + 1); vIdx.push_back(count + 2);	// First triangle
		vIdx.push_back(count + 1); vIdx.push_back(count + 2); vIdx.push_back(count + 3);	// Second triangle
		count += 4;
	}

}



void Assignment14::createFunctionMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is the surface y = sin(x) * cos(z) with -3 <= x <= 3 and -3 <= z <= 3.
	
	// Fill array vPos with the positions of the vertices of the mesh
	/*vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.5f, 0.0f, 0.866f}});	// vertex 0 - Position and Normal
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 2 - Position and Normal
	*/

	const float RES = 1.0f/8; //meter per vertex (distance between vertices)

	for(float x = -3; x <= 3; x += RES){
		for(float z = -3; z <= 3; z += RES){
			//calculate correct normal vector to the surface
			//std::cout << "x: " << x << " z: " << z << std::endl;
			vDef.push_back({{x, sin(x) * cos(z), -z}, {cos(x)*cos(z), 1.0f, -sin(x)*sin(z)}});	// vertex 0 - Position and Normal
		}
	}


	for (int j = 0; j < 6.0f*6.0f/(RES*RES); j += (6.0f/RES + 1)){
		for(int i = 0; i < 6.0f/RES; i++){
			//std::cout << "Joining vertex: (" << i + j << ", " << i + 1 + j << ", " << i + 6.0f/RES + 1 + j << ")" << std::endl;
			vIdx.push_back(i + j); vIdx.push_back(i + 1 + j); vIdx.push_back(i + 6.0f/RES + 1 + j);	// First triangle
			//std::cout << "Joining vertex: (" << i + 1 + j << ", " << i + 6.0f/RES + 1 + j << ", " << i + 6.0f/RES + 2 + j << ")" << std::endl;
			vIdx.push_back(i + 1 + j); vIdx.push_back(i + 6.0f/RES + 1 + j); vIdx.push_back(i + 6.0f/RES + 2 + j);	// Second triangle	
		}	
		std::cout << std::endl;
	}
	
}


void Assignment14::createCylinderMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is a cylinder, with radius 1, and height 2, centered in the origin.

	const float RES = 40; //number of outer points per circle


	//CREATING UPPER CIRCLE
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}}); //Center (0)

	//outer points
	for(float i = 0; i < 360; i += 360.0f/RES){
		vDef.push_back({{cos(glm::radians(i)), 1.0f, sin(glm::radians(i))}, {0.0f, 1.0f, 0.0f}});
	}
	//building triengles
	for(int i = 1; i < RES; i++){
		vIdx.push_back(0); vIdx.push_back(i); vIdx.push_back(i + 1);	
	}
	vIdx.push_back(0); vIdx.push_back(RES); vIdx.push_back(1);	// Last triangle

	

	//CREATING LOWER CIRCLE
	vDef.push_back({{0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f}}); //Center (RES+1)

	//Outer points
	for(float i = 0; i < 360; i += 360.0f/RES){
		vDef.push_back({{cos(glm::radians(i)), -1.0f, sin(glm::radians(i))}, {0.0f, -1.0f, 0.0f}});
	}

	//Building triangles
	for(int i = RES+2; i < RES*2+1; i++){
		vIdx.push_back(RES+1); vIdx.push_back(i); vIdx.push_back(i+1);	
	}
	vIdx.push_back(RES+1); vIdx.push_back(RES*2+1); vIdx.push_back(RES+2);	// Last triangle
	

	//CREATING SIDE
	int cnt = vDef.size(); //Index of the first vertex of the side

	//Outer points
	for(float i = 0; i < 360; i += 360.0f/RES){
		vDef.push_back({{cos(glm::radians(i)), 1.0f, sin(glm::radians(i))}, {cos(glm::radians(i)), 0.0f, sin(glm::radians(i))}}); //Upper point
		vDef.push_back({{cos(glm::radians(i)), -1.0f, sin(glm::radians(i))}, {cos(glm::radians(i)), 0.0f, sin(glm::radians(i))}}); //Lower point
	}

	//Building triangles
	for(int i = cnt; i < cnt + RES*2 - 2; i+=2){
		vIdx.push_back(i); vIdx.push_back(i+1); vIdx.push_back(i+2);	
		vIdx.push_back(i+1); vIdx.push_back(i+2); vIdx.push_back(i+3);	
	}

	vIdx.push_back(cnt); vIdx.push_back(cnt+1); vIdx.push_back(vDef.size()-2);
	vIdx.push_back(cnt+1); vIdx.push_back(vDef.size()-1); vIdx.push_back(vDef.size()-2);



}
