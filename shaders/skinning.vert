attribute vec4 a_position;
attribute vec3 a_normal;

attribute ivec4 a_boneIDs;
attribute vec4 a_weights;

const int MAX_BONES = 1000;
uniform mat4 bones[MAX_BONES];

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
    // bone transform matrices
    mat4 boneTransform = bones[a_boneIDs[0]] * a_weights[0];
    boneTransform += bones[a_boneIDs[1]] * a_weights[1];
    boneTransform += bones[a_boneIDs[2]] * a_weights[2];
    boneTransform += bones[a_boneIDs[3]] * a_weights[3];

    // vertex position
    mat4 MVP = proj_matrix * view_matrix * model_matrix;
    vec4 pos = boneTransform * a_position;
    gl_Position = MVP * pos;

    // vert pos for frag
    vertex = pos;

    // normal
    vec4 norm = boneTransform * a_normal;
    vertexNormal = normal_matrix * norm;

    // color
    col = vec4(objectColor.x, objectColor.y, objectColor.z, 1);
}
