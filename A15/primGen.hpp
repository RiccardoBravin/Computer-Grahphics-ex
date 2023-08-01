
void Assignment15::createBoxMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The primitive built here is a box centered in the origin, with proportions respecting the texture.

    /*
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	vDef.push_back({{0,0,0}, {0,0,1}, {0,0}});	// vertex 0 - Position, Normal and uv
	vDef.push_back({{1,0,0}, {0,0,1}, {1,0}});	// vertex 1 - Position and Normal
	vDef.push_back({{0,1,0}, {0,0,1}, {0,1}});	// vertex 2 - Position and Normal
	vDef.push_back({{1,1,0}, {0,0,1}, {1,1}});// vertex 3 - Position and Normal

	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
    */

    //box real dimensions 58,2 x 48 x 17 cm
    //defining the height as 1 unit, the width is 0.8275862069 and the depth is 0.2931034483
    //texture is 1024 x 512

    //top scanning (96,0) to (443,91)
    //front scanning (96,95) to (443,417)
    //left side scanning (0,95) to (92,417) 
    //right side scanning (446,95) to (538,417)
    //back scanning (541,95) to (888,417)
    //bottom scanning (96,420) to (443,512)




    //bottom face
    vDef.push_back({{0, 0, 0},                      {0, -1, 0},     {443.0f/1024, 512.0f/512}});	// vertex 0 - Position, Normal and uv
    vDef.push_back({{0.8275862069, 0, 0},           {0, -1, 0},     {96.0f/1024, 512.0f/512}});	// vertex 1 - Position and Normal
    vDef.push_back({{0, 0, 0.2931034483},           {0, -1, 0},     {443.0f/1024, 420.0f/512}});	// vertex 2 - Position and Normal
    vDef.push_back({{0.8275862069, 0, 0.2931034483},{0, -1, 0},     {96.0f/1024, 420.0f/512}});// vertex 3 - Position and Normal

    //top face
    vDef.push_back({{0, 1, 0},                      {0, 1, 0},      {96.0f/1024, 0.0f/512}});	// vertex 4 - Position, Normal and uv
    vDef.push_back({{0.8275862069, 1, 0},           {0, 1, 0},      {443.0f/1024, 0.0f/512}});	// vertex 5 - Position and Normal
    vDef.push_back({{0, 1, 0.2931034483},           {0, 1, 0},      {96.0f/1024, 91.0f/512}});	// vertex 6 - Position and Normal
    vDef.push_back({{0.8275862069, 1, 0.2931034483},{0, 1, 0},      {443.0f/1024, 91.0f/512}});// vertex 7 - Position and Normal

    //front face
    vDef.push_back({{0, 0, 0.2931034483},           {1, 0, 0},      {96.0f/1024, 95.0f/512}});	// vertex 8 - Position, Normal and uv
    vDef.push_back({{0.8275862069, 0, 0.2931034483},{1, 0, 0},      {96.0f/1024, 417.0f/512}});	// vertex 9 - Position and Normal
    vDef.push_back({{0, 1, 0.2931034483},           {1, 0, 0},      {443.0f/1024, 95.0f/512}});	// vertex 10 - Position and Normal
    vDef.push_back({{0.8275862069, 1, 0.2931034483},{1, 0, 0},      {443.0f/1024, 417.0f/512}});// vertex 11 - Position and Normal
    
    //back face
    vDef.push_back({{0, 0, 0},                      {-1, 0, 0},     {541.0f/1024, 95.0f/512}});	// vertex 12 - Position, Normal and uv
    vDef.push_back({{0.8275862069, 0, 0},           {-1, 0, 0},     {541.0f/1024, 417.0f/512}});	// vertex 13 - Position and Normal
    vDef.push_back({{0, 1, 0},                      {-1, 0, 0},     {888.0f/1024, 95.0f/512}});	// vertex 14 - Position and Normal
    vDef.push_back({{0.8275862069, 1, 0},           {-1, 0, 0},     {888.0f/1024, 417.0f/512}});// vertex 15 - Position and Normal

    //left face
    vDef.push_back({{0, 0, 0},                      {0, 0, -1},     {92.0f/1024, 95.0f/512}});	// vertex 16 - Position, Normal and uv
    vDef.push_back({{0, 0, 0.2931034483},           {0, 0, -1},     {0.0f/1024, 95.0f/512}});	// vertex 17 - Position and Normal
    vDef.push_back({{0, 1, 0},                      {0, 0, -1},     {92.0f/1024, 417.0f/512}});	// vertex 18 - Position and Normal
    vDef.push_back({{0, 1, 0.2931034483},           {0, 0, -1},     {0.0f/1024, 417.0f/512}});// vertex 19 - Position and Normal

    //right face
    vDef.push_back({{0.8275862069, 0, 0},           {0, 0, 1},     {446.0f/1024, 95.0f/512}});	// vertex 20 - Position, Normal and uv
    vDef.push_back({{0.8275862069, 0, 0.2931034483},{0, 0, 1},     {538.0f/1024, 95.0f/512}});	// vertex 21 - Position and Normal
    vDef.push_back({{0.8275862069, 1, 0},           {0, 0, 1},     {446.0f/1024, 417.0f/512}});	// vertex 22 - Position and Normal
    vDef.push_back({{0.8275862069, 1, 0.2931034483},{0, 0, 1},     {538.0f/1024, 417.0f/512}});// vertex 23 - Position and Normal


	for(int i = 0; i < 24; i += 4){

		vIdx.push_back(i + 0); vIdx.push_back(i + 1); vIdx.push_back(i + 2);	// First triangle
		vIdx.push_back(i + 1); vIdx.push_back(i + 2); vIdx.push_back(i + 3);	// Second triangle
	}



}



void Assignment15::createSphereMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The primitive built here is a sphere of radius 1, centered in the origin, on which the Mars texture is applied seamless.

    constexpr float PI = 3.141595f;

    const int ver = 64;  //number of vertical slices
    const int hor = 32;  //number of horizontal slices
    const int radius = 1;
    
    const float dVer = PI / hor;
    const float dHor = 2 * PI / ver;

    
    for (int i = 0; i <= hor; ++i)
    {
        float angleVer = PI / 2 - i * dVer; /* Starting -pi/2 to pi/2 */
        
        for (int j = 0; j <= ver; ++j)
        {
            float angleHor = j * dHor;

            //forumla to map radius, angleVer, angleHor to x,y,z
            float x = radius * cos(angleVer) * cos(angleHor);
            float y = radius * sin(angleVer);
            float z = radius * cos(angleVer) * sin(angleHor);

            //x,y,z are both the position and normal 
            //uv is calculated by dividing the current index by the resolution
            vDef.push_back({{x,y,z}, {x,y,z}, {(float)j/ver,(float)i/hor}});
            
        }
    }

  
    for(int i = 0; i < hor; ++i)
    {
        //calculate index start of lower and upper slices
        int lower = i * (ver + 1);
        int upper = lower + ver + 1;
        

        for(int j = 0; j < ver; j++)
        {   
            //do not perform for bottommost slice
            if (i != 0)
            {
                vIdx.push_back(lower);
                vIdx.push_back(upper);
                vIdx.push_back(lower + 1);
            }

            //do not perform for topmost slice
            if (i != hor - 1)
            {
                vIdx.push_back(lower + 1);
                vIdx.push_back(upper);
                vIdx.push_back(upper + 1);
            }

            lower++; 
            upper++;
        }

    }

}
