// Name: Jonathan An
// CS 130 Project 1
// Fall Quarter, Year: 2013
// TA: Calvin Phung
//
////////////////////////////////////////////////////////////////////////
#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>

using namespace std;

/*****************************CONSTANTS*********************************/
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
#define PI 3.14
#define SCALE 8

/**************************STRUCTURES**********************************/
// A simple wrapper for to store 3D vectors (given from lab)
// Vector3 is used to store vertex positions of the mesh
struct Vector3
{
	float x;
	float y;
	float z;

	Vector3() : x(0.0), y(0.0), z(0.0)
	{}

	Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	Vector3(const Vector3 & v)
		: x(v.x), y(v.y), z(v.z)
	{}

	Vector3 operator+(const Vector3 & rhs) const
	{ return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
	Vector3 operator-(const Vector3 & rhs) const
	{ return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
	Vector3 operator*(float rhs) const
	{ return Vector3(x * rhs, y * rhs, z * rhs); }
	Vector3 operator/(float rhs) const
	{ return Vector3(x / rhs, y / rhs, z / rhs); }
	Vector3 operator+=(const Vector3 & rhs)
	{ x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
	Vector3 operator-=(const Vector3 & rhs)
	{ x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
	Vector3 operator*=(float rhs)
	{ x *= rhs; y *= rhs; z *= rhs; return *this; }
	Vector3 operator/=(float rhs)
	{ x /= rhs; y /= rhs; z /= rhs; return *this; }

	float magnitude() const
	{ return sqrt(x * x + y * y + z * z); }
	void normalize()
	{ *this /= magnitude(); }
	float dot(const Vector3 & rhs) const
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}
	Vector3 cross(const Vector3 & rhs) const
	{
		return Vector3(y * rhs.z - z * rhs.y,
					z * rhs.x - x * rhs.z,
					x * rhs.y - y * rhs.x);
	}
};

//Edge struct used for the odd case.
//This will help with applying 3/8 weight to adjacent vertices
//and 1/8 weight to opposite vertices
struct Edge
{
	float three8th1, three8th2;
	float one8th1, one8th2;
};
vector <Edge> edges;

//Triangle structure to hold 3 vector3 points
struct Triangle
{
	Vector3 a, b, c;
	Vector3 normalA, normalB, normalC;

	Triangle() : a(0.0,0.0,0.0), b(0.0,0.0,0.0), c(0.0,0.0,0.0)
	{}

	Triangle( Vector3 a, Vector3 b, Vector3 c)
		: a(a), b(b), c(c)
	{}

	Vector3 calcNormalA() {
		Vector3 point1 = b-a;
		Vector3 point2 = c-a;
		normalA = point1.cross(point2);
		normalA.normalize();
	}

	Vector3 calcNormalB() {
		Vector3 point1 = a-b;
		Vector3 point2 = c-b;
		normalB = point1.cross(point2);
		normalB.normalize();
	}

	Vector3 calcNormalC() {
		Vector3 point1 = a-c;
		Vector3 point2 = b-c;
		normalC = point1.cross(point2);
		normalC.normalize();
	}

	/*Triangle( const Vector3 &a, const Vector3 &b, const Vector3 &c)
		: a(a.x,a.y,a.z), b(b.x,b.y,b.z), c(c.x,c.y,c.z)
	{}*/
};

//Ray structure with a vector3 position and vector3 direction
struct Ray
{
	Vector3 o;
	Vector3 d;

	Ray() : o(0.0,0.0,0.0), d(0.0,0.0,0.0)
	{}

	Ray( Vector3 o, Vector3 d )
		: o(o), d(d)
	{}

	/*Ray( const Vector3 &o, const Vector3 &d )
		: o(o.x,o.y,o.z), d(d.x,d.y,d.z)
	{}*/
};

//Quaternion structure to help with rotations
struct Quaternion
{
	float w, x, y, z;

	Quaternion() : w(0), x(0), y(0), z(0)
	{}

	Quaternion( float angle, float x1, float y1, float z1 ) {
		w = cos(angle/2 );
		x = x1 * sin(angle/2);
		y = y1 * sin(angle/2);
		z = z1 * sin(angle/2);
;	}

	void normalize() {
		float magnitude = sqrt(w*w + x*x + y*y +z*z);
		w = w / magnitude;
		x = x / magnitude;
		y = y / magnitude;
		z = z / magnitude;
	}

	Quaternion times(const Quaternion & rhs) const
	{
		float w1 = w*rhs.w - x*rhs.x - y*rhs.y - z*rhs.z;
		float x1 = w*rhs.x + x*rhs.w + y*rhs.z - z*rhs.y;
		float y1 = w*rhs.y - x*rhs.z + y*rhs.w + z*rhs.x;
		float z1 = w*rhs.z + x*rhs.y - y*rhs.x + z*rhs.w;
		return Quaternion(w1,x1,y1,z1);
	}
};

//Light structure for light source
struct Light {
	Vector3 color, pos;
	float intensity;

	Light(): color(0.0,0.0,0.0), pos(0.0,0.0,0.0), intensity(0.9) {}

	Light( Vector3 c, Vector3 p, float i ) {
		color = c;
		pos = p;
		intensity = i;
	}
};

/**********************************GLOBAL VARIABLES************************/
//Global variables used to maintain and manipulate data to apply loop subdivion
vector< Vector3 > coords, coords2, coordsTemp;
vector< Vector3 > faceVertices, faceVertices2, verticesTemp;
vector< vector<int> > neigh;
map< int, set<int> > neighbors;
int VERTICES = 0;
int FACES = 0;
int toggle = 0;
unsigned subCount = 0;

/*******************************RENDER FUNCTIONS****************************/
//Renders pixel to screen
void renderPixel(int x, int y, float r, float g, float b)
{

	glBegin(GL_POINTS);
	glVertex3i(x, y, 0);
	glColor3f(r,g,b);
	glEnd();
}

//Renders a line from (x1, y1) to (x2, y2). (From lab)
void DDA_alg(float x1, float y1, float x2, float y2)
{
	float dx = x2-x1;
	float dy = y2-y1;
	float steps;
	float x_inc, y_inc;
	float x = x1, y = y1;

	if( abs(dx) > abs(dy) ) steps = abs(dx);
	else steps = abs(dy);

	x_inc = dx/steps;
	y_inc = dy/steps;

	for (int i = 0; i < steps; ++i) {
		x += x_inc;
		y += y_inc;
		renderPixel((int)x, (int)y,1,0,0);
	}
}


/********************************************HELPER FUNCTIONS******************************/
//From "http://www.cs.princeton.edu/courses/archive/fall02/cs526/lectures/subdivision.pdf"
//I used these beta and alpha functions to help update
//old vertices for the smoothing process
float beta(int n);
float alpha(int n);

//print functions
void printVertices();
void printCoords();

//helper functions for subdivide and creating adjacencys lists
bool hasInt(vector<int> v, int n);
bool hasVec3(vector<Vector3> v, Vector3 v2);
int search(vector<Vector3> v, Vector3 v2);

/******************************REGULAR FUNCTIONS***************************/

// Reads a text file and parses the file.
void readFile( char* fileName );
void adjList(vector<Vector3> vert, vector<Vector3> coords);

//storeEdges creates an adjacency list using maps
//printEdges will print the map adjacencys lists
void storeEdges( map< int, set<int> > &n, vector<Vector3> fv );
void printEdges( map< int, set<int> > n );

//determine if two vertices are adjacent
bool isAdj( map < int, set<int> > n, int v1, int v2 );

//updates old vertices and applies proper weight
void vertUpdate(vector<Vector3> coords);

//calculates edge points or midpoints and applies proper weight
Vector3 updateMid(vector<Vector3>coords, int n, int m);
//helps create adjacencys lists to calculate midpoints using neighbors
void helpOdd(vector<Vector3> vert);

//subdivide function will get new edge points and their positions.
//It will also update the faces vectors.
void subdivide(vector<Vector3> verts, vector<Vector3> coordinates);

//draws the mesh and its subdivions
void drawTriangles(vector<Vector3> c);

/*------------------------------------------------------------------------*/
/*******************************Project 2 Functions***********************/
/*------------------------------------------------------------------------*/
//global variables
unsigned char lastKey = 0;
char* fileName;
const float NOTHIT = 999999;

//transformation functions
void rotate(unsigned char k);
void translate(unsigned char k);

//-----Phong Lighting
//light source in scence
Vector3 lightSource(800,800,100);
//material color of mesh
Vector3 material(1,0,0);
//calculates diffuse, specular, ambient
Vector3 phongLight(Triangle,float i, float j, Vector3);
//calculates middle of mesh
Vector3 centroid();
//function used to see if a ray intersects a triangle
float rayIntersect( Ray ray, Triangle tri );
//shades mesh
void rayRender(unsigned char k);

//-----Shadow Rendering
void shadowRender(Ray r, vector<Triangle> triangles, float i, float j);
//help render check of shadow vs mesh
float inFront[WINDOW_WIDTH][WINDOW_HEIGHT];

//-----Anti-Aliasing
float aaX[WINDOW_WIDTH][WINDOW_HEIGHT];
float aaY[WINDOW_WIDTH][WINDOW_HEIGHT];
float aaZ[WINDOW_WIDTH][WINDOW_HEIGHT];
//2x2 supersampling
void antiAliasing(float aaX[WINDOW_WIDTH][WINDOW_HEIGHT], float aaY[WINDOW_WIDTH][WINDOW_HEIGHT], float aaZ[WINDOW_WIDTH][WINDOW_HEIGHT]);

//=================helper functions===================
//helper for rayRender
void helpRender(Ray r, vector<Triangle> triangles, float i, float j, Vector3 centroid);
//print mesh lab7
void drawTriangles2();
//calculate determinants
float det2x2(float x11,float x22,float x12,float x21);
float det3x3( float x11, float x12, float x13,
	      float x21, float x22, float x23,
	      float x31, float x32, float x33 );
//find angle between two vectors
float findAngle( Vector3 v1, Vector3 v2 );
//Quaternion -> Rotation Matrix
vector<Vector3> getRotationMatrix( Quaternion q );
//Multiply 3x3 matrix by 3x1 to get new position of point after rotation
Vector3 matrixMultiply( vector<Vector3> rotation, Vector3 point );

/*********************************GL FUNCTIONS**************************/

//renders
void GL_render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawTriangles(coords2);
	if(lastKey=='i') {
		rayRender('i');
		antiAliasing(aaX, aaY, aaZ);
	}

	glutSwapBuffers();
}
//uses keyboard during program
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: //ESCAPE key
			exit(0);
			break;
		case 'g': //toggle
			++toggle;
			if(toggle > 2) toggle = 0;

			break;
		case 'l': //subdivide level
			cout << "Subdivided!" << endl;
			subCount++;
			if(subCount > 3) {
				coords.clear(); coords2.clear(); coordsTemp.clear();
				faceVertices.clear(); faceVertices2.clear();
				verticesTemp.clear(); neighbors.clear(); neigh.clear();

				readFile(fileName);
				faceVertices2 = faceVertices;
				coords2 = coords;
				adjList(faceVertices, coords);
				storeEdges(neighbors, faceVertices);
				helpOdd(faceVertices);
				cout << "Back to Orginal Mesh!" << endl;
				subCount = 0;
				break;
			}
			coordsTemp=coords2;
			verticesTemp=faceVertices2;
			subdivide(verticesTemp, coordsTemp);
			vertUpdate(coordsTemp);
			adjList(faceVertices2, coords2);
			storeEdges( neighbors, faceVertices2 );
			helpOdd(faceVertices2);
			break;
		case 'r': //rotate
			cout << "Rotate Mode:" << endl;
			lastKey = 'r';
			break;
		case 't': //translate
			cout << "Translate Mode:" << endl;
			lastKey = 't';
			break;
		case 'w': //up
			if(lastKey == 't') translate('w');
			if(lastKey == 'r') rotate('w');
			break;
		case 'a': //left
			if(lastKey == 't') translate('a');
			if(lastKey == 'r') rotate('a');
			break;
		case 's': //down
			if(lastKey == 't') translate('s');
			if(lastKey == 'r') rotate('s');
			break;
		case 'd': //right
			if(lastKey == 't') translate('d');
			if(lastKey == 'r') rotate('d');
			break;
		case 'i': //ray-trace rendering
			lastKey = 'i';
			cout << "Rendering image..." << endl;
			break;
	}
}


