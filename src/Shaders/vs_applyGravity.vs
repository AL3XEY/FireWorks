#version 310
 
in vec3 speed;
 
void main()
{  
    vec4 pos = gl_Vertex;
    pos.x = pos.x * 0.5;
    pos.y = pos.y * 0.5;
    
    gl_position = gl_ModelViewProjectionMatrix * pos;
}