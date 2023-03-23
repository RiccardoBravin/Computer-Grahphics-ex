

void SetupTriangles(Assignment01 *A) {
/**************
 Function Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 Using function Triangle(...) try to draw a children house, similar to the one below.
 
 First remove the two function below (given only as an example), and replace them with your own.
 Since it is a C program, you can use for loops if you think it can be helpful in your drawing.
 The for() command below that draws a sun like shape in exact center of the screen near the top,
 is an example on how you can use it: please remove it, and replace it with your own code.
 It is not necessery to use a for loop if you do not really need it: it has been put here only as
 an example to help students not familiar with C++.
***************/
	
	//pink ear rgb(255, 192, 203)
	A->Triangle(50/400.0, -275/300.0, 125/400.0, -200/300.0, 50/400.0, -125/300.0, 255/255.0, 192/255.0, 203/255.0);

	//aqua ear rgb(128, 211, 225)
	A->Triangle(200/400.0, -275/300.0, 125/400.0, -200/300.0, 200/400.0, -125/300.0, 128/255.0, 221/255.0, 225/255.0);

	//purple head rgb(128, 20, 128)
	A->Triangle(125/400.0, -200/300.0, 50/400.0, -125/300.0, 200/400.0, -125/300.0, 128/255.0, 20/255.0, 128/255.0);
	A->Triangle(125/400.0, -50/300.0, 50/400.0, -125/300.0, 200/400.0, -125/300.0, 128/255.0, 20/255.0, 128/255.0);

	//yellow body rgb(200, 200, 0)
	A->Triangle(50/400.0, -125/300.0, 150/400.0, -25/300.0, 50/400.0, 100/300.0, 200/255.0, 200/255.0, 0/255.0);

	//red body rgb(255, 0, 0)
	A->Triangle(50/400.0, -125/300.0, 50/400.0, 200/300.0, -100/400.0, 25/300.0, 255/255.0, 0/255.0, 0/255.0);

	//blue feet rgb(50, 100, 255)
	A->Triangle(-100/400.0, 25/300.0, -100/400.0, 250/300.0, 100/400.0, 250/300.0, 50/255.0, 100/255.0, 255/255.0);

	//green tail rgb(50, 255, 50)
	A->Triangle(-100/400.0, 250/300.0, -250/400.0, 250/300.0, -175/400.0, 175/300.0, 50/255.0, 255/255.0, 50/255.0);
	A->Triangle(-325/400.0, 175/300.0, -250/400.0, 250/300.0, -175/400.0, 175/300.0, 50/255.0, 255/255.0, 50/255.0);

}