void GLInit(int* argc, char** argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// ...
	// Complete this function
	// ...
	glutCreateWindow("CS 130 - Jonathan An");

	// The default view coordinates is (-1.0, -1.0) bottom left & (1.0, 1.0) top right.
	// For the purposes of this lab, this is set to the number of pixels
	// in each dimension.
	glMatrixMode(GL_PROJECTION_MATRIX);
	glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);

	glutDisplayFunc(GL_render);
	glutKeyboardFunc(keyboard);
	glClearColor(1.0f,1.0f,1.0f,0.0f);
}
/**********************************************************************/
/******************************MAIN***********************************/
/**********************************************************************/
int main(int argc, char** argv)
{
	fileName = argv[1];
	readFile(fileName);
	faceVertices2 = faceVertices;
	coords2 = coords;
	adjList(faceVertices, coords);
	storeEdges(neighbors, faceVertices);
	helpOdd(faceVertices);
	printCoords();
	printVertices();

	GLInit(&argc, argv);
	glutMainLoop();

	return 0;
}
/*---------------------------FUNCTION DEFINITIONS--------------------------*/
/******************************HELPER FUNCTIONS***************************/
void printVertices() {
	cout << "VERTICES" << endl;
	for(int i = 0; i < faceVertices2.size(); i++) {
		cout << faceVertices2[i].x << " "
		     << faceVertices2[i].y << " "
		     << faceVertices2[i].z << endl;
	}
}

