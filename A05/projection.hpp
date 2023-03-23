#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>


void SetupProjectionMatrices(Assignment05 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

	glm::mat4 S;
	

	float FovY = glm::radians(60.0f);
	S = glm::perspective(FovY, Ar, 0.1f, 50.0f);
	S[1][1] *= -1;
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	
	FovY = glm::radians(105.0f);
	S = glm::perspective(FovY, Ar, 0.1f, 50.0f);
	S[1][1] *= -1;
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	FovY = glm::radians(25.0f);
	S = glm::perspective(FovY, Ar, 0.1f, 50.0f);
	S[1][1] *= -1;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Right View, Fov-x = 45 deg
	float t = 0.1*tan(glm::radians(45.0f)/2);
	float r = Ar*t; 

	S = glm::scale(glm::mat4(1), glm::vec3(1,-1,1))*
		glm::frustum(0.0f,2*r,-t,t,0.1f,50.0f);
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
