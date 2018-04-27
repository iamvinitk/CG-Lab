void triangle(float *a, float *b, float *c){
	glBegin(GL_TRIANGLE);
	glVertex2v(v[a]);
	glVertex2v(v[b]);
	glVertex2v(v[c]);
	glEnd();
}


void dt(float *a, float *b, float *c, int m){
	float v1[3],v2[3],v3[3];
	if(m>0){
		for(int i=0; i<3;i++){
		v1[i] = (a[i]+b[i])/2;
		v2[i] = (b[i]+c[i])/2;
		v3[i] = (c[i]+a[i])/2;
}