void printCoords() {
	cout << "COORDINATES" << endl;
	for (int i = 0; i < coords2.size(); i++) {
		cout << coords2[i].x << " " << coords2[i].y << " "
                     << coords2[i].z << endl;
	}
}

bool hasVec3(vector<Vector3> v, Vector3 v2) {
	for (int i=0; i< v.size(); i++) {
		if (v[i].x == v2.x && v[i].y == v2.y && v[i].z == v2.z) {
			return true;
		}
	}
	return false;
}

float beta(int n) {
	return (1.0/n)*((5.0/8.0)- pow(((3.0/8.0)+(1.0/4.0)*cos((2*PI)/n)),2) );

}

float alpha(int n) {
	return 1.0 - n*beta(n);
}


int search(vector<Vector3> v, Vector3 v2) {
	for (int i=0; i< v.size(); i++) {
		if (v[i].x == v2.x && v[i].y == v2.y && v[i].z == v2.z) {
			return i;
		}
	}
	return -1;
}

bool hasInt(vector<int> v, int n) {
	for (int i=0; i< v.size(); i++) {
		if (v[i] == n) {
			return true;
		}
	}
	return false;
}
/******************************REGULAR FUNCTIONS***************************/
void readFile( char* fileName ) {
	float coord;
	Vector3 v3;

	ifstream myFile(fileName);
	if( myFile.is_open() ) {
		myFile >> VERTICES;
		myFile >> FACES;

		for(int i = 0; i < VERTICES; i++) {
			myFile >> coord;
			v3.x = coord;
			myFile >> coord;
			v3.y = coord;
			myFile >> coord;
			v3.z = coord;
			coords.push_back(v3);
		}
		for(int i =0; i < FACES; i++) {
			myFile >> coord;
			v3.x = coord;
			myFile >> coord;
			v3.y = coord;
			myFile >> coord;
			v3.z = coord;
			faceVertices.push_back(v3);
		}


		myFile.close();
	}

	else cout << "Unable to open file";

}

