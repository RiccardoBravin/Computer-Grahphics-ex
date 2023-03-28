
void lrWalls(int i, int j, int &h, int &vCnt,std::vector<float> &vPos, std::vector<int> &vIdx){
	
	vPos.push_back(i); vPos.push_back(h); vPos.push_back(-j);			
	vPos.push_back(i+1); vPos.push_back(h); vPos.push_back(-j);
	
	h = h ? 0 : 1;
	
	vPos.push_back(i); vPos.push_back(h); vPos.push_back(-j);			
	vPos.push_back(i+1); vPos.push_back(h); vPos.push_back(-j);
	
	vIdx.push_back(vCnt); vIdx.push_back(vCnt+1); vIdx.push_back(vCnt+2);	// First triangle
	vIdx.push_back(vCnt+1); vIdx.push_back(vCnt+2); vIdx.push_back(vCnt+3);

	vCnt+=4;
}

bool checkUp(int i, int j, char **maze, int col){
	
	if(i == 0) return true;

	for (int k = j; k < col; k++){
		if(maze[i][k] == ' ') break;

		if(maze[i-1][k] == ' '){
			return true;
		}
	}

	return false;	
}

bool checkDown(int i, int j, char **maze, int col){

	for (int k = j; k < col; k++){
		if(maze[i][k] == ' ') break;
		
		if(maze[i+1][k] == ' '){
			return true;
		}
	}
	return false;
}

void Assignment08::createMazeMesh(int row, int col, char **maze) {
	// The procedure gets in input the number of rows <row> of the maze, and the number of columns <col>
	// Element <maze[r][c]>, with 0 <= r <= row-1 and 0 <= c <= col-1 contains:
	//		Symbol ' ' if there is an empty space
	//		Symbol '#' if there is a wall
	//
	// Example: The following piece of code executes the instruction in the ... section
	//          if there is a wall in position r=5, c=7
	//
	// int r, c;
	// r = 5; c = 7;
	// if(maze[r][c] == '#') {
	//		...
	// }
	//
	// The example below creates a square, with four vertices and two triangles.
	// It must be deleted and replaced with your code creating the mesh of the maze.
	
	int vCnt = 0;
	int base1 = 0;
	int base2 = 0;
	
	for(int i = 0; i < row; i++){
		int h = 0; //current height
		
		if(i == row-1) base2 = vCnt+1; //saving index for bottom floor

		for (int j = 0; j < col; j++){
			
			if(h == 0 && maze[i][j] == '#'){
				
				lrWalls(i, j, h, vCnt, vPos, vIdx);
				
				//roofs of each block
				vIdx.push_back(vCnt-2); vIdx.push_back(vCnt-1); vIdx.push_back(vCnt);
				vIdx.push_back(vCnt-1); vIdx.push_back(vCnt); vIdx.push_back(vCnt+1);
				
				//build walls on the north face
				if(checkUp(i,j,maze,col)){
					vIdx.push_back(vCnt-4); vIdx.push_back(vCnt-2); vIdx.push_back(vCnt);
					vIdx.push_back(vCnt-4); vIdx.push_back(vCnt); vIdx.push_back(vCnt+2);
				}
				
				//build walls on the south face
				if( i < row-1 && checkDown(i,j,maze,col) || i == row-1){
					vIdx.push_back(vCnt-3); vIdx.push_back(vCnt-1); vIdx.push_back(vCnt+1);
					vIdx.push_back(vCnt-3); vIdx.push_back(vCnt+1); vIdx.push_back(vCnt+3);
				}
			}

			if(h == 1 && maze[i][j] == ' '){
				//vIdx.push_back(vCnt); vIdx.push_back(base1); vIdx.push_back(base2);			
				lrWalls(i, j, h, vCnt, vPos, vIdx);
			}

		}
		
		lrWalls(i, col, h, vCnt, vPos, vIdx);
		if(i == 0) base1 = vCnt-2; //saving index for bottom floor
	}
	
	vIdx.push_back(0); vIdx.push_back(base1); vIdx.push_back(base2);	// half base
	vIdx.push_back(base1); vIdx.push_back(base2); vIdx.push_back(vCnt-1);

	std::cout << "d1:" << base1 << "\nd2:" << base2 << " \ncnt:" << vCnt <<std::endl; 

}
