//
//  House.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Luyao Zhou on 10/6/15.
//  Copyright © 2015 RexWest. All rights reserved.
//

#include "House.hpp"
#include "Globals.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



// This data structure defines a simple house

int nVerts = 42;    // your vertex array needs to have this many entries
int i = 0;

// These are the x,y,z coordinates of the vertices of the triangles
float vertices[] = {
    -4,-4,4, 4,-4,4, 4,4,4, -4,4,4,     // front face
    -4,-4,-4, -4,-4,4, -4,4,4, -4,4,-4, // left face
    4,-4,-4,-4,-4,-4, -4,4,-4, 4,4,-4,  // back face
    4,-4,4, 4,-4,-4, 4,4,-4, 4,4,4,     // right face
    4,4,4, 4,4,-4, -4,4,-4, -4,4,4,     // top face
    -4,-4,4, -4,-4,-4, 4,-4,-4, 4,-4,4, // bottom face
    
    -20,-4,20, 20,-4,20, 20,-4,-20, -20,-4,-20, // grass
    -4,4,4, 4,4,4, 0,8,4,                       // front attic wall
    4,4,4, 4,4,-4, 0,8,-4, 0,8,4,               // left slope
    -4,4,4, 0,8,4, 0,8,-4, -4,4,-4,             // right slope
    4,4,-4, -4,4,-4, 0,8,-4};                   // rear attic wall

// These are the RGB colors corresponding to the vertices, in the same order
float colors[] = {
    1,0,0, 1,0,0, 1,0,0, 1,0,0,  // front is red
    0,1,0, 0,1,0, 0,1,0, 0,1,0,  // left is green
    1,0,0, 1,0,0, 1,0,0, 1,0,0,  // back is red
    0,1,0, 0,1,0, 0,1,0, 0,1,0,  // right is green
    0,0,1, 0,0,1, 0,0,1, 0,0,1,  // top is blue
    0,0,1, 0,0,1, 0,0,1, 0,0,1,  // bottom is blue
    
    0,0.5,0, 0,0.5,0, 0,0.5,0, 0,0.5,0, // grass is dark green
    0,0,1, 0,0,1, 0,0,1,                // front attic wall is blue
    1,0,0, 1,0,0, 1,0,0, 1,0,0,         // left slope is green
    0,1,0, 0,1,0, 0,1,0, 0,1,0,         // right slope is red
    0,0,1, 0,0,1, 0,0,1,};              // rear attic wall is red

// The index data stores the connectivity of the triangles;
// index 0 refers to the first triangle defined above
int indices[] = {
    0,2,3,    0,1,2,      // front face
    4,6,7,    4,5,6,      // left face
    8,10,11,  8,9,10,     // back face
    12,14,15, 12,13,14,   // right face
    16,18,19, 16,17,18,   // top face
    20,22,23, 20,21,22,   // bottom face
    
    24,26,27, 24,25,26,   // grass
    28,29,30,             // front attic wall
    31,33,34, 31,32,33,   // left slope
    35,37,38, 35,36,37,   // right slope
    39,40,41};            // rear attic wall


House::House(void) : Drawable()
{
}

House::~House(void)
{
    //Delete any dynamically allocated memory/objects here
}


void House::draw(DrawData& data)
{

    material.apply();
    
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glMultMatrixf(toWorld.ptr());

    glBegin(GL_POLYGON);
    
    glColor3f(colors[0], colors[1], colors[2]);
    glVertex3f(vertices[0], vertices[1], vertices[2]);
    
    glColor3f(colors[3], colors[4], colors[5]);
    glVertex3f(vertices[3], vertices[4], vertices[5]);
    
    glColor3f(colors[6], colors[7], colors[8]);
    glVertex3f(vertices[6], vertices[7], vertices[8]);
    
    glColor3f(colors[9], colors[10], colors[11]);
    glVertex3f(vertices[9], vertices[10], vertices[11]);
    
    glColor3f(colors[12], colors[13], colors[14]);
    glVertex3f(vertices[12], vertices[13], vertices[14]);
    
    glColor3f(colors[15], colors[16], colors[17]);
    glVertex3f(vertices[15], vertices[16], vertices[17]);
    
    glColor3f(colors[18], colors[19], colors[20]);
    glVertex3f(vertices[18], vertices[19], vertices[20]);
    
    glColor3f(colors[21], colors[22], colors[23]);
    glVertex3f(vertices[21], vertices[22], vertices[23]);
    
    glColor3f(colors[24], colors[25], colors[26]);
    glVertex3f(vertices[24], vertices[25], vertices[26]);
    
    glColor3f(colors[27], colors[28], colors[29]);
    glVertex3f(vertices[27], vertices[28], vertices[29]);
    
    glColor3f(colors[30], colors[31], colors[32]);
    glVertex3f(vertices[30], vertices[31], vertices[32]);
    
    glColor3f(colors[33], colors[34], colors[35]);
    glVertex3f(vertices[33], vertices[34], vertices[35]);
    
    glColor3f(colors[36], colors[37], colors[38]);
    glVertex3f(vertices[36], vertices[37], vertices[38]);
    
    glColor3f(colors[3], colors[4], colors[5]);
    glVertex3f(vertices[3], vertices[4], vertices[5]);
    
    glColor3f(colors[6], colors[7], colors[8]);
    glVertex3f(vertices[6], vertices[7], vertices[8]);
    
    glColor3f(colors[9], colors[10], colors[11]);
    glVertex3f(vertices[9], vertices[10], vertices[11]);
    
    glColor3f(colors[0], colors[1], colors[2]);
    glVertex3f(vertices[0], vertices[1], vertices[2]);
    
    glColor3f(colors[3], colors[4], colors[5]);
    glVertex3f(vertices[3], vertices[4], vertices[5]);
    
    glColor3f(colors[6], colors[7], colors[8]);
    glVertex3f(vertices[6], vertices[7], vertices[8]);
    
    glColor3f(colors[9], colors[10], colors[11]);
    glVertex3f(vertices[9], vertices[10], vertices[11]);
    glColor3f(colors[0], colors[1], colors[2]);
    glVertex3f(vertices[0], vertices[1], vertices[2]);
    
    glColor3f(colors[3], colors[4], colors[5]);
    glVertex3f(vertices[3], vertices[4], vertices[5]);
    
    glColor3f(colors[6], colors[7], colors[8]);
    glVertex3f(vertices[6], vertices[7], vertices[8]);
    
    glColor3f(colors[9], colors[10], colors[11]);
    glVertex3f(vertices[9], vertices[10], vertices[11]);

    glEnd();

    

    
    
    
    glPopMatrix();
    
}