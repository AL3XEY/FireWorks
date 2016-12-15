#version 410
 
in vec3 position;
 
out VertexData {
    vec3 position;
} VertexOut;
 
void main()
{
    VertexOut.texCoord = texCoord;
    VertexOut.normal = normalize(normalMatrix * normal);    
    gl_Position = projModelViewMatrix * vec4(position, 1.0);
}