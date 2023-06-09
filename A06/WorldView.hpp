//README:
//I changed the default commands to make them simpler to use on the keyboard. This way the movement 
//model is more like a walking flight model being able to go up and down with SPACE and CTRL and
//changing controlled object with "c"  

glm::mat4 MakeViewProjectionMatrix(float Ar, float Alpha, float Beta, float Rho, glm::vec3 Pos) {
	// Creates a view projection matrix, with near plane at 0.1, and far plane at 50.0, and
	// aspect ratio given in <Ar>. The view matrix, uses the Look-in-Direction model, with
	// vector <pos> specifying the position of the camera, and angles <Alpha>, <Beta> and <Rho>
	// defining its direction. In particular, <Alpha> defines the direction (Yaw), <Beta> the
	// elevation (Pitch), and <Rho> the roll.

	glm::mat4 P = glm::perspective(glm::radians(45.0f), Ar, 0.1f, 50.0f);
	P[1][1] *= -1;

	glm::mat4 MV = glm::rotate(glm::mat4(1), -Rho, glm::vec3(0,0,1)) *
				   glm::rotate(glm::mat4(1), -Beta, glm::vec3(1,0,0)) *
				   glm::rotate(glm::mat4(1), -Alpha, glm::vec3(0,1,0)) *
				   glm::translate(glm::mat4(1),  -Pos);
	


	return P * MV;
}

glm::mat4 MakeWorldMatrix(glm::vec3 pos, glm::quat rQ, glm::vec3 size) {
	// creates and returns a World Matrix that positions the object at <pos>,
	// orients it according to <rQ>, and scales it according to the sizes
	// given in vector <size>

	glm::mat T = glm::translate(glm::mat4(1), pos);
	glm::mat R = glm::mat4(rQ);
	glm::mat S = glm::scale(glm::mat4(1), size);
	glm::mat4 M = T*R*S;

	return M;
}