bool isAdj( map < int, set<int> > n, int v1, int v2 ) {
	bool adjFlag = false;

	typedef map<int, set<int> >::const_iterator MapIterator;
	typedef set<int>::const_iterator SetIterator;

	map< int, set<int> >::iterator it;
	map< int, set<int> >::iterator it2;

	it = n.find(v1);
	for( SetIterator s1 = it->second.begin(); s1 != it->second.end(); s1++ ) {
		if( *s1 == v2 ) {
			adjFlag = true;
			cout << v1 << " adjacent to " << v2 << endl;
			break;
		}
		adjFlag = false;
	}
	if(!adjFlag)
		cout << v1 <<  " NOT adjacent to " << v2 << endl;

	return adjFlag;

}

void helpOdd(vector<Vector3> vert) {
	float adj1=0, adj2=0, adj3=0;
	float neigh1, neigh2, neigh3;
	edges.clear();
	for(int i = 0; i < vert.size()-1; ++i) {
		adj1 = vert[i].x;
		adj2 = vert[i].y;
		adj3 = vert[i].z;
		for(int j = i+1; j < vert.size(); ++j) {
			Edge line;
			neigh1 = vert[j].x;
			neigh2 = vert[j].y;
			neigh3 = vert[j].z;
			if( (adj1 == neigh1 || adj1 == neigh2 || adj1 == neigh3) &&
			     	  (adj3 == neigh1 || adj3 == neigh2 || adj3 == neigh3)) {
				line.three8th1 = adj1, line.three8th2 = adj3, line.one8th1 = adj2;
				if (neigh1 != adj1 && neigh1 != adj3) line.one8th2 = neigh1;
				else if (neigh2 != adj1 && neigh2 != adj3) line.one8th2 = neigh2;
				else line.one8th2 = neigh3;
				edges.push_back(line);
			}
			else if( (adj1 == neigh1 || adj1 == neigh2 || adj1 == neigh3) &&
			     (adj2 == neigh1 || adj2 == neigh2 || adj2 == neigh3) ) {
				line.three8th1 = adj1, line.three8th2 = adj2, line.one8th1 = adj3;
				if (neigh1 != adj1 && neigh1 != adj2) line.one8th2 = neigh1;
				else if (neigh2 != adj1 && neigh2 != adj2) line.one8th1 = neigh2;
				else line.one8th2 = neigh3;
				edges.push_back(line);
	 	     	}
			else{
				line.three8th1 = adj2, line.three8th2 = adj3, line.one8th1 = adj1;
				if (neigh1 != adj2 && neigh1 != adj3) line.one8th2 = neigh1;
				else if (neigh2 != adj2 && neigh2 != adj3) line.one8th2 = neigh2;
				else line.one8th2 = neigh3;
				edges.push_back(line);
			}
		}
	}
}

void vertUpdate(vector<Vector3> coords) {
	float betaNum, alphaNum = 0;
	typedef map<int, set<int> >::const_iterator MapIterator;
	for( MapIterator iter = neighbors.begin(); iter != neighbors.end(); iter++ ) {
		Vector3 update = coords[iter->first];
		Vector3 tmp;
		betaNum = beta(iter->second.size());
		alphaNum = alpha(iter->second.size());
		update.x *= alphaNum, update.y *= alphaNum, update.z *= alphaNum;
		typedef set<int>::const_iterator SetIterator;
		for( SetIterator set_iter = iter->second.begin(); set_iter != iter->second.end(); set_iter++ ) {
			tmp.x += coords[*set_iter].x;
			tmp.y += coords[*set_iter].y;
			tmp.z += coords[*set_iter].z;
		}
		tmp.x*=betaNum, tmp.y*=betaNum, tmp.z*=betaNum;
		update.x += tmp.x, update.y += tmp.y, update.z += tmp.z;
		coords2[iter->first] = update;
	}
}

void adjList(vector<Vector3> vert, vector<Vector3> coords) {
	vector<int> tmp;
	neigh.clear();
	for(int i=0; i < coords.size(); ++i) tmp.push_back(i), neigh.push_back(tmp), tmp.clear();
	for (int j=0; j < coords.size(); ++j) {
		for (int k=0; k < vert.size(); ++k) {
			if (vert[k].x == neigh[j][0]) {
				if (!hasInt(neigh[j], (int)vert[k].y)) neigh[j].push_back((int)vert[k].y);
				if (!hasInt(neigh[j], (int)vert[k].z)) neigh[j].push_back((int)vert[k].z);
			}
			if (vert[k].y == neigh[j][0]) {
				if (!hasInt(neigh[j], (int)vert[k].x)) neigh[j].push_back((int)vert[k].x);
				if (!hasInt(neigh[j], (int)vert[k].z)) neigh[j].push_back((int)vert[k].z);
			}
			if (vert[k].z == neigh[j][0]) {
				if (!hasInt(neigh[j], (int)vert[k].x)) neigh[j].push_back((int)vert[k].x);
				if (!hasInt(neigh[j], (int)vert[k].y)) neigh[j].push_back((int)vert[k].y);
			}
		}
	}
}

