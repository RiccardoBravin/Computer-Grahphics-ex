#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragUV;

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
	vec3 Norm = fragNorm;
	
	float y = fragPos.y;
	float t = gubo.time;
	float r = 0.0f, g = 0.0f, b = 0.0f;

	/***** Insert the code here to compute the correct value of r, g and b ****/
	 //value - Trunc(value/modulus)*modulus;

	float a = (t/3+y);

	float H = a - int(a/6)*6;

	uint c1 = uint(H < 1);
	uint c2 = uint(H >= 1 && H < 2);
	uint c3 = uint(H >= 2 && H < 3);
	uint c4 = uint(H >= 3 && H < 4);
	uint c5 = uint(H >= 4 && H < 5);
	uint c6 = uint(H >= 5);


	r = 1 * c1 + (2-H) * c2 + 0 * c3 + 0 * c4 + (H-4) * c5 + 1 * c6;
	g = H * c1 + 1 * c2 + 1 * c3 + (4-H) * c4 + 0 * c5 + 0 * c6;
	b = 0 * c1 + 0 * c2 + (H-2) * c3 + 1 * c4 + 1 * c5 + (6-H) * c6;


	/***** Leave it as is from this point on ****/
	
	outColor = vec4(r, g, b, 1.0);
}