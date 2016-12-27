#version 330
in vec4 col;

in highp vec3 vertex;
in highp vec3 vertexNormal;
uniform highp vec3 lightPos;

void main()
{
    highp vec3 L = normalize(lightPos - vertex);

    highp float NL = max(dot(normalize(vertexNormal), L), 0.0);

    highp vec4 color = clamp(col * 0.2 + col * 0.8 * NL, 0.0, 1.0);

    gl_FragColor = color;
}