void storeEdges( map< int, set<int> > &n, vector<Vector3> fv ) {
	for( int i = 0; i < fv.size(); i++ ) {
		n[(int)fv[i].x].insert((int)fv[i].y);
		n[(int)fv[i].x].insert((int)fv[i].z);

		n[(int)fv[i].y].insert((int)fv[i].x);
		n[(int)fv[i].y].insert((int)fv[i].z);

		n[(int)fv[i].z].insert((int)fv[i].x);
		n[(int)fv[i].z].insert((int)fv[i].y);
	}
}

void printEdges( map< int, set<int> > n ) {
	typedef map<int, set<int> >::const_iterator MapIterator;
	for( MapIterator iter = n.begin(); iter != n.end(); iter++ ) {
		cout << "Vertice: " << iter->first << endl << "Neighbors:" << endl, cout.flush();
		typedef set<int>::const_iterator SetIterator;
		for( SetIterator set_iter = iter->second.begin(); set_iter != iter->second.end(); set_iter++ ) {
			cout << " " << *set_iter << endl, cout.flush();
		}
	}

}

Vector3 updateMid(vector<Vector3>coords, int n, int m) {
	Vector3 mid;
	float VALUE_3_8 = 3.0/8.0;
	float VALUE_1_8 = 1.0/8.0;
	for(int i = 0; i < edges.size();++i) {
		if ( (edges[i].three8th1 == m && edges[i].three8th2 == n) ||
		     (edges[i].three8th1 == n && edges[i].three8th2==m ) ) {
			mid.x=VALUE_3_8*coords[n].x+VALUE_3_8*coords[m].x+VALUE_1_8*coords[(int)edges[i].one8th1].x+VALUE_1_8*coords[(int)edges[i].one8th2].x;
			mid.y=VALUE_3_8*coords[n].y+VALUE_3_8*coords[m].y+VALUE_1_8*coords[(int)edges[i].one8th1].y+VALUE_1_8*coords[(int)edges[i].one8th2].y;
			mid.z=VALUE_3_8*coords[n].z+VALUE_3_8*coords[m].z+VALUE_1_8*coords[(int)edges[i].one8th1].z+VALUE_1_8*coords[(int)edges[i].one8th2].z;
			return mid;
		}
	}
	return mid;
}

void subdivide(vector<Vector3> verts, vector<Vector3> coordinates) {
	Vector3 newv, e1, e2, e3;
	faceVertices2.clear(); coords2.clear();
	coords2 = coordinates;

	for(int i = 0; i < verts.size(); i++) {
		e1 = updateMid(coordinates, (int)verts[i].x, (int)verts[i].y);
		if (!hasVec3(coords2, e1)) coords2.push_back(e1);
		e2 = updateMid(coordinates, (int)verts[i].x, (int)verts[i].z);
		if (!hasVec3(coords2, e2)) coords2.push_back(e2);
		e3 = updateMid(coordinates, (int)verts[i].y, (int)verts[i].z);
		if (!hasVec3(coords2, e3)) coords2.push_back(e3);

		newv.x=verts[i].x;
		newv.y=search(coords2, e1);
		newv.z=search(coords2, e2);
		faceVertices2.push_back(newv);

		newv.x=verts[i].y;
		newv.y=search(coords2, e1);
		newv.z=search(coords2, e3);
		faceVertices2.push_back(newv);

		newv.x=verts[i].z;
		newv.y=search(coords2, e2);
		newv.z=search(coords2, e3);
		faceVertices2.push_back(newv);

		newv.x=search(coords2, e1);
		newv.y=search(coords2, e2);
		newv.z=search(coords2, e3);
		faceVertices2.push_back(newv);
	}
}

void drawTriangles(vector<Vector3> c) {
	Vector3 c1, c2;
	for (int i = 0; i < neigh.size();++i) {
		for (int j=1; j < neigh[i].size(); ++j) {
			c1.x = c[i].x*SCALE;
			c1.y = c[i].y*SCALE;
			c1.z = c[i].z*SCALE;

			c2.x = c[neigh[i][j]].x*SCALE;
			c2.y = c[neigh[i][j]].y*SCALE;
			c2.z = c[neigh[i][j]].z*SCALE;

			if (toggle==0) DDA_alg(c1.x, c1.y, c2.x, c2.y);
			else if(toggle==1) DDA_alg(c1.x, c1.z, c2.x, c2.z);
			else DDA_alg(c1.z, c1.y, c2.z, c2.y);

			glutPostRedisplay();
		}
	}
}

float det2x2(float x11,float x22,float x12,float x21) {
	float ret = 0;
	ret = (x11 * x22) - (x12 * x21);
	return ret;
}

float det3x3( float x11, float x12, float x13,
	      float x21, float x22, float x23,
	      float x31, float x32, float x33 ) {
	float ret = 0, det1 = 0, det2 = 0, det3 = 0;
	det1 = det2x2(x22,x33,x23,x32);
	//cout << "det1: " << det1 << endl;
	det2 = det2x2(x21,x33,x23,x31);
	//cout << "det2: " << det3 << endl;
	det3 = det2x2(x21,x32,x22,x31);
	//cout << "det3: " << det3 << endl;
	ret = (x11*det1)-(x12*det2)+(x13*det3);
	return ret;
}

float findAngle( Vector3 v1, Vector3 v2 ) {
	float dotProduct = v1.dot(v2);
	float mag1 = v1.magnitude();
	float mag2 = v2.magnitude();
	float cosTheta = dotProduct/(mag1*mag2);
	float result = acosf(cosTheta);
	return result*57.2957795;
}

