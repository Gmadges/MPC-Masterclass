#version 330
in vec4 a_position;
in vec3 a_normal;

uniform mat4 proj_matrix;
uniform mat4 view_matrix;
uniform mat4 model_matrix;

uniform mat3 normal_matrix;

uniform vec4 objectColor;
uniform vec3 lightPos;

out vec3 vertex;
out vec3 vertexNormal;
out vec4 col;

void main(void)
{
    mat4 MVP = proj_matrix * view_matrix * model_matrix;
    gl_Position = MVP * a_position;
    vertex = a_position.xyz;
    vertexNormal = normal_matrix * a_normal;
    col = vec4(objectColor.x, objectColor.y, objectColor.z, 1);
}
