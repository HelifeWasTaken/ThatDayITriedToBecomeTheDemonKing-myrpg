// Mode 7 Shader
uniform sampler2D Buf1;
uniform float Sin1, Cos1, Sin2, Cos2;

vec2 RepeatXY(in vec2 XY){
        return vec2(mod(XY.x, 1.0), mod(XY.y, 1.0));
}

void main(void)
{
        vec2 uv = gl_TexCoord[0].st;

        float Scale = 128.0;
        float Distance = -2.0;
        float LookY = -0.3;

        vec2 warped;

        // perform Mode 7 transformation on uvs
        warped = vec2( (uv.x-0.5)/(uv.y+LookY-0.5), 1.0/(uv.y+LookY-0.5) - Distance)/Scale;

        // rotate the new uvs
        warped = vec2(Sin1*warped.x, Sin2*warped.x) + vec2(Cos1*warped.y, Cos2*warped.y);

        // set the uvs to repeat in space
        warped = RepeatXY(warped);

        // horizon check
        if(uv.y < 0.5 - LookY)
                // sample the input texture with new uvs
                gl_FragColor = texture2D(Buf1, warped);
        else
                // sky
                gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
}