vector<Vector3> getRotationMatrix( Quaternion q ) {
	Vector3 row1, row2, row3;
	vector<Vector3> rotation;
	row1.x = q.w*q.w + q.x*q.x - q.y*q.y - q.z*q.z;
	row1.y = (2*q.x*q.y) - (2*q.w*q.z);
	row1.z = (2*q.x*q.z) + (2*q.w*q.y);

	row2.x = (2*q.x*q.y) + (2*q.w*q.z);
	row2.y = q.w*q.w - q.x*q.x + q.y*q.y - q.z*q.z;
	row2.z = (2*q.y*q.z) + (2*q.w*q.x);

	row3.x = (2*q.x*q.z)-(2*q.w*q.y);
	row3.y = (2*q.y*q.z)-(2*q.w*q.x);
	row3.z = q.w*q.w - q.x*q.x - q.y*q.y + q.z*q.z;

	rotation.push_back(row1);
	rotation.push_back(row2);
	rotation.push_back(row3);
	return rotation;
}

Vector3 matrixMultiply( vector<Vector3> rotation, Vector3 point ) {
	float result1 = rotation[0].dot(point);
	float result2 = rotation[1].dot(point);
	float result3 = rotation[2].dot(point);
	Vector3 ret(result1,result2,result3);
	return ret;
}

void rotate(unsigned char k) {
	//rotate by 5 degress
	float degrees = 5;
	float radians = degrees * 0.0174532925;
	if( k == 'a' || k == 's' ) radians = -radians;

	//used to translate to origin and back
	float average = 0;
	if( k == 'w' || k == 's' ) {
		for(int i = 0; i < coords2.size(); i++) {
			average += coords2[i].x;
		}
		average = average/coords2.size();
	}
	else if( k == 'a' || k == 'd' ) {
		for(int i = 0; i < coords2.size(); i++) {
			average += coords2[i].y;
		}
		average = average/coords2.size();
	}

	vector<Vector3> rotation;
	Quaternion x(radians,1,0,0);
	Quaternion y(radians,0,1,0);

	switch(k)
	{
		case 'w': //rotate up
			rotation = getRotationMatrix(x);
			for(int i = 0; i < coords2.size(); i++) {
				coords2[i].x -= average;
				coords2[i].y -= average;
				coords2[i].z -= average;
				coords2[i] = matrixMultiply( rotation, coords2[i] );
				coords2[i].x += average;
				coords2[i].y += average;
				coords2[i].z += average;
			}
			break;
		case 'a': //rotate left
			rotation = getRotationMatrix(y);
			for(int i = 0; i < coords2.size(); i++) {
				coords2[i].x -= average;
				coords2[i].y -= average;
				coords2[i].z -= average;
				coords2[i] = matrixMultiply( rotation, coords2[i] );
				coords2[i].x += average;
				coords2[i].y += average;
				coords2[i].z += average;
			}
			break;
		case 's': //rotate down
			rotation = getRotationMatrix(x);
			for(int i = 0; i < coords2.size(); i++) {
				coords2[i].x -= average;
				coords2[i].y -= average;
				coords2[i].z -= average;
				coords2[i] = matrixMultiply( rotation, coords2[i] );
				coords2[i].x += average;
				coords2[i].y += average;
				coords2[i].z += average;
			}
			break;
		case 'd': //rotate right
			rotation = getRotationMatrix(y);
			for(int i = 0; i < coords2.size(); i++) {
				coords2[i].x -= average;
				coords2[i].y -= average;
				coords2[i].z -= average;
				coords2[i] = matrixMultiply( rotation, coords2[i] );
				coords2[i].x += average;
				coords2[i].y += average;
				coords2[i].z += average;
			}
			break;
	}
}

void translate(unsigned char k) {
	//check boundries
	float smallX = coords2[0].x, bigX = coords2[0].x,
	      smallY = coords2[0].y, bigY = coords2[0].y;
	for( int i = 0; i < coords2.size(); i++ ) {
		if( coords2[i].x < smallX ) smallX = coords2[i].x;
		if( coords2[i].x > bigX ) bigX = coords2[i].x;
		if( coords2[i].y < smallY ) smallY = coords2[i].y;
		if( coords2[i].y > bigY ) bigY = coords2[i].y;
	}

	//translate
	switch(k)
	{
		case 'w': //move up
			for( int i = 0; i < coords2.size(); i++ ) {
				if( bigY*SCALE < WINDOW_HEIGHT ) {
					coords2[i].y += 5;
				}
			}
			break;
		case 'a': //move left
			for( int i = 0; i < coords2.size(); i++ ) {
				if( smallX*SCALE > 0 ) {
					coords2[i].x -= 5;
				}
			}
			break;
		case 's': //move down
			for( int i = 0; i < coords2.size(); i++ ) {
				if( smallY*SCALE > 0 ) {
					coords2[i].y -= 5;
				}
			}
			break;
		case 'd': //move right
			for( int i = 0; i < coords2.size(); i++ ) {
				if( bigX*SCALE < WINDOW_WIDTH ) {
					coords2[i].x += 5;
				}
			}
			break;
	}
}

