

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>

void SetupProjectionMatrices(Assignment04 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

	glm::mat4 S;
	//can be either done in one of these two ways
	//glm::mat4 P = glm::scale(glm::mat4(1), glm::vec3(1.0/10, -Ar/10, -1.0/100)) * glm::translate(glm::mat4(1), glm::vec3(0, 0, -1.0/100));
	glm::mat4 P = glm::scale(glm::mat4(1), glm::vec3(1, -1, 1))*
				  glm::ortho(-10.f, 10.f, -10/Ar, 10/Ar, -50.f, 50.f);

	// Isometric projection
	S = P * 
		glm::rotate(glm::mat4(1), glm::radians(35.26f) ,glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1), glm::radians(-45.f) ,glm::vec3(0, 1, 0));
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Dimetric
	S = P * 
		glm::rotate(glm::mat4(1), glm::radians(20.f) ,glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1), glm::radians(-45.f) ,glm::vec3(0, 1, 0));
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Trimetric
	S = P * 
		glm::rotate(glm::mat4(1), glm::radians(20.f) ,glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1), glm::radians(-30.f) ,glm::vec3(0, 1, 0));
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Cabinet
	float alpha = 45;
	float rho = 0.5;
	S = P *
		shearZ3D(glm::mat4(1), -rho*cos(alpha), -rho*sin(alpha));
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
