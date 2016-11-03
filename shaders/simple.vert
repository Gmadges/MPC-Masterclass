attribute vec4 a_position;
attribute vec3 a_normal;

uniform mat4 proj_matrix;
uniform mat4 view_matrix;
uniform mat4 model_matrix;

uniform mat3 normal_matrix;

uniform vec4 objectColor;
uniform vec3 lightPos;

varying vec3 vertex;
varying vec3 vertexNormal;
varying vec4 col;

void main(void)
{
    mat4 MVP = proj_matrix * view_matrix * model_matrix;
    gl_Position = MVP * a_position;
    vertex = a_position;
    vertexNormal = normal_matrix * a_normal;
    col = vec4(objectColor.x, objectColor.y, objectColor.z, 1);
}