float rayIntersect( Ray ray, Triangle tri ) {
	float t, beta, gamma;
	Vector3 BminusA, CminusA, AminusRo;

	//initialize variables
	BminusA = tri.b - tri.a;
	//cout << "BminusA: " << BminusA.x << " " << BminusA.y << " " << BminusA.z << endl;
	CminusA = tri.c -tri.a;
	//cout << "CminusA: " << CminusA.x << " " << CminusA.y << " " << CminusA.z << endl;
	AminusRo = tri.a -ray.o;
	//cout << "AminusRo: " << AminusRo.x << " " << AminusRo.y << " " << AminusRo.z << endl;

	//find determinant for t
	float dett= 0;
	dett = det3x3((-BminusA.x),(-CminusA.x),(AminusRo.x),
		      (-BminusA.y),(-CminusA.y),(AminusRo.y),
		      (-BminusA.z),(-CminusA.z),(AminusRo.z));
	//cout << "dett: " << dett << endl;

	//find determinant for c
	float detc = 0;
	detc = det3x3((-BminusA.x),(AminusRo.x),(ray.d.x),
		      (-BminusA.y),(AminusRo.y),(ray.d.y),
		      (-BminusA.z),(AminusRo.z),(ray.d.z));
	//cout << "detc: " << detc << endl;

	//find determinant for b
	float detb = 0;
	detb = det3x3((AminusRo.x),(-CminusA.x),(ray.d.x),
		      (AminusRo.y),(-CminusA.y),(ray.d.y),
		      (AminusRo.z),(-CminusA.z),(ray.d.z));
	//cout << "detb: " << detb << endl;

	//find determinant for a
	float deta = 0;
	deta = det3x3((-BminusA.x),(-CminusA.x),(ray.d.x),
		      (-BminusA.y),(-CminusA.y),(ray.d.y),
		      (-BminusA.z),(-CminusA.z),(ray.d.z));
	//cout << "deta: " << deta << endl;

	t = dett/deta;
	//cout << "t: " << t << endl;
	beta = detb/deta;
	//cout << "beta: " << beta << endl;
	gamma = detc/deta;
	//cout << "gamma: " << gamma << endl;

	if( t > 0 ) { //tri is in front of us
		if( beta > 0 && gamma > 0 ) {
			if( beta + gamma < 1 ) { //we intersect
				return t;
			}
		}
	}
	//else we do not intersect
	t = NOTHIT;
	return t;
}

Vector3 centroid() {
	float x=0, y=0, z=0;
	for(int i = 0; i < coords2.size(); i++) {
		x += coords2[i].x;
	}
	x /= coords2.size();
	for(int i = 0; i < coords2.size(); i++) {
		y += coords2[i].y;
	}
	y /= coords2.size();
	for(int i = 0; i < coords2.size(); i++) {
		z += coords2[i].z;
	}
	z /= coords2.size();
	Vector3 ret(x,y,z);
	return ret;
}

Vector3 phongLight(Triangle tri,float i, float j, Vector3 centroid) {
	//-----------------AMBIENT LIGHT--------------
	float kA = 0.6;
	Vector3 iA(0.5,0.5,0.5);
	iA.normalize();
	Vector3 ambient = iA;//*kA;

	//----------------DIFFUSE LIGHT--------------
	float kD = 0.6;
	Vector3 iD(0.7,0.7,0.7);
	iD.normalize();
	//calculate vector from pos to lightsource
	Vector3 lightSource(800,800,0);
	lightSource.x -= i; lightSource.y -= j;
	lightSource = lightSource * -1.0;
	lightSource.normalize();
	//calculate normal of face
	Vector3 normal = tri.calcNormalA();
	normal.normalize();
	//calculate vector from centroid to pos
	Vector3 point;
	Vector3 pos;
	if( toggle == 0 ) {
		pos.x=i; pos.y=j; pos.z=0;
		centroid.z = 0;
	}
	else if(toggle == 1) {
		pos.x=i; pos.y=0; pos.z=j;
		centroid.y = 0;
	}
	else {
		pos.x=0; pos.y=i; pos.z=j;
		centroid.x = 0;
	}
	point = pos - centroid;
	point.normalize();
	//check if normal is pointing the right way
	float temp = normal.dot(point);
	if(temp < 0) normal *= -1;
	//check if angle between normal and centroid->pos is > 90
	//if(abs(findAngle(point,normal)) > 90) normal *= -1;
	//calculate l.n
	float LdotN = lightSource.dot(normal);
	//LdotN = LdotN < 0 ? 0.0f : LdotN;
	Vector3 diffuse = (iD/*kD*/)*LdotN;

	//------------------SPECULAR LIGHT------------------
	float kS = 0.5;
	Vector3 iS(0.1,0.1,0.1);
	//shininess coeff
	float alpha = 50;
	//figure out view
	Vector3 view;
	if(toggle == 0) {view.x=1; view.y=1; view.z=0;}
	else if(toggle==1) {view.x=1; view.y=0; view.z=1;}
	else {view.x=0; view.y=1; view.z=1;}
	view.normalize();
	//calculate r
	normal = tri.calcNormalA();
	normal.normalize();
	float NdotL = normal.dot(lightSource);
	Vector3 r;
	r = normal*(2*NdotL);
	r.x -= 1; r.y -= 1; r.z -= 1;
	r.normalize();
	//calculate r.v
	float RdotV = r.dot(view);
	Vector3 specular = (iS*kS)*(pow(RdotV,alpha));


	return ambient+diffuse+specular;
}

void helpRender(Ray r, vector<Triangle> triangles, float i, float j, Vector3 centroid) {
	float t = NOTHIT, prev = NOTHIT, checkHit = 0;
	Vector3 phong;
	for(int k = 0; k < triangles.size(); k++) {
		t = rayIntersect( r, triangles[k] );
		inFront[(int)i][(int)j] = t;
		if(t < prev) {
			checkHit = 1; prev = t;
			phong = phongLight(triangles[k], i, j, centroid);

			//render object at pixel i,j
			renderPixel( (int)i, (int)j, phong.x*material.x, phong.y*material.y, phong.z*material.z );
			aaX[(int)i][(int)j] = phong.x*material.x;
			aaY[(int)i][(int)j] = phong.y*material.y;
			aaZ[(int)i][(int)j] = phong.z*material.z;
		}
	}
	//background
	if( checkHit != 1 ) {
		renderPixel((int)i,(int)j,1,1,1);
		aaX[(int)i][(int)j] = 1;
		aaY[(int)i][(int)j] = 1;
		aaZ[(int)i][(int)j] = 1;
	}
}

void shadowRender(Ray r, vector<Triangle> triangles, float i, float j) {
	float t = NOTHIT, prev = NOTHIT, checkHit = 0;
	for(int k = 0; k < triangles.size(); k++) {
		t = rayIntersect( r, triangles[k] );
		if(t < prev) checkHit = 1;
		if(t < prev) prev = t;

		//shadow
		if( checkHit == 1 && t < inFront[(int)i][(int)j] ) {
			renderPixel((int)i,(int)j,0,0,0);
			aaX[(int)i][(int)j] = 0;
			aaY[(int)i][(int)j] = 0;
			aaZ[(int)i][(int)j] = 0;
		}
	}
}

void rayRender(unsigned char k) {
	if(k=='i') {
		//make a vector of all triangles/faces
		vector<Triangle> triangles;
		for(int i = 0; i < faceVertices2.size(); i++) {
			Triangle tri;
			tri.a.x = coords2[(int)faceVertices2[i].x].x*SCALE;
			tri.a.y = coords2[(int)faceVertices2[i].x].y*SCALE;
			tri.a.z = coords2[(int)faceVertices2[i].x].z*SCALE;
			tri.b.x = coords2[(int)faceVertices2[i].y].x*SCALE;
			tri.b.y = coords2[(int)faceVertices2[i].y].y*SCALE;
			tri.b.z = coords2[(int)faceVertices2[i].y].z*SCALE;
			tri.c.x = coords2[(int)faceVertices2[i].z].x*SCALE;
			tri.c.y = coords2[(int)faceVertices2[i].z].y*SCALE;
			tri.c.z = coords2[(int)faceVertices2[i].z].z*SCALE;
			triangles.push_back(tri);
		}

		Vector3 cent = centroid();

		//For checking if mesh or shadow is in front
		for(int i = 0; i < WINDOW_WIDTH; i++) {
			for(int j = 0; j < WINDOW_HEIGHT; j++) {
				inFront[i][j] = NOTHIT;
			}
		}

		//direction for shadow cast
		Vector3 l = lightSource;
		l.normalize();
		l.z = 1.0;

		//FRONT VIEW
		if(toggle == 0) {
			Vector3 d(0,0,1);
			for(float i = 0; i < WINDOW_WIDTH; i++) {
				for(float j = 0; j < WINDOW_HEIGHT; j++) {
					Vector3 o(i,j,0);
					Ray r(o,d); //ray tracer
					Ray r2(o,l); //shadow ray
					helpRender(r,triangles,i,j,cent);
					shadowRender(r2,triangles,i,j);
				}
			}
		}
		//TOP VIEW
		else if(toggle == 1) {
			Vector3 d(0,1,0);
			for(float i = 0; i < WINDOW_WIDTH; i++) {
				for(float j = 0; j < WINDOW_HEIGHT; j++) {
					Vector3 o(i,0,j);
					Ray r(o,d);
					helpRender(r,triangles,i,j, cent);
				}
			}
		}
		//SIDE VIEW
		else {
			Vector3 d(1,0,0);
			for(float i = 0; i < WINDOW_WIDTH; i++) {
				for(float j = 0; j < WINDOW_HEIGHT; j++) {
					Vector3 o(0,j,i);
					Ray r(o,d);
					helpRender(r,triangles,i,j, cent);
				}
			}
		}
	}
}

void antiAliasing(float aaX[WINDOW_WIDTH][WINDOW_HEIGHT], float aaY[WINDOW_WIDTH][WINDOW_HEIGHT], float aaZ[WINDOW_WIDTH][WINDOW_HEIGHT]) {
	float newPixelX = 0, newPixelY = 0, newPixelZ = 0;
	for(int i = 0; i < WINDOW_WIDTH-1; i++) {
		for(int j=0; j < WINDOW_HEIGHT-1; j++) {
			newPixelX = ( aaX[i][j]+aaX[i+1][j]+aaX[i][j+1]+aaX[i+1][j+1] )/4;
			newPixelY = ( aaY[i][j]+aaY[i+1][j]+aaY[i][j+1]+aaY[i+1][j+1] )/4;
			newPixelZ = ( aaZ[i][j]+aaZ[i+1][j]+aaZ[i][j+1]+aaZ[i+1][j+1] )/4;
			renderPixel(i,j,newPixelX,newPixelY,newPixelZ);
		}
	}
}